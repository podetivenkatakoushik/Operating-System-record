#include <stdio.h>
int main() {
    printf("Roll no: 25071A6253\n\n");
    int m, n;
    int s[10], a[10];
    int S = 0, total_allocated = 0;

    printf("Enter total frames available in physical memory: ");
    scanf("%d", &m);
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size (in pages/virtual memory) for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d size: ", i + 1);
        scanf("%d", &s[i]);
        S += s[i];
    }

    if (S == 0) {
        printf("\nInvalid total process size.\n");
        return 0;
    }
    printf("\n--- Proportional Frame Allocation Result ---\n");
    printf("Total Virtual Memory Required (S) = %d pages\n\n", S);
    printf("Process\tSize (s_i)\tAllocated Frames (a_i)\tPercentage\n");

    for (int i = 0; i < n; i++) {
        a[i] = (int)(((double)s[i] / S) * m);
        total_allocated += a[i];
        double pct = ((double)s[i] / S) * 100.0;
        printf("P%d\t%d\t\t%d\t\t\t%.2f%%\n", i + 1, s[i], a[i], pct);
    }
    printf("\nTotal Frames Allocated: %d / %d", total_allocated, m);
    printf("\nUnallocated Buffer Frames: %d\n", m - total_allocated);

    return 0;
}
