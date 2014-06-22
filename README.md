TOKENIZE
=========
String parsing for words or quoted substrings
---------------------------------------------

This function splits a string into words or substrings.

_Tokenize_ returns an array of \*strings pointing to the words in input buffer, and the number of strings as a \*int.
Note that the __buffer__ (_\*buf_) __is modified:__ a null character is inserted at the end of each word or quoted string.

###Syntax
char**	__tokenize__(_char_ *buf, _int_ *n);



__TODO:__	add error processing when a quote occurs in a word, or when
		the number of quotes is uneven. 
		Also add treatment for escaped space or quote characters.


*v2.00*
22.06.2014


###Log History
* 2.1.2 
* 2.1.1	
