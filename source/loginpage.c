#include "API/html_layout.h"
#include <stdio.h>

int main(void)
{
    printf("Content-Type: text/html;\n\n");
    load_template("../headers/header.html");
    load_template("../templates/loginpage.html");
    load_template("../headers/footer.html");
    
    return 0;
}
