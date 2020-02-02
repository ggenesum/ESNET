#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void argparse(char *str, char **var, int argc) //string username=foo&pass=bar into array ["foo","bar"]
{
  char *token = strtok(str, "=");
  for (int i = 0; i < argc; i++)
	{
    token = strtok(NULL, "&");
    if (token == NULL)
    {
      break;
    }
    var[i] = token;
    token = strtok(NULL, "=");
	}
}

int main()
{
  int argc = 3;
  char **var = (char**)malloc(argc*sizeof(char*));
  char str[] = "username=jean&pass=louis";
  argparse(str,var,argc);
  printf("%s\n",var[0]);
  printf("%s\n",var[1]);
  free(var);
  return 0;
}
