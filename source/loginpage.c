#include "API/html_layout.h"
#include <stdio.h>

int main(void)
{
    printf("Content-Type: text/html;\n\n");
    //load_template("headers/styles.html");
    load_template("/ESNET/source/templates/loginpage.html");
    return 0;
}
