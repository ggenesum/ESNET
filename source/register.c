#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/argparse.h"
#include "API/cookies.h"

int main(void)
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

  int argc = 4; // number of arguments we get
  int varc = 2; // number of "||" markers in zhtml page

  fgets(post, len + 1, stdin);

  char *content = fgets(post, len + 1, stdin);

  char **args = (char**)malloc(argc*sizeof(char*)); //post request parsed values
  char **vars = (char**)malloc(varc*sizeof(char*)); //dynamicly generated content (vars that are embeeded in html page)


  if (argparse(post,args,argc) != 0)
  {
   printf("Please enter user, email and password");
   free(len_);
   free(content);
   free(post);
   free(vars);
   free(args);
   return 1;
  }

  if (strcmp(args[2], args[3]) == 0) //compare 2 entered passwords
  {
     struct login_cookie lc; //craft cookie
     lc.auth_token = "test_uid";

     if (add_login_cookies(lc)==0) //if success
     {
       printf("Content-Type: text/html;\n\n");
       load_ztemplate("../templates/register.zhtml", vars);
       free(len_);
       free(content);
       free(post);
       free(vars);
       free(args);
       return 0;
     }
  }
  printf("Content-Type: text/html;\n\n");
  printf("<p> The passwords don't match </p>");

	return 1;
}
