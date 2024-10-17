// TO CREATE A FILE WITH HOLE IN IT

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    
    int fd = open("file_with_holes.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    
    const char *data1 = "Hello, World!";
    write(fd, data1, 13); 

    
    off_t offset = 100; 
    if (lseek(fd, offset, SEEK_SET) == (off_t)-1) {
        perror("Error seeking");
        close(fd);
        return 1;
    }

    
    const char *data2 = "This is a hole!";
    write(fd, data2, 15); 

    
    close(fd);
    
    printf("File created with holes in it.\n");
    return 0;
}

