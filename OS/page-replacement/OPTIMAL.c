#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, i, j, frames, pageFaults = 0, s, k, max, maxIndex;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int incomingStream[n];
    printf("Enter the incoming stream of requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &incomingStream[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int temp[frames];
    for(i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    // Optimal Algorithm
    for(i = 0; i < n; i++) {
        s = 0;
        for(j = 0; j < frames; j++) {
            if(incomingStream[i] == temp[j]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if(pageFaults <= frames && (s == 0)) {
            temp[i] = incomingStream[i]; 
        } else if(s == 0) {
            max = INT_MIN;
            for(j = 0; j < frames; j++) {
                int found = 0;
                for(k = i + 1; k < n; k++) {
                    if(incomingStream[k] == temp[j]) {
                        found = 1;
                        if(k > max) {
                            max = k;
                            maxIndex = j;
                        }
                        break;
                    }
                }
                if(found == 0) {
                    maxIndex = j;
                    break;
                }
            }
            temp[maxIndex] = incomingStream[i];
        }
        printf("\n");
        printf("%d\t\t\t", incomingStream[i]);
        for(j = 0; j < frames; j++) {
            if(temp[j] != -1) {
                printf(" %d\t\t\t", temp[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d", pageFaults);
    return 0;
}
