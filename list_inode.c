// Write a c program to list for every file in a directory its inode number and file name

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void list_files(const char *path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; 
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        printf("Inode: %lu, File: %s\n", (unsigned long)file_stat.st_ino, entry->d_name);
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    const char *dir_path = (argc > 1) ? argv[1] : "."; 
    list_files(dir_path);
    return 0;
}

