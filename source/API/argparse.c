#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int argparse(char *str, char **var, int argc) //string username=foo&pass=bar into array ["foo","bar"]
//if they are more values in post than argc, return only the argc first values
//if less, return error code
{
  int c = 0;
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
    if (strlen(token) == 0)
    {
      return 1;
    }
    var[i] = token;
    c++;
    token = strtok(NULL, "=");
	}

  if (c < argc)
  {
    return 1;
  }
  return 0;
}
