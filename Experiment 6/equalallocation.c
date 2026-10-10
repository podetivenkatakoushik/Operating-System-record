#include <stdio.h>

int main() {
    printf("Roll no: 25071A6253\n\n");
    int total_frames, m;
    int page_req[10], allocated[10];

    printf("Enter total frames in physical memory: ");
    scanf("%d", &total_frames);
    printf("Enter number of processes: ");
    scanf("%d", &m);

    if (m <= 0 || total_frames < m) {
        printf("\nAllocation Failed! Insufficient frames for equal allocation.\n");
        return 0;
    }

    printf("Enter page requirements for each process:\n");
    for (int i = 0; i < m; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &page_req[i]);
    }

    int equal_share = total_frames / m;
    int leftover = total_frames % m;

    printf("\n--- Equal Frame Allocation Result ---\n");
    printf("Process\tPage Req\tAllocated Frames\tUnmet Pages\n");
    for (int i = 0; i < m; i++) {
        allocated[i] = equal_share;
        int unmet = (page_req[i] > allocated[i]) ? (page_req[i] - allocated[i]) : 0;
        printf("P%d\t%d\t\t%d\t\t\t%d\n", i + 1, page_req[i], allocated[i], unmet);
    }

    printf("\nTotal Allocated Frames: %d / %d", equal_share * m, total_frames);
    printf("\nLeftover System Frames: %d\n", leftover);

    return 0;
}
