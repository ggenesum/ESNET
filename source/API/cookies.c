#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct login_cookie
{
    char *auth_token;
};

int add_login_cookie(char *auth_token)
  {
    struct login_cookie lc;
    if (auth_token == NULL)
    {
      return 1; //no cookie :(
    }
    lc.auth_token = auth_token;
    printf("Set-Cookie: auth_token=%s\n",lc.auth_token);
    return 0;
  }
