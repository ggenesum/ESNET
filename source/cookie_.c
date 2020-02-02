#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main()
{
  int argc = 6;
  char test[] = "|| ceci est un || du bon fonctionnemnt de la fonction || : || || ||";
  char **str_arr = (char**)malloc(argc*sizeof(char*));
  str_arr[0] = "begin:";
  str_arr[1] = "test";
  str_arr[2] = "argparse";
  str_arr[3] = "c'est";
  str_arr[4] = "vraiment";
  str_arr[5] = "nickel";

  replacefirst(test,str_arr,argc);
  if (str_arr == NULL)
  {
    printf("adfaeff");
  }
  free(str_arr);


}
