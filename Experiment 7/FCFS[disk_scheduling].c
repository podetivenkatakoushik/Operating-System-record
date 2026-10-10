#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Roll no: 25071A6253\n");
    int n, head, req[20], thm = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    printf("Enter request sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: "); scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);
    for (int i = 0; i < n; i++) {
        thm += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nTotal Head Movement = %d\nAverage Seek Time = %.2f\n", thm, (float)thm / n);
    return 0;
}
