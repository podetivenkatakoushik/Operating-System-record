#include <stdio.h>

int main() {
    printf("Roll no: 25071A6253\n\n");
    int total_frames, min_per_process, n;
    int page_req[10], allocated[10];

    printf("Enter total frames in physical memory: ");
    scanf("%d", &total_frames);
    printf("Enter minimum frames required per process (by architecture): ");
    scanf("%d", &min_per_process);
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int total_min_needed = n * min_per_process;
    if (total_min_needed > total_frames) {
        printf("\nAllocation Failed! Total available frames (%d) < Required minimum frames (%d).\n", 
               total_frames, total_min_needed);
        return 0;
    }

    printf("\nEnter page requirements for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &page_req[i]);
        allocated[i] = min_per_process;
    }

    int total_allocated = total_min_needed;
    int remaining = total_frames - total_allocated;

    printf("\n--- Minimum Frame Allocation Result ---\n");
    printf("Process\tPage Req\tAllocated Frames\tStatus\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t\t%s\n", 
               i + 1, page_req[i], allocated[i], 
               (allocated[i] >= page_req[i]) ? "Satisfied" : "Needs Swap Space");
    }
    printf("\nTotal Frames Allocated: %d / %d", total_allocated, total_frames);
    printf("\nRemaining Unallocated Frames: %d\n", remaining);

    return 0;
}
