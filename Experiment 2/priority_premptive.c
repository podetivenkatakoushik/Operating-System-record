#include <stdio.h>
int main() 
{
    printf("Roll no: 25071A6253\n");
    int n, at[10], bt[10], pr[10], rt[10], ct[10], done = 0, time = 0, min_pr, idx;
    float twt = 0, ttat = 0;
    printf("Enter number of processes: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]); rt[i] = bt[i];
    }
    while (done < n) {
        min_pr = 1e9; idx = -1;
        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] > 0 && pr[i] < min_pr) { min_pr = pr[i]; idx = i; }
        if (idx == -1) { time++; continue; }
        rt[idx]--; time++;
        if (rt[idx] == 0) { done++; ct[idx] = time; }
    }
    printf("\nProcess\tAT\tBT\tPr\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        int tat = ct[i] - at[i], wt = tat - bt[i]; twt += wt; ttat += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], ct[i], wt, tat);
    }
    printf("\nAverage Waiting Time = %.2f\nAverage Turnaround Time = %.2f\n", twt / n, ttat / n);
    return 0;
}
