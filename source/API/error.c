#include <stdio.h>
#include <stdlib.h>
#include "html_layout.h"

int errpage(char *errormsg, int debug)
{
  char **vars = (char**)malloc(sizeof(char*)); //dynamicly generated content (vars that are embeeded in html page)
  //load_template("/headers/styles.html");
  //add debug/prod error modes
  if (debug && errormsg != NULL)
    vars[0] = errormsg;
  else
    vars[0] = "We're sorry, an error happened on our side.\n Please try again later, or contact us so we can work on this issue.";

  printf("Content-Type: text/html;\n\n");
  load_ztemplate("subtemplates/error.zhtml",vars);
  return 0;
}
