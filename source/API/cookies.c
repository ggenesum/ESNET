#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct login_cookie
{
    char *auth_token;
    char *username;
};

int add_login_cookies(struct login_cookie lc)
  {
    if (lc.auth_token == NULL)
    {
      return 1; //no cookie :(
    }
    printf("Set-Cookie: auth_token=%s\n",lc.auth_token);
    printf("Set-Cookie: username=%s\n",lc.username);

    return 0;
  }
