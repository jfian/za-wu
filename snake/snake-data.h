#pragma once

struct Snake {
    int xpoint;
    int ypoint;
    struct Snake* next;
};


struct Snake* pmove;

struct Snake* CreateList() {
    struct Snake* snake = (struct Snake*)malloc(sizeof(struct Snake));
    snake->next = NULL;
    return snake;
}

struct Snake* CreateNode(int xpoint,int ypoint) {
    struct Snake* new_body = (struct Snake*)malloc(sizeof(struct Snake));
    new_body->xpoint = xpoint;
    new_body->ypoint = ypoint;
    new_body->next = NULL;
    return new_body;
}

void InsertNode(struct Snake* snake, int xpoint, int ypoint) {
    struct Snake* new_body = CreateNode(xpoint, ypoint);
    new_body->next = snake->next;
    snake->next = new_body;
}

void FreeData(struct Snake* snake) {
    struct Snake* p_free = NULL;
    while (snake) {
        p_free = snake;
        snake = snake->next;
        free(p_free);
        p_free = NULL;
    }
}