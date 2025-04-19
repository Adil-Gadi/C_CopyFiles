#include <stdio.h>

int main(int argc, const char** argv) {
    if (argc < 3) {
        perror("Provide both name of the file to be copied and the new name for the copied file");
        return 1;
    }

    const char* origin = argv[1];
    const char* copy = argv[2];

    FILE* origin_handle = fopen(origin, "r");
    FILE* copy_handle = fopen(copy, "w");

    if (origin_handle == NULL) {
        perror("Unable to open original file");
        return 1;
    }

    if (copy_handle == NULL) {
        perror("Unable to create copied file");
        return 1;
    }

    char buffer[BUFSIZ];
    while (fgets(buffer, sizeof(buffer), origin_handle) != NULL) {
        fprintf(copy_handle, "%s", buffer);
    }

    printf("Successfully copied.\n");

    fclose(origin_handle);
    fclose(copy_handle);

    return 0;
}