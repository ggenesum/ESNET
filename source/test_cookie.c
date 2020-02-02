#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/cookies.h"


int main()
{
  printf("Content-Type: text/html;\n\n");
  load_template("headers/styles.html");

  char **parsed_cookies = (char**)malloc(2*sizeof(char*)); //post request parsed values
  char *cookies= getenv("HTTP_COOKIE");

  cookieparse(cookies,parsed_cookies,2); //parse cookie string to array
  printf("<p> token found: %s </p>\n",parsed_cookies[0]);
  printf("<p> You are %s\n </p>",parsed_cookies[1]);

  return 0;
}
