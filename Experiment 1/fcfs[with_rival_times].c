#include <stdio.h>
int main() {
    int n, at[20], bt[20], time = 0;
    float twt = 0, ttat = 0;
    printf("Roll no: 25071A6253\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        time += bt[i];
        int tat = time - at[i], wt = tat - bt[i];
        twt += wt; ttat += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], time, wt, tat);
    }
    printf("\nAverage Waiting Time = %.2f\nAverage Turnaround Time = %.2f\n", twt / n, ttat / n);
    return 0;
}
