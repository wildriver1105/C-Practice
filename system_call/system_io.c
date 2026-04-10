#include <unistd.h> // System Call을 위한 헤더
#include <fcntl.h> // File Control을 위한 헤더
#include <string.h>

int main() {
    const char *msg = "System Deep Dive starts now!\n";

    // 1. 파일 열기
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) return 1;

    // 2. 데이터 쓰기
    write(fd, msg, strlen(msg));

    // 파일 닫기
    close(fd);

    return 0;
}