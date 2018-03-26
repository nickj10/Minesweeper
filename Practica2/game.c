#include "game.h"
#include <stdio.h>

void fflushnou () {
    char buffer;   
    fscanf (stdin, "%c", &buffer);
    while (buffer != EOF && buffer != '\n') {
        fscanf (stdin, "%c", &buffer);
    }
}