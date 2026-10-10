#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Roll no: 25071A6253\n");
    int n, h, r[30], s, d, thm = 0, p = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    printf("Enter request sequence: "); for (int i = 0; i < n; i++) scanf("%d", &r[i]);
    printf("Enter initial head position: "); scanf("%d", &h);
    printf("Enter total disk size: "); scanf("%d", &s);
    printf("Enter direction (1 for High/Right, 0 for Low/Left): "); scanf("%d", &d);
    r[n++] = h; r[n++] = d ? s - 1 : 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (r[j] > r[j + 1]) { int t = r[j]; r[j] = r[j + 1]; r[j + 1] = t; }
    while (r[p] != h) p++;
    printf("\nSeek Sequence: %d", h);
    int cur = h, step = d ? 1 : -1, start = d ? p + 1 : p - 1, end = d ? n : -1;
    for (int pass = 0; pass < 2; pass++) {
        for (int i = start; i != end; i += step) { thm += abs(r[i] - cur); cur = r[i]; printf(" -> %d", cur); }
        step = -step; start = (d == (pass == 0)) ? p - 1 : p + 1; end = (d == (pass == 0)) ? -1 : n;
    }
    printf("\nTotal Head Movement = %d\nAverage Seek Time = %.2f\n", thm, (float)thm / (n - 2));
    return 0;
}
