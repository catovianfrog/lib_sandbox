TOKENIZE
=========
String parsing for words or quoted substrings
---------------------------------------------

*v3.2*

22.06.2014    

This function splits a string into words or substrings.
This is a small exercise to learn C. The same function in Perl would probably
take only a couple of lines of code. 



_Tokenize_ returns an array of strings pointing to the words in the input buffer. The number of strings
is returned as an \*int parameter passed by reference.

Note that the source string __buffer__ (_\*buf_) __is modified:__ a null character is inserted at the end of each word or quoted string.

###Syntax
char\*\*	__tokenize__(_char_ \*buffer, _int_ \*word_count);

###To Do
* nil

###Log History

* v3  Prints error message on stderr and returns non-zero when syntax error (uneven number of quotes, or quotes within words)
* v2  Memory allocation cleaned up. Doesn't allocate memory to returned strings, but return pointers to 
strings in input buffer. Input puffer is modified with end-of-strins characters.
* v1  works, but memory almlocation is a mess

