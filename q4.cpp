#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main() {
    int fd = creat("newfile.txt", S_IRUSR | S_IWUSR);
    printf("File descriptor of newfile.txt: %d\n", fd);
    int fd2 = open("existingfile.txt", O_RDWR);
    printf("File descriptor of existingfile.txt: %d\n", fd2);
    close(fd);
    printf("Closed the file descriptor for newfile.txt.\n");
    char buf[] = "Hello, world!";
    write(fd2, buf, 13);
    printf("Wrote to the file descriptor for existingfile.txt.\n");
    char buf2[14];
    read(fd2, buf2, 13);
    printf("Read from the file descriptor for existingfile.txt: %s\n", buf2);
    close(fd2);
    printf("Closed the file descriptor for existingfile.txt.\n");
    return 0;
}
