#include <stdio.h>
#include <stdlib.h>

#include "euler.h"

int main(int argc, char** argv){
    if (argc != 2) {
        printf("Usage: %s <iterations>\n", argv[0]);
        return 1;
    }
    int iters = atoi(argv[1]);

    double e = euler(iters);
    printf("e = %.17g\n", e);
    return 0;
}
