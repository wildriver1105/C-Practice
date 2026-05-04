#include <stdio.h>
#include <stdlib.h> // malloc, free를 위한 헤더

struct Employee {
    int id;
    float performance;
};

int main() {
    int n;
    printf("현재 스타트업의 총 인원수는 몇 명입니까? ");
    scanf("%d", &n);

    // 1. 핵심: (구조체 크기 * n) 만큼의 거대한 메모리 블록을 힙에 요청합니다.
    // team은 이 거대한 땅의 '첫 번째 칸' 주소를 가리키게 됩니다.
    struct Employee *team = (struct Employee *)malloc(sizeof(struct Employee) * n);

    if (team == NULL) {
        printf("시스템 메모리가 부족하여 팀을 생성할 수 없습니다.\n");
        return 1;
    }

    // 2. 데이터 입력 (배열처럼 사용)
    // 포인터가 가리키는 주소가 배열의 시작점이므로, team[i] 형식을 쓸 수 있습니다.
    for (int i = 0; i < n; i++) {
        team[i].id = 100 + i;
        team[i].performance = 0.0f; // 초기 성능 점수
        printf("사원 %d 생성 완료 (ID: %d)\n", i + 1, team[i].id);
    }

    // 3. 포인터 연산을 통한 데이터 수정 실습
    // team[1]은 사실 *(team + 1)과 같습니다.
    (team + 1)->performance = 95.5f; // 두 번째 직원의 성과 입력

    printf("\n--- 팀 정보 출력 ---\n");
    for (int i = 0; i < n; i++) {
        printf("사원 ID: %d, 성과 점수: %.1f\n", team[i].id, team[i].performance);
    }

    // 4. 자원 반납 (CTO의 의무)
    // team이 가리키는 메모리 덩어리 전체를 해제합니다.
    free(team);
    team = NULL;

    printf("\n팀 데이터가 안전하게 메모리에서 소멸되었습니다.\n");

    return 0;
}