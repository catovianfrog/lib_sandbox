/**********************************************************************
 *
 *	TOKENIZE (string parsing for words or quoted substrings)
 *
 *      this function splits a string into words or substrings
 *      TODO	add error processing when a quote occurs in a word, or 
 *		the number of quotes is uneven
 *		Also add treatment for escaped space or quote characters
 *
 *	v2.1.2
 *	22.06.2014
 *
 **********************************************************************/
#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>


char** tokenize(char *buf,int *n);

int main(int argc, char **argv) {
  //char*	s="  word1 word2 \"word 3\"  'word 4' word5";
  char	*s="  word1 word2 \"word 3\"  'wor\"d 4' wo\"rd5 word6";
  char	*buffer;
  int	count,i;
  char  **words=NULL;


  buffer=malloc(strlen(s)+1);
  strcpy(buffer,s);
  words=tokenize(buffer,&count);
  printf("%d parameters:\n",count);
  for(i=0; i<count; i++) printf("\t\t%s\n",words[i]);

  free(buffer);
  free(words);
  return 0;
}

char** get_token(int word_beg, int word_end, int word_count, char *buffer, char **words) {
    word_count++;
    buffer[word_end+1]='\0'; // terminate string
    words=realloc(words,(word_count)*sizeof(words)); //extend size of word array
    words[word_count-1]=&buffer[word_beg];	// token points to strt of word
    return words;
}

char** tokenize(char *buf,int *n) 
{
    enum states {between_words, in_word, in_quote, in_dquote} state;
    int	    ch,pos,word_beg,word_count;
    char    **tokens;

    tokens=NULL;
    state=between_words;
    word_count=0;
    for(pos=0; buf[pos]!='\0'; pos++) {	//parse the buffer string
	ch=buf[pos];
	    switch (state) {
	    case between_words:
		if(isspace(ch)) {
		    // still not in a word, ignore this char
		    continue;
		}
		// ch is not a space. Enter either a quoted string or a word
                if(ch == '\'') {
		    state=in_quote;
		    word_beg=pos+1; //word starts after the quote
		    continue;
		}
                if(ch == '"') {
		    state=in_dquote;
		    word_beg=pos+1; //word starts after the quote
		    continue;
		} // not a space nor a quote: in a word
		state=in_word;
		word_beg=pos;   // word starts here
		continue;
	    case in_quote:
		// keep going until next quote
		if(ch == '\'') {
		    tokens=get_token(word_beg, pos-1, word_count, buf, tokens);
		    word_count++;
		    state=between_words;
		}
		continue; //either still in string or between words
	    case in_dquote:	// keep going until next quote
		if(ch == '"') {
		    tokens=get_token(word_beg, pos-1, word_count, buf, tokens);
		    word_count++;
		    state=between_words;
		}
		continue; //either still in string or between words
	    case in_word:
		//keep going until next space
		if(isspace(ch)) {
		    tokens=get_token(word_beg, pos-1, word_count, buf, tokens);
		    word_count++;
		    state=between_words;
		}
		// TODO an error or warning should be generated here if ch is in_quote
		continue;
	    }
    }
    // end of buffer is reached ('\0');
    if(state == in_word) {
	tokens=get_token(word_beg, pos-1, word_count, buf, tokens);
	word_count++;
    }
   
 // TODO an error or warning should be generated here if state is in_quote
    memcpy(n,&word_count,sizeof(word_count));
    return tokens;
}

