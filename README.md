TOKENIZE
=========
string parsing for words or quoted substrings
---------------------------------------------

*v3.0*
 22.06.2014    

This function splits a string into words or substrings.

_Tokenize_ returns an array of \*strings pointing to the words in input buffer, and the number of strings as a \*int.
Note that the __buffer__ (_\*buf_) __is modified:__ a null character is inserted at the end of each word or quoted string.

###Syntax
char**	__tokenize__(_char_ *buf, _int_ *n);   


__TODO__	Change into a library function   



###Log History
v3  Prints error message on stderr and returns non-zero when syntax error (uneven number of quotes, or quotes within words)
v2  Memory allocation cleaned up. Doesn't allocate memory to returned strings, but return pointers to 
strings in input buffer. Input puffer is modified with end-of-strins characters.
v1  works, but memory almlocation is a mess


