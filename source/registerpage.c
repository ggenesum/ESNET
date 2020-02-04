#include "API/html_layout.h"
#include <stdio.h>

int main(void)
{
    printf("Content-Type: text/html;\n\n");
    load_template("../extremities/header.html");
    load_template("../templates/registerpage.html");
    load_template("../extremities/footer.html");
    
    return 0;
}