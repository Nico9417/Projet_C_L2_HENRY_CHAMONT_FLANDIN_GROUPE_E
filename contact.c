#include <stdio.h>
#include <stdlib.h>
#include "contact.h"


char *scanString()
{
    char *mot = (char *)malloc(100*sizeof(char));
    scanf("%s", mot);
    return mot;
}

