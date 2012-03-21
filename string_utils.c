#include "string_utils.h"

#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
char* str_create(int length)
{
  assert(length >= 0);
    
  char* str = (char*) malloc((length + 1) * sizeof(char));
  
  if(str)
    str[length] = '\0';
    
  return str; 
}

//
// copies string_from to str_to, setting the last byte to null
//
// str_to should be limit + 1 big
//
void str_copy(char* str_to, char* str_from, int limit)
{
    memcpy(str_to, str_from, limit);
    *(str_to + limit) = '\0';
}

char* str_substring(const char* str, int offset, int length)
{
  char* str_new;
  int   str_len=strlen(str);
  
  bool cond = (length  >  str_len         ||
              (offset + length) > str_len||
              str_len < 1                 ||
              length < 0);
  if(cond)
      return NULL;

  str_new = strndup((str + offset), length);
  return str_new;
}

//
// concats str1 with str2
//
char* str_concat(const char* str1, const char* str2)
{
  if(!str1)
    str1 = str_create(0);
  if(!str2)
    str2 = str_create(0);
    
  assert(str1 && str2);

  int len_str1 = strlen(str1);
  int len_str2 = strlen(str2);

  char* str_new = malloc(len_str1 + len_str2 + 1);
  assert(str_new);
  
  strcpy(str_new, str1);
  strcat(str_new, str2);
  
  assert((str_new[len_str1 + len_str2] == '\0'));
  
  return str_new;
}

//
// lowercases a string
//
char* str_tolower(char* word)
{
  char* ret = strdup(word);
  char* c;
  
  for(c = ret; *c != '\0'; c++)
  {
    *c = tolower(*c);
  }

  return ret;
}

//
// copies a character array
//
char** str_copy_strings(char** strings, int strings_size)
{
  char** copy = (char**) malloc(strings_size * sizeof(char*));

  if(!copy) 
    return NULL;

  int i;
  for(i = 0; i < strings_size; i++)
    copy[i] = strdup(strings[i]);

  return copy;
}

//
// frees a str array
//
void str_cleanup_strings(char** strings, int strings_size)
{
  int i;
  for(i = 0; i < strings_size; i++)
  {
    free(strings[i]);
  }
  
}
//
// finds a string in an array
//
bool str_is_in_array(char * string, char** strings, const int strings_size)
{
  if(strings == NULL || strings_size <= 0)
    return false;
    
  int i;

  for(i = 0; i < strings_size; i++)
    if(strcmp(strings[i], string) == 0)
      return true;

  return false;
}
//
// merges two string arrays
// 
char** str_merge_strings(char** strings1, int strings1_size, char** strings2, int strings2_size)
{
  if(strings1_size < 0 || strings2_size < 0) 
    return NULL;
    
  char** merge = (char**) malloc((strings1_size + strings2_size) * sizeof(char*));

  
  if(!merge)
    return NULL;

  int i, j = 0;
  
  for(i = 0; i < strings1_size; i++)
    merge[j++] = strdup(strings1[i]);
    
  for(i = 0; i < strings2_size; i++)
    merge[j++] = strdup(strings2[i]);

  return merge;
}

bool str_is_space(char c)
{
  return isspace(c);
}

bool str_is_char(char c)
{
  return('A' <= c && c <= 'z' &&
         c != '`' &&
         c != '[' &&
         c != ']' &&
         c != '\'' &&
         c != '^' &&
         c != '_' &&
         c != '\\');
}

bool str_has_char(const char* string)
{
  int i, len = strlen(string);
  for(i = 0; i < len; i++)
    if(str_is_char(string[i])  == true)
      return true;
      
  return false;
}

char* str_trim(const char* string, int limit)
{
  if(limit <= 0)
    return 0;

  const int len = strnlen(string, limit) ;
  const char* beg = string;
  const char* end = string + len - 1;
  
  int str_size = 0;

  while(beg < string + len - 1 && str_is_space(*beg))
    beg++;
  while(end > string && str_is_space(*end)) 
    end--;

  str_size = (end - beg) < len - 1 ? (end - beg) + 1: len;


  if(str_size > 0)  
  {
    
    char* str_new = (char*) malloc(str_size * sizeof(char));

    assert(str_new);
    
    memcpy(str_new, beg, str_size);
    str_new[str_size] = '\0';

    return str_new;
  }
  else
    return str_create(0);
}

