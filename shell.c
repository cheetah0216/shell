/***************************************************************************
 *  ISA 563 - Spring 2012
 *  C Shell
 *
 *  Chris Brahms
 *
 **************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include "string_utils.h"
/* Some constants */
const char* VERSION     = "speller-1.33.7";
const char* USAGE = "\
  speller [-h | --help]                   : output this usage message. \n\
  speller [-v | --version]                : prints out the version.\n\
  speller [-n | --count] count            : sets the max amount of matched words to count\n\
  speller [-d | --dictionary] file        : sets the dictionary file to use\n";

//
// returns false if the program should exit, else true
//
bool get_arguments(int argc, char *argv[] );

//
// Outputs the help message
//
void output_help();

//
// Outputs the version
//
void output_version();


int main (int argc, char *argv[] )
{
  if(!get_arguments(argc, argv)) return 0;

  //
  // done
  // 
  printf("\n<done>\n");
  return 0;
}


bool get_arguments(int argc, char **argv)
{
  bool help_flag = 0;
  bool version_flag = 0;
  int c;
  while(1)
  {
    static struct option long_options[] =
      {
       {"version",    no_argument,       0, 'v'},
       {"help",       no_argument,       0, 'h'},
       {0,0,0,0}
      };

     int option_index = 0;
     
     c = getopt_long (argc, argv, "vhd:n:",
                      long_options, &option_index);

     /* Detect the end of the options. */
     if (c == -1)
       break;

     switch (c)
     {
       case 'h':
         help_flag = true;
         break;
       case 'v':
         version_flag = true;
         break;
       case '?': 
        return false;
     }  //end switch
  } // end while

  if(help_flag)
  {
    output_help();
    return false;
  }
  if(version_flag)
  {
    output_version();
    return false;
  }
  
  return true;
}

void output_version()
{
  printf("%s\n", VERSION);
}

void output_help()
{
  printf("%s\n", USAGE);
}
