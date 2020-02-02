#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace_markers(char *str, char **var, int argc) //parse each || with corresponding var
{

  int i = 0;
  if (str[0] == '|' && str[1] == '|')
  {
    printf("%s",var[i]);
    i++;
  }

  char *token = strtok(str, "||");
  while(1)
	{
		printf("%s",token);
		token = strtok(NULL, "||");
    if (token == NULL)
    {
      break;
    }
    printf("%s",var[i]);

    i++;
	}
}


void load_template(char* path)
{
  FILE *fp;
  int buffsz = 4096;
  char *str = malloc(buffsz);
  if (str == NULL)
  {
    printf("failure in load template: Could not allocate memory");
    return;
  }

  fp = fopen(path, "r");
  if (fp == NULL){
      printf("Could not load template %s", path);
      return;
  }
  while (fgets(str, buffsz, fp) != NULL)
      printf("%s", str);
  fclose(fp);
}

void load_ztemplate(char* path, char **var)
{
  int argc = sizeof(var)/sizeof(var[0]);
  FILE *fp;
  int buffsz = 4096;
  char *str = malloc(buffsz);
  if (str == NULL)
  {
    printf("failure in load template: Could not allocate memory");
    return;
  }

  fp = fopen(path, "r");
  if (fp == NULL){
      printf("Could not load template %s", path);
      return;
  }
  while (fgets(str, buffsz, fp) != NULL)
    replace_markers(str,var,argc);
  fclose(fp);
}
