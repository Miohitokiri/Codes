#ifndef LIBTEST_H_INCLUDED
#define LIBTEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void init(int, long long[]);
void change(int, int, long long);
long long query(int);

int main()
{
    int n, m, q, a, b, i;
    long long* d;
    long long k;

    scanf("%d%d%d", &n, &m, &q);
    d = (long long*)malloc(sizeof(long long) * n);

    for (i = 0; i < n; i++) scanf("%lld", d + i);
    init(n, d);
    for (i = 0; i < m; i++) {
        scanf("%d%d%lld", &a, &b, &k);
        change(a, b, k);
    }
    for (i = 0; i < q; i++) {
        scanf("%d", &a);
        printf("%lld\n", query(a));
    }

    free(d);
}

#endif // LIBTEST_H_INCLUDED
