#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"

int main()
{
  printf("Set-Cookie: cookie=miam\n");
  printf("Content-Type: text/html;\n\n");

  char *len_ = getenv("CONTENT_LENGTH");
  long len = strtol(len_, NULL, 10);
  char *post = malloc(len + 1);

  if (!post)
  {
    printf("couldnt allocate memory");
    return 1;
 }

 fgets(post, len + 1, stdin);


 printf("%s", post);

 free(post);





int argc = 2;
char **var = (char**)malloc(argc*sizeof(char*));
var[0] = "jean";
var[1] = "louis";

load_ztemplate("templates/login.zhtml", var);
free(var);
return 0;
}
