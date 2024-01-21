#include <stdio.h>
#include <stdlib.h>
 // Define the maximum number of frames in memory

int main() {
    int num_pages; // Number of pages in the reference string
    int pages[100]; // Page reference sequence
    int x; // Array to represent the frames in memory
    int frame_count = 0; // Number of frames currently in use
    int page_faults = 0; // Count of page faults
    // Initialize frames array to -1 (indicating empty frames)  
    // Get user input for the page reference sequence
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the number of frames");
    scanf("%d",&x);
    int frames[x];
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }
     
    for (int i = 0; i < x; i++) {
        frames[i] = -1;
    }

    // Simulate page references
    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int page_found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        // If the page is not in a frame, perform page replacement
        if (!page_found) {
            if (frame_count < x) {
                // If there are empty frames, use them
                frames[frame_count] = page;
                frame_count++;
            } else {
                // Replace the oldest page in the frame (FIFO)
                frames[page_faults % x] = page;
            }
            page_faults++;
        }

        // Print the current state of memory
        printf("Page %d: [", page);
        for (int j = 0; j < frame_count; j++) {
            printf("%d", frames[j]);
            if (j < frame_count - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
