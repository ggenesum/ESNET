#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/argparse.h"

int main()
{
    char *len_ = getenv("CONTENT_LENGTH");
    long len = strtol(len_, NULL, 10);
    char *post = malloc(len + 1);

    if (!post)
    {
      printf("couldnt allocate memory");
      return 1;
   }

   int argc = 2;
   fgets(post, len + 1, stdin);
   char **var = (char**)malloc(argc*sizeof(char*));
   argparse(post,var,argc);

 printf("Set-Cookie: cookie=miam\n");
 printf("Content-Type: text/html;\n\n");

  load_ztemplate("templates/login.zhtml", var);
  free(var);
  return 0;
}
