/**********************************************************************
* TOKENIZE
*
* test the tokenize function in libstring library
*
* String manipulation library
* v1	June 2014
* (C) Bruno Charrière, see http://www.gnu.org/licenses/gpl.html
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libstring.h"


int main(int argc, char **argv) {
  char	*buffer;
  int	count,i;
  char **words=NULL;
  char	*s=" word1 word2 \"word 3o\" 'word 4' word5" ;
  printf("default string: %s\nInput string ?",s);
  buffer=malloc(255);
  if(fgets(buffer,250,stdin) == NULL || strlen(buffer)==1) strcpy(buffer,s);
  buffer[strlen(buffer)]='\0';
  words=tokenize(buffer,&count);
  for(i=0; i<count; i++) printf("\t\t%s\n",words[i]);
  free(buffer);
  free(words);
  if (words != NULL) return 0; else return 1;
}
