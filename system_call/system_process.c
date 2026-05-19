#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*
 * fork(2), getpid(2), getppid(2): 프로세스를 복제하고 PID를 확인합니다.
 * - fork() 반환값: 자식에서는 0, 부모에서는 자식 PID, 실패 시 -1
 */
int main(void) {
    printf("before fork: pid=%d, ppid=%d\n", getpid(), getppid());
    fflush(stdout); /* fork 전에 비우지 않으면 버퍼 내용이 부모·자식에 복제됩니다 */

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("  child:  pid=%d, ppid=%d\n", getpid(), getppid());
        fflush(stdout);
        _exit(0);
    }

    printf("  parent: pid=%d, child_pid=%d\n", getpid(), pid);
    int status;
    waitpid(pid, &status, 0);
    printf("child exited with status %d\n", WEXITSTATUS(status));

    return 0;
}
