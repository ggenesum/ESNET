#include "API/html_layout.h"
#include <stdio.h>

int main(void)
{
    printf("Content-Type: text/html;\n\n");
    load_template("headers/styles.html");

    printf("Esnet\n\n");
    load_template("templates/index.html");
    return 0;
}
