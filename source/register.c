#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/argparse.h"
#include "API/cookies.h"
#include "API/database.h"
#include "API/error.h"

#define DEBUG 1 //display error messages

int main(void)
{
	char *len_ = getenv("CONTENT_LENGTH");
  if (len_ == NULL)
  {
    //free pointers, handle correctly
    errpage("regiser/err1 : NULL ptr content_length",DEBUG);
    return 1;
  }

  long len = strtol(len_, NULL, 10);
  if (len == 0)
  {
    errpage("register/err2 : post len is 0",DEBUG);
    return 1;
  }

  char *post = malloc(len + 1);
  if (!post)
  {
    errpage("register/err3 : post is NULL",DEBUG);
    return 1;
  }

  int argc = 4; // number of arguments we get
  int varc = 2; // number of "||" markers in zhtml page

  char *content = fgets(post, len + 1, stdin);

  char **args = (char**)malloc(argc*sizeof(char*)); //post request parsed values
  char **vars = (char**)malloc(varc*sizeof(char*)); //dynamicly generated content (vars that are embeeded in html page)


  if (argparse(post,args,argc) != 0)
  {
   errpage("register/err4 : argparse returns error code",DEBUG);
   free(len_);
   free(content);
   free(post);
   free(vars);
   free(args);
   return 1;
  }

  if (strcmp(args[2], args[3]) == 0) //compare 2 entered passwords
  {
    // struct login_cookie lc; //craft cookie
    // lc.auth_token = NULL;
     sqlite3* db = init_sqldb();
     printf(__Username_exists(args[0],db));
     if (Register(args[0], args[1], args[2], db) != -1)
     {
       printf("Content-Type: text/html;\n\n");
       load_ztemplate("../templates/register.zhtml", vars);
       free(len_);
       free(content);
       free(post);
       free(vars);
       free(args);
       close_sqldb(db);
       return 0;
     }
     close_sqldb(db);
  }
  else
  {
    printf("Content-Type: text/html;\n\n");
    printf("<p> The passwords don't match </p>");
  }

	return 1;
}
