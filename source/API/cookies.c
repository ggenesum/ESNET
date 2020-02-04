#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct login_cookie
{
    char *auth_token;
    char *username;
    char *email;
};

void cookieparse(char *str, char **var, int argc) //parse cookie string to array
{
  char *token = strtok(str, "=");
  for (int i = 0; i < argc; i++)
	{
    token = strtok(NULL, ";");
    if (token == NULL)
    {
      break;
    }
    var[i] = token;
    token = strtok(NULL, "=");
	}
}

int add_login_cookies(struct login_cookie lc)
  {
    if (lc.auth_token == NULL)
    {
      return 1; //no cookie :(
    }
    printf("Set-Cookie: auth_token=%s\n",lc.auth_token);
    if (lc.username != NULL)
    printf("Set-Cookie: username=%s\n",lc.username);
    if (lc.email != NULL)
      printf("Set-cookie: email=%s\n",lc.email);

    return 0;
  }
