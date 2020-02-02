#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/argparse.h"
#include "API/cookies.h"

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
   int varc = 1; //number of "||" markers in zhtml page

   fgets(post, len + 1, stdin);
   
   char **args = (char**)malloc(argc*sizeof(char*)); //post request parsed values
   char **vars = (char**)malloc(varc*sizeof(char*)); //dynamicly generated content (vars that are embeeded in html page)

   argparse(post,args,argc);
   vars[0] = args[1]; //username

   if (strcmp(args[1],"test") == 0) //raw password value is test
   {
     if (add_login_cookie("test_uid")==0)
     {
       printf("Content-Type: text/html;\n\n");
       load_ztemplate("templates/login.zhtml", vars);
       free(vars);
       free(args);
       return 0;
     }
   }
   printf("Content-Type: text/html;\n\n");
   printf("<p> invalid password </p>");


  free(vars);
  free(args);
  return 1;
}
