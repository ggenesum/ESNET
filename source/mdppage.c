#include "API/html_layout.h"
#include <stdio.h>

int main(void)
{
    printf("Content-Type: text/html;\n\n");
    load_template("../subtemplates/header.html");
    load_template("../templates/mdplost.html");
    load_template("../subtemplates/footer.html");

    return 0;
}