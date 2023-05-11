#include<stdio.h>
#include<stdlib.h>

int main() {
    int p, r, i, j, k, c;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);
    int alloc[p][r], max[p][r], avail[r], need[p][r];
    int finish[p], safesequence[p], index = 0;
    
    // Initialize all arrays to 0
    for (i = 0; i < p; i++) {
        finish[i] = 0;
        safesequence[i] = 0;
        for (j = 0; j < r; j++) {
            alloc[i][j] = 0;
            max[i][j] = 0;
            need[i][j] = 0;
        }
    }
    
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the maximum required matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources:\n");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }
    
    // Calculate the need matrix
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Check if the system is in a safe state
    for (k = 0; k < p; k++) {
        for (i = 0; i < p; i++) {
            if (finish[i] == 0) {
                int safe = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe) {
                    finish[i] = 1;
                    safesequence[index++] = i;
                    for (j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }
    }
    
    // Output the safe sequence if one exists
    int isSafe = 1;
    for (i = 0; i < p; i++) {
        if (finish[i] == 0) {
            isSafe = 0;
            break;
        }
    }

    if (isSafe) {
        printf("The safe sequence is:\n");
        for (i = 0; i < p; i++) {
            printf("P%d ", safesequence[i]);
        }
    } else {
        printf("Unsafe state -- deadlock detected");
    }

    return 0;
}
