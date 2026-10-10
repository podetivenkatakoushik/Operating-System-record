#include <stdio.h>
int main()
{
    printf("Roll no: 25071A6253\n");
    int m, n, bsize[10], psize[10], alloc[10], occupied[10] = {0};
    printf("Enter number of blocks: "); scanf("%d", &m);
    printf("Enter block sizes: ");
    for (int i = 0; i < m; i++) scanf("%d", &bsize[i]);
    printf("Enter number of processes: "); scanf("%d", &n);
    printf("Enter process sizes: ");
    for (int i = 0; i < n; i++) { 
     scanf("%d", &psize[i]); alloc[i] = -1;
 }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!occupied[j] && bsize[j] >= psize[i]) {
                alloc[i] = j;
                occupied[j] = 1;
                break; }  }    }
    printf("\nProcess\tProcess Size\tBlock No.\tBlock Size\tInternal Frag\n");
    for (int i = 0; i < n; i++) {
        if (alloc[i] != -1)
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, psize[i], alloc[i] + 1, bsize[alloc[i]], bsize[alloc[i]] - psize[i]);
        else
            printf("P%d\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, psize[i]);}
    return 0;
}
