#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

/*
 * read(2): 열린 파일 디스크립터(fd)에서 바이트를 읽습니다.
 * - 반환값: 실제로 읽은 바이트 수 (0이면 EOF, -1이면 오류)
 * - 버퍼 크기만큼 한 번에 읽히지 않을 수 있으므로 루프로 모을 수 있습니다.
 */
int main(void) {
    const char *path = "sample_read.txt";
    const char *content = "Hello from read(2)!\n";

    int wfd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("open (write)");
        return 1;
    }
    write(wfd, content, strlen(content));
    close(wfd);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open (read)");
        return 1;
    }

    char buf[128];
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buf[n] = '\0';
    printf("read %zd bytes:\n%s", n, buf);

    close(fd);
    return 0;
}
