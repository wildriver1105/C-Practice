#include <unistd.h> // System Call을 위한 헤더
#include <fcntl.h> // File Control을 위한 헤더
#include <string.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;  // 1. a가 가리키는 주소로 가서 값을 꺼내 temp에 보관 (Read)
    *a = *b;        // 2. b가 가리키는 주소의 값을 a가 가리키는 주소에 덮어씀 (Update)
    *b = temp;      // 3. temp에 보관했던 값을 b가 가리키는 주소에 덮어씀 (Update)
}

int main() {
    const char *msg = "System Deep Dive starts now!\n";

    // 1. 파일 열기
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) return 1;

    // 2. 데이터 쓰기
    write(fd, msg, strlen(msg));

    // 파일 닫기
    close(fd);

    int x = 10;
    int y = 20;

    printf("--- Swap 전 ---\n");
    printf("x의 값: %d, 주소: %p\n", x, (void*)&x);
    printf("y의 값: %d, 주소: %p\n", y, (void*)&y);

    // [호출] & 연산자를 통해 x와 y의 '주소'를 직접 넘깁니다.
    // 이것이 C에서 원본 데이터를 수정하는 유일한 방법입니다.
    swap(&x, &y);

    printf("\n--- Swap 후 ---\n");
    printf("x의 값: %d\n", x);
    printf("y의 값: %d\n", y);

    return 0;
}