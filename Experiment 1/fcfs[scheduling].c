#include <stdio.h>
int main() {
    int n, bt[20], wt[20], tat[20];
    float twt = 0, ttat = 0;
    printf("Roll no: 25071A6253\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        twt += wt[i]; ttat += tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    printf("\nAvg WT = %.2f | Avg TAT = %.2f\n", twt / n, ttat / n);
    return 0;
}
