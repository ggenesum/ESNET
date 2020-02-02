#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"

void main()
{
  printf("Set-Cookie: cookie=miam\n");
  printf("Content-Type: text/html;\n\n");

  char *len_ = getenv("CONTENT_LENGTH");
  long len = strtol(len_, NULL, 10);
  char *post = malloc(len + 1);

  if (!post)
  {
    printf("couldnt allocate memory");
    return;
 }

fgets(post, len + 1, stdin);
printf("%s", post);
free(post);
}
