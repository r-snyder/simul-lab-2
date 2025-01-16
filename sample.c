#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Calculate the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fclose(file);

    if (file_size < 0) {
        fprintf(stderr, "Error: Failed to determine the size of '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Print the file size
    printf("The size of '%s' is %ld bytes.\n", argv[1], file_size);

    return EXIT_SUCCESS;
}
