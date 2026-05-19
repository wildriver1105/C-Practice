#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*
 * stat(2): 경로에 대한 메타데이터(크기, 권한, inode 등)를 조회합니다.
 * - struct stat의 st_mode, st_size, st_mtime 등을 확인할 수 있습니다.
 */
static void print_mode(mode_t mode) {
    printf("  type: ");
    if (S_ISREG(mode))  printf("regular file\n");
    else if (S_ISDIR(mode)) printf("directory\n");
    else                printf("other\n");

    printf("  permissions: ");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main(void) {
    const char *path = "stat_demo.txt";

    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    const char *msg = "stat demo\n";
    write(fd, msg, strlen(msg));
    close(fd);

    struct stat st;
    if (stat(path, &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("stat(\"%s\"):\n", path);
    printf("  size: %lld bytes\n", (long long)st.st_size);
    printf("  inode: %llu\n", (unsigned long long)st.st_ino);
    printf("  link count: %u\n", (unsigned)st.st_nlink);
    print_mode(st.st_mode);

    return 0;
}
