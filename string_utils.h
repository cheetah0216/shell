/***************************************************************************
 *  ISA 563 - Spring 2012
 *
 *  Some string functions for c strings
 *
 *  Chris Brahms
 *
 **************************************************************************/



#ifndef CBRAHMS_LIB_STRING
#define CBRAHMS_LIB_STRING

#include <stdbool.h>


char* str_create(int length);

//
// copies string_from to str_to, setting the last byte to null
//
// str_to should be limit + 1 big
//
void str_copy(char* str_to, char* str_from, int limit);

char* str_substring(const char* str, int offset, int length);

//
// concats str1 with str2
//
char* str_concat(const char* str1, const char* str2);
//
// lowercases a string
//
char* str_tolower(char* word);

//
// copies a character array
//
char** str_copy_strings(char** strings, int strings_size);

//
// frees a str array
//
void str_cleanup_strings(char** strings, int strings_size);
// finds a string in an array
//
bool str_is_in_array(char * string, char** strings, const int strings_size);
//
// merges two string arrays
// 
char** str_merge_strings(char** strings1, int strings1_size, char** strings2, int strings2_size);

//
// returns true if the character is a space
//
bool str_is_space(char c);

//
// returns a character array that has no outer whitespace, given an input string
// 
char* str_trim(const char* string, int limit);


//
// Returns true if the string has either letters or the '-' character
//
bool str_has_char(const char* string);

//
// Returns true if the char is a letter or a '-'
//
bool str_is_char(char c);

#endif

