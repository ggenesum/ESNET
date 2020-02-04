#ifndef COOKIES
#define COOKIES

struct login_cookie
{
    char *auth_token;
    char *username;
    char *email;
};

int add_login_cookies(struct login_cookie lc);
void cookieparse(char *str, char **var, int argc);

#endif
