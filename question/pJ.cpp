#include <stdio.h>
#define N_MAX 10
int main(int argc, char *argv[]) {
    int i, catalan[N_MAX + 2] = {1};
    for (i = 1; i < N_MAX + 2; i++) {
        catalan[i] = catalan[i - 1] * 2 * (2 * i - 1) / (i + 1);
    }
    int N, index = 0;
    while (scanf("%d", &N) != EOF && ++index) {
        if (index > 1) printf("\n");
        printf("%d\n", catalan[N]);
    }
    return 0;
}