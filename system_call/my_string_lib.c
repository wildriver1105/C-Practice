#include <stdio.h>

size_t my_strlen(const char *s) {
    const char *p = s;
    while (*p != '\0') {    // 포인터가 가리키는 값이 NULL 문자가 아닐 때까지
        p++;                // 포인터를 증가시킴
    }

    return p - s;           // 최종 주소에서 시작 주소를 빼면 길이가 나옴
}

char *my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while (*src != '\0') {
        *dest = *src;   // src의 내용을 dest에 복사 (값을 복사)
        dest++;         // 둘 다 한 칸씩 전진
        src++;
    }
    *dest = '\0';       // 마지막에 NULL 문자를 추가
    return ptr;
}

int main() {
    char source[] = "Test String";
    char destination[50];

    printf("원본 문자열 길이: %zu\n", my_strlen(source));

    my_strcpy(destination, source);
    printf("복사된 문자열: %s\n", destination);

    return 0;
}