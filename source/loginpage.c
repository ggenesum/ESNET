#include "API/html_layout.h"
#include <stdio.h>

int main(void)
{
    printf("Content-Type: text/html;\n\n");
    load_template("../headers/header.html");
    load_template("../templates/footer.html");
    load_template("../templates/loginpage.html");
    
    return 0;
}
