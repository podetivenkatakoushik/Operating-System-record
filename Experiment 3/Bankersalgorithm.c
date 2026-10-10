int main() 
{
    printf("Roll no: 25071A6253\n");
    int n, m, alloc[10][10], max[10][10], need[10][10], avail[10], finish[10] = {0}, safeSeq[10], count = 0;
    printf("Enter number of processes: "); scanf("%d", &n);
    printf("Enter number of resource types: "); scanf("%d", &m);
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &alloc[i][j]);
    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++) scanf("%d", &avail[j]);
    int work[10];
    for (int j = 0; j < m; j++) work[j] = avail[j];
  while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int possible = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) { possible = 0; break; }
                }
                if (possible) 
                {
                    for (int j = 0; j < m; j++) work[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1; 
                }
            }
        }
        if (!found) break;
    }
    if (count == n) {
        printf("\nSystem is in a SAFE STATE.\nSafe Sequence: ");
        for (int i = 0; i < n; i++) printf("P%d ", safeSeq[i] + 1);
        printf("\n");
    } else {
        printf("\nSystem is in an UNSAFE STATE (Deadlock possible).\n");
    }
    return 0;
}
