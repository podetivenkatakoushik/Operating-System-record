#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Roll no: 25071A6253\n");
    int n, head, req[20], visited[20] = {0}, thm = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    printf("Enter request sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: "); scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);
    for (int count = 0; count < n; count++) {
        int min_dist = 1e9, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && abs(req[i] - head) < min_dist) {
                min_dist = abs(req[i] - head);
                idx = i;
            }
        }
        visited[idx] = 1;
        thm += min_dist;
        head = req[idx];
        printf(" -> %d", head);
    }
    printf("\nTotal Head Movement = %d\nAverage Seek Time = %.2f\n", thm, (float)thm / n);
    return 0;
}
