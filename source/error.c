#include <stdio.h>
#include "API/html_layout.h"

int main()
{
  char *error = "error";
  //load_template("/headers/styles.html");
  //add debug/prod error modes
  printf("Content-Type: text/html;\n\n");
  printf("<p style=\"color:#FF0000\";>server error:\n%s</p>\n</html>",error);
  return 0;
}
