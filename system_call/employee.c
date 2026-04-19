#include <stdio.h>

struct Employee {
    int id;
    char grade;
    float salary;
};

// Struct의 주소를 받아서 내용을 수정하는 함수
void update_salary(struct Employee *e, float new_salary) {
    e->salary = new_salary;
}

int main() {
    struct Employee cto = {1, 'A', 1000.0f};

    printf("수정 전 연봉: %.2f\n", cto.salary);

    // 주소를 넘겨줍니다
    update_salary(&cto, 1000000.0f);

    printf("수정 후 연봉, %.2f\n", cto.salary);
    printf("구조체 전체 크기: %lu 바이트\n", sizeof(cto));

    return 0;
}