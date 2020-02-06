#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "API/html_layout.h"
#include "API/cookies.h"


int main()
{
  printf("Content-Type: text/html;\n\n");
  load_template("../headers/styles.html");

  char **parsed_cookies = (char**)malloc(1*sizeof(char*)); //post request parsed values
  char *cookies= getenv("HTTP_COOKIE");

  cookieparse(cookies,parsed_cookies,1); //parse cookie string to array
  printf("<p> token found: %s </p>\n",parsed_cookies[0]);

  return 0;
}
