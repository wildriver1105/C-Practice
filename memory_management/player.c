#include <stdio.h>

struct Player {
    int level;
    int hp;
};

void level_up(struct Player *p) {
    p->level += 1;
    p->hp += 10;
}

int main() {
    struct Player cto = {1, 100};

    printf("레벨업 전: Level %d, HP %d\n", cto.level, cto.hp);

    level_up(&cto);

    printf("레벨업 후: Level %d, HP %d\n", cto.level, cto.hp);

    return 0;
}