#include "my_functions.h"

void print_alphabet(void)
{
  /* declare variable */  
  char c;

  /* print the letters of the alphabet in lowercase */
  /* initialize, check and update */
  for(c = 97; c <= 122; c++)
   {
    print_char(c);
   }

}
