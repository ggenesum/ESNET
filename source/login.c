#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/argparse.h"
#include "API/cookies.h"
#include "API/database.h"

int main()
{
    char *len_ = getenv("CONTENT_LENGTH");
    if (len_ == NULL)
    {
      //free pointers, handle correctly
      printf("Location: /cgi/error.cgi\n\n");
      return 1;
    }
    long len = strtol(len_, NULL, 10);

    if (len == 0)
    {
      printf("Location: /cgi/error.cgi\n\n");
      return 1;
    }

    char *post = malloc(len + 1);

    if (!post)
    {
      printf("Location: /cgi/error.cgi\n\n");
      return 1;
   }

   int argc = 2;
   int varc = 1; //number of "||" markers in zhtml page

   fgets(post, len + 1, stdin);

   char **args = (char**)malloc(argc*sizeof(char*)); //post request parsed values
   char **vars = (char**)malloc(varc*sizeof(char*)); //dynamicly generated content (vars that are embeeded in html page)

   if (argparse(post,args,argc) != 0)
   {
     printf("Location: /cgi/error.cgi\n\n");
     return 1;
   }
   vars[0] = args[0]; //username
   struct login_cookie lc; //craft cookie
   lc.auth_token = NULL;
   sqlite3* db = init_sqldb();

   if (Auhtenticate(args[0], vars[0],lc,db) != -1) //raw password value is test
   {
     lc.auth_token = "test_uid";
     if (add_login_cookies(lc)==0) //add, and if success
     {
       printf("Content-Type: text/html;\n\n");
       load_ztemplate("../templates/login.zhtml", vars);
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
