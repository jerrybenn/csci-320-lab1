#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 *
 * fileName is c-string representing the file to read.
 *
 */
char *readString(char *fileName)
{
    // TODO: Replace this line with your code
    FILE *file = fopen(fileName, "r");

    char *buffer = (char *)malloc(100 * sizeof(char));

    fgets(buffer, 100, file);

    buffer[strcspn(buffer, "\n")] = '\0';

    fclose(file);

    return buffer;
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 *
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 *
 */
char *mysteryExplode(const char *str)
{
    // TODO: Replace this line with your code
    int len = strlen(str);               // uses strlen to count all the characters in a string not including the null terminator
    int window = 0;                      // created a window that will add said characters to the result string, it will add it to the result string then repeat the process
    int resultLen = len * (len + 1) / 2; // Sum of lengths of all prefixes
    char *resultString = (char *)malloc(resultLen + 1);
    resultString[0] = '\0';

    for (int i = 0; i < len; i++)
    {
        window++; // Increment window to (i+1)
        strncat(resultString, str, window);
    }

    return resultString;
}
