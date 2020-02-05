#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/argparse.h"
#include "API/cookies.h"
#include "API/database.h"
#include "API/error.h"

#define DEBUG 1 //display error messages

int main()
{
    char *len_ = getenv("CONTENT_LENGTH");
    if (len_ == NULL)
    {
      //free pointers, handle correctly
      errpage("login/err1 : NULL ptr content_length",DEBUG);
      return 1;
    }
    long len = strtol(len_, NULL, 10);

    if (len == 0)
    {
      errpage("login/err2 : post len is 0",DEBUG);
      return 1;
    }

    char *post = malloc(len + 1);

    if (!post)
    {
      errpage("login/err3 : post is NULL",DEBUG);
      return 1;
   }

   int argc = 2;
   int varc = 1; //number of "||" markers in zhtml page

   fgets(post, len + 1, stdin);

   char **args = (char**)malloc(argc*sizeof(char*)); //post request parsed values
   char **vars = (char**)malloc(varc*sizeof(char*)); //dynamicly generated content (vars that are embeeded in html page)

   if (argparse(post,args,argc) != 0)
   {
      errpage("login/err4 : argparse returns error code",DEBUG);
     return 1;
   }
   vars[0] = args[0]; //username
   struct login_cookie lc; //craft cookie
   lc.auth_token = NULL;
   sqlite3* db = init_sqldb();

   if (Auhtenticate(args[0],args[1],lc,db) != -1)
   {
     lc.auth_token = "test_token";
     if (add_login_cookies(lc)==0) //add cookie, and if success
     {
       printf("Content-Type: text/html;\n\n");
       load_ztemplate("../templates/login.zhtml", vars);
       free(vars);
       free(args);
       return 0;
     }
   }
   printf("Content-Type: text/html;\n\n");
   printf("<p> Cannot log in </p>");


  free(vars);
  free(args);
  return 1;
}
