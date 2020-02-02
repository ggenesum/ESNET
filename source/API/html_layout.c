#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void strstrip(char *str, char *stripseq) //and display
{
  char *match;
  while ((match == strstr(str, stripseq)))
  {
    *match = '\0';
    strcat(str,match+strlen(stripseq));
  }
  printf("%s",str);

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
  //strip
      strstrip(str,"\n");
      printf("%s", str);
  fclose(fp);
}
