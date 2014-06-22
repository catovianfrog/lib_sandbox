 	TOKENIZE (string parsing for words or quoted substrings)
	========================================================

      This function splits a string into words or substrings.

      __TODO__	add error processing when a quote occurs in a word, or 
		the number of quotes is uneven
		Also add treatment for escaped space or quote characters

      __TODO__	Main issue: very inelegant. Memory is assigned as 
		needed,	and the structures are complex.	Total string 
		memory needed is lower that the input string size, so
		memory allocation should be simplified 

	*v1.00*
	22.06.2014



