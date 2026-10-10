#include <stdio.h>

int main() {
    printf("Roll no: 25071A6253\n");
    int ms, ps, p_size, total_frames, total_pages;
    int page_table[20];
    int la, p, d, pa;

    printf("Enter main memory size (in bytes): ");
    scanf("%d", &ms);
    printf("Enter page size (in bytes): ");
    scanf("%d", &ps);

    total_frames = ms / ps;
    printf("Total frames available in memory: %d\n\n", total_frames);

    printf("Enter process size (in bytes): ");
    scanf("%d", &p_size);

    total_pages = p_size / ps;
    if (p_size % ps != 0) total_pages++;

    if (total_pages > total_frames) {
        printf("\nMemory Allocation Failed: Not enough frames available.\n");
        return 0;
    }

    printf("Total pages required for process: %d\n", total_pages);
    printf("Enter frame numbers allocated to each page:\n");
    for (int i = 0; i < total_pages; i++) {
        printf("Page %d -> Frame No: ", i);
        scanf("%d", &page_table[i]);
    }

    printf("\nEnter Logical Address to translate: ");
    scanf("%d", &la);

    p = la / ps;
    d = la % ps;

    if (p >= total_pages) {
        printf("\nInvalid Logical Address! (Page number %d exceeds allocated pages)\n", p);
    } 
    else {
        pa = (page_table[p] * ps) + d;
        printf("\n--- Address Translation Details ---\n");
        printf("Page Number (p)      : %d\n", p);
        printf("Page Offset (d)      : %d\n", d);
        printf("Allocated Frame No   : %d\n", page_table[p]);
        printf("Physical Address     : %d\n", pa);
    }

    return 0;
}

