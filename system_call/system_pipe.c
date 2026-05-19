#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

/*
 * pipe(2) + fork(2): 부모·자식 프로세스가 파이프(fd[0]=읽기, fd[1]=쓰기)로 데이터를 주고받습니다.
 * - fork() 후에는 fd를 사용하지 않는 쪽을 close() 해야 데드락을 피할 수 있습니다.
 */
int main(void) {
    int fds[2];
    if (pipe(fds) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        /* 자식: 쓰기 끝만 사용 */
        close(fds[0]);
        const char *msg = "message via pipe\n";
        write(fds[1], msg, strlen(msg));
        close(fds[1]);
        _exit(0);
    }

    /* 부모: 읽기 끝만 사용 */
    close(fds[1]);
    char buf[64];
    ssize_t n = read(fds[0], buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';
        printf("parent received: %s", buf);
    }
    close(fds[0]);

    waitpid(pid, NULL, 0);
    return 0;
}
