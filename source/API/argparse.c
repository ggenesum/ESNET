#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int argparse(char *str, char **var, int argc) //string username=foo&pass=bar into array ["foo","bar"]
{
  char *token = strtok(str, "=");
  if (token == NULL)
  {
    return 1;
  }
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
  return 0;
}
