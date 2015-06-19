#include <stdio.h>
#include <math.h>
 
void main() {
    int N = 1;
    long int T, aux;
    int i, j, a = 1;
    while (N != 0){
        scanf("%d", &N);
 
        if (N > 0) {
            aux = pow(2, N + N - 2);
            T = 0;
            while (aux >= 1){
                aux = floor(aux / 10);
                T ++;
            }
            if (N == 1){
                a = 1;
                printf("%1d\n\n", a);
            } else {
                for (i = 0; i < N; i ++){
                    for (j = 0; j < N - 1; j ++){
                        a = pow(2, i + j);
                        switch (T){
                            case 1:
                                printf("%1d ", a);
                                break;
                            case 2:
                                printf("%2d ", a);
                                break;
                            case 3:
                                printf("%3d ", a);
                                break;
                            case 4:
                                printf("%4d ", a);
                                break;
                            case 5:
                                printf("%5d ", a);
                                break;
                            case 6:
                                printf("%6d ", a);
                                break;
                            case 7:
                                printf("%7d ", a);
                                break;
                            case 8:
                                printf("%8d ", a);
                                break;
                            case 9:
                                printf("%9d ", a);
                                break;
                            case 10:
                                printf("%10d ", a);
                                break;
                        }
                    }
                    a = pow(2, i + j);
                    switch (T){
                        case 1:
                            printf("%1d\n", a);
                            break;
                        case 2:
                            printf("%2d\n", a);
                            break;
                        case 3:
                            printf("%3d\n", a);
                            break;
                        case 4:
                            printf("%4d\n", a);
                            break;
                        case 5:
                            printf("%5d\n", a);
                            break;
                        case 6:
                            printf("%6d\n", a);
                            break;
                        case 7:
                            printf("%7d\n", a);
                            break;
                        case 8:
                            printf("%8d\n", a);
                            break;
                        case 9:
                            printf("%9d\n", a);
                            break;
                        case 10:
                            printf("%10d\n", a);
                            break;
                    }
                }
                printf("\n");
            }
        }
    }
}
