#pragma once

typedef struct EnemyNPC_Info {
    int speed;
    posStruct pos;
    int id;
    struct EnemyNPC_Info* next;
} EnemyNPC_Info;