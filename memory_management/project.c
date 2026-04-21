#include <stdio.h>
#include <stdlib.h> // malloc, free를 쓰기 위해 필수!

struct Project {
    int id;
    float budget;
};

int main() {
    // 1. 힙 영역에 struct Project 크기만큼 메모리 할당
    // (struct Project *)는 "받아온 주소를 이 구조체 타입으로 해석하겠다"는 뜻입니다.
    struct Project *my_proj = (struct Project *)malloc(sizeof(struct Project));

    // 2. 할당 실패 체크 (메모리가 부족할 경우 NULL 리턴)
    if (my_proj == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    // 3. 데이터 입력 (화살표 연산자 사용)
    my_proj->id = 101;
    my_proj->budget = 5000.50f;

    printf("프로젝트 ID: %d, 예산: %.2f\n", my_proj->id, my_proj->budget);

    // 4. 중요: 메모리 해제
    // 이 코드를 생략하면 프로그램이 끝나기 전까지 이 메모리는 '미사용' 상태로 묶입니다.
    free(my_proj); 
    
    // 5. 안전을 위한 습관: 해제 후 포인터를 NULL로 초기화
    my_proj = NULL; 

    return 0;
}