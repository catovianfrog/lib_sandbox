/**********************************************************************
 *
 *	TOKENIZE (string parsing for words or quoted substrings)
 *
 *      This function splits a string into words or substrings
 *
 *	v3.0
 *	22.06.2014
 *
 **********************************************************************/
#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>


char** tokenize(char *buf,int *word_count);

int main(int argc, char **argv) {
  char	*buffer;
  int	count,i;
  char  **words=NULL;

  // default string:
  char	*s="  word1 word2 \"word 3  'word 4' word5 ";
  buffer=malloc(255);
  if(fgets(buffer,250,stdin) == NULL || strlen(buffer)==1) strcpy(buffer,s);
  buffer[strlen(buffer)]='\0';
  words=tokenize(buffer,&count);
  for(i=0; i<count; i++) printf("\t\t%s\n",words[i]);

  free(buffer);
  free(words);
  if (words != NULL) return 0; else return 1;
}

char** get_token(int word_beg, int word_end, int word_count, char *buffer, char **words) {
    word_count++;
    buffer[word_end+1]='\0'; // terminate string
    words=realloc(words,(word_count)*sizeof(words)); //extend size of word array
    words[word_count-1]=&buffer[word_beg];	// token points to strt of word
    return words;
}

char** tokenize(char *buf,int *word_count) 
{
    enum states {between_words, in_word, in_quote, in_dquote} state;
    int	    ch,pos,word_beg;
    char    **tokens;

    tokens=NULL;
    state=between_words;
    *word_count=0;
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
		    tokens=get_token(word_beg, pos-1, *word_count, buf, tokens);
		    *word_count++;
		    state=between_words;
		}
		continue; //either still in string or between words
	    case in_dquote:	// keep going until next quote
		if(ch == '"') {
		    tokens=get_token(word_beg, pos-1, *word_count, buf, tokens);
		    *word_count++;
		    state=between_words;
		}
		continue; //either still in string or between words
	    case in_word:
		//keep going until next space
		if(isspace(ch)) {
		    tokens=get_token(word_beg, pos-1, *word_count, buf, tokens);
		    *word_count++;
		    state=between_words;
		}
		if(ch=='\'' || ch=='\"') {
		    fprintf(stderr, "******** ERROR: String badly constructed. Quote within a word.\n");
		    *word_count=0;
		    tokens=NULL;
		    goto error;
		}
		continue;
	    }
    }
    // end of buffer is reached ('\0');
    if(state == in_word) {
	tokens=get_token(word_beg, pos-1, *word_count, buf, tokens);
	*word_count++;
    }
   
    if(state == in_quote || state== in_dquote) {
	fprintf(stderr, "******** ERROR: String badly constructed. Uneven number of quotes.\n");
	*word_count=0;
	tokens=NULL;
    }

error:
    //memcpy(n,&word_count,sizeof(word_count));
    return tokens;
}

