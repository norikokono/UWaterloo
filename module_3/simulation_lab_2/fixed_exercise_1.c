// The main issue with your code is that the `system` function is not the best way to achieve this due to potential security risks. 
// Instead, you can use file handling functions in C to get the file size. Here's a revised version of your program:
// This program prints the size of a specified file in bytes
// Code revised with help from Microsoft Copilot

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    printf("The size of the file is %ld bytes\n", fileSize);
    return 0;
}

// This version opens the file in binary mode, seeks to the end of the file to determine its size, and then prints the size.
// This approach is safer and more efficient. 
