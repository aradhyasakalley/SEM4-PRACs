#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 100
#define MAX_REQUESTS 1000

int main() {
    int requests[MAX_REQUESTS], frames[MAX_FRAMES];
    int n, m, i, j, k, p, q, min, min_idx, page_faults;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        frames[i] = -1;
    }

    page_faults = 0;

    for (i = 0; i < n; i++) {
        p = requests[i];
        q = -1;

        for (j = 0; j < m; j++) {
            if (frames[j] == p) {
                q = j;
                break;
            }
        }

        if (q == -1) {
            if (i < m) {
                q = i;
            } else {
                min = 99999;
                for (j = 0; j < m; j++) {
                    k = frames[j];
                    p = 0;
                    for (p = i - 1; p >= 0; p--) {
                        if (requests[p] == k) {
                            break;
                        }
                    }
                    if (p < min) {
                        min = p;
                        min_idx = j;
                    }
                }
                q = min_idx;
            }

            frames[q] = requests[i];
            page_faults++;
        }

        printf("\n%d\t", requests[i]);
        for (j = 0; j < m; j++) {
            if (frames[j] == -1) {
                printf("-\t");
            } else {
                printf("%d\t", frames[j]);
            }
        }
    }

    printf("\n\nNumber of page faults: %d\n", page_faults);

    return 0;
}
