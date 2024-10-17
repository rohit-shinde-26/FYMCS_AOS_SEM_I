// Write a c program to takes multiple files as command line argument and print their inode number

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    
    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];

        
        if (stat(filename, &fileStat) < 0) {
            perror(filename);
            continue; 
        }

      
        printf("File: %s, Inode Number: %lu\n", filename, (unsigned long)fileStat.st_ino);
    }

    return 0;
}

