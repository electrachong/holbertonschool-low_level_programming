#include "my_functions.h"

void print_base16(void)
{
  /* declare variables */
  char c;

    /* print numbers of base 16
    initialize, check and update
    */
  for (c = 48; c <= 70; c++)
      {
	if (c > 57 && c < 65)
	  	    continue;
	  print_char(c);
      }
}
