#include <stdio.h>

void main() {
    int N;

    while (scanf("%d", &N) != EOF){
        if (N > 0){
            printf ("vai ter duas!\n");
        } else {
            printf ("vai ter copa!\n");
        }
    }
}
