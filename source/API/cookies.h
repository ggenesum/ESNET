#ifndef COOKIES
#define COOKIES

struct login_cookie
{
    char *auth_token;
    char *username;
};

int add_login_cookies(struct login_cookie lc);
#endif
