#include <stdio.h>
#define FRAMES 3

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[FRAMES] = {-1, -1, -1}, page_faults = 0;
    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0, index = -1;
        for (int j = 0; j < FRAMES; j++)
            if (frames[j] == page) {
                found = 1;
                break;
            } else if (frames[j] == -1) {
                index = j;
                break;
            }
        if (!found) {
            if (index != -1) frames[index] = page;
            else {
                int temp[FRAMES] = {-1, -1, -1};
                for (int j = i + 1; j < n && index == -1; j++)
                    for (int k = 0; k < FRAMES && index == -1; k++)
                        if (frames[k] == pages[j]) {
                            temp[k] = 1;
                            index = j;
                            break;
                        }
                for (int j = 0; j < FRAMES; j++)
                    if (temp[j] == -1) index = j;
                frames[index] = page;
            }
            page_faults++;
        }
    }
    printf("Page faults: %d\n", page_faults);
}
