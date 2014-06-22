TOKENIZE
=========
string parsing for words or quoted substrings
---------------------------------------------

This function splits a string into words or substrings.

__TODO__	add error processing when a quote occurs in a word, or 
		the number of quotes is uneven
		Also add treatment for escaped space or quote characters

Tokenize returns an array of \*strings pointing to the words in input buffer
The __buffer is modified:__ a null character is inserted at the end of each word or quoted string.


*v2.00*
22.06.2014


###Log History
2.1.2 
2.1.1	
