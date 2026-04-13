#include <stdio.h>

size_t my_strlen(const char *s) {
    const char *p = s;
    while (*p != '\0') { // 포인터가 가리키는 값이 NULL 문자가 아닐 때까지
        p++; // 포인터를 증가시킴
    }

    return p - s; // 최종 주소에서 시작 주소를 빼면 길이가 나옴
}