#pragma once
#include<windows.h>
#include<time.h>
#include<conio.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define MAP_MODE "■"
#define SNAKE_MODE "■"
#define FOOD_MODE "●"
#define MAP_WIDTH 70
#define MAP_HEIGHT 30
#define INIT_LEN 3
#define false 0
#define true 1
#define LIGHT_GREEN   "\033[1;32m"
#define RED           "\033[0;32;31m"
#define WHITE         "\033[1;37m"
#define LIGHT_BLUE    "\033[1;34m"

struct  Food {
    int xpoint;
    int ypoint;
}food;

char g_game_map[30][72] = {
    "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■                                                                  ■\n",
    "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n",
};

int g_enter_direction = 'a';

int g_snake_direction = 'a';

int g_is_produce_food = 1;

int g_num_of_food_eaten = 0;

int g_is_del_tail = 1;

COORD g_position;

HANDLE g_out;

void MoveCursor(int xpoint, int ypoint) {
    g_position.X = xpoint * 2;
    g_position.Y = ypoint;
	g_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(g_out, g_position);
}

void CreateFood() {
    if (g_is_produce_food) {
        food.xpoint = rand() % 33 + 1;
        food.ypoint = rand() % 28 + 1;
        MoveCursor(food.xpoint, food.ypoint);
        printf(RED FOOD_MODE WHITE);
        g_is_produce_food = 0;
    }
}

void GameInit(struct Snake* snake) {
    //data
    g_enter_direction = 'a';
    g_snake_direction = 'a';
    g_is_produce_food = 1;
    g_num_of_food_eaten = 0;
    g_is_del_tail = 1;

    int xpoint = rand() % 21 + 6;
    int ypoint = rand() % 16 + 6;

    InsertNode(snake, xpoint + 2, ypoint);
    InsertNode(snake, xpoint + 1, ypoint);
    InsertNode(snake, xpoint, ypoint);

    //print
    pmove = snake->next;
    while (pmove) {
        MoveCursor(pmove->xpoint, pmove->ypoint);
        printf(WHITE SNAKE_MODE);
        pmove = pmove->next;
    }
}

void GameMap() {
    system("color 09");
    system("mode con cols=70 lines=31");
    for (int i = 0; i < 30; i++)
        printf(g_game_map[i]);
}

void DelTail(struct Snake** snake) {
    if (g_enter_direction != 'w' &&
        g_enter_direction != 'W' &&
        g_enter_direction != 's' &&
        g_enter_direction != 'S' &&
        g_enter_direction != 'a' &&
        g_enter_direction != 'A' &&
        g_enter_direction != 'd' &&
        g_enter_direction != 'D' )
        return;
    struct Snake* tem = *snake;
    struct Snake* tem1 = *snake;
    while (tem->next) {
        tem1 = tem;
        tem = tem->next;
    }

    MoveCursor(tem->xpoint, tem->ypoint);
    printf("  ");

    free(tem);
    tem = NULL;
    tem1->next = NULL;
    MoveCursor(food.xpoint, food.ypoint);
    printf(RED FOOD_MODE WHITE);
}

void SnakeGrowUp(struct Snake* snake) {
    pmove = snake->next;
    if (food.xpoint == pmove->xpoint && food.ypoint == pmove->ypoint) {
        g_num_of_food_eaten++;
        g_is_produce_food = 1;
        g_is_del_tail = 0;
    }
}

void MoveSnake(struct Snake* snake) {

    if (_kbhit()) {
        fflush(stdin);
        g_enter_direction = _getch();
    }
    int xpoint, ypoint;
    //snake head
    pmove = snake->next;
    switch (g_enter_direction) {
    case 'W':
    case 'w':  
        //No retreat at all !
        if (g_snake_direction != 's' && g_snake_direction != 'S') {
            g_snake_direction = g_enter_direction;
            xpoint = pmove->xpoint;
            ypoint = pmove->ypoint - 1;
            InsertNode(snake, xpoint, ypoint);
        }
        else {
            xpoint = pmove->xpoint;
            ypoint = pmove->ypoint + 1;
            InsertNode(snake, xpoint, ypoint);
        }break;
    case 'S':
    case 's':
        if (g_snake_direction != 'w' && g_snake_direction != 'W') {
            g_snake_direction = g_enter_direction;
            xpoint = pmove->xpoint;
            ypoint = pmove->ypoint + 1;
            InsertNode(snake, xpoint, ypoint);
        }
        else {
            xpoint = pmove->xpoint;
            ypoint = pmove->ypoint - 1;
            InsertNode(snake, xpoint, ypoint);
        }break;
    case 'D':
    case 'd':
        if (g_snake_direction != 'a' && g_snake_direction != 'A') {
            g_snake_direction = g_enter_direction;
            xpoint = pmove->xpoint + 1;
            ypoint = pmove->ypoint;
            InsertNode(snake, xpoint, ypoint);
        }
        else {
            xpoint = pmove->xpoint - 1;
            ypoint = pmove->ypoint;
            InsertNode(snake, xpoint, ypoint);
        }break;
    case 'A':
    case 'a':
        if (g_snake_direction != 'd' && g_snake_direction != 'D') {
            g_snake_direction = g_enter_direction;
            xpoint = pmove->xpoint - 1;
            ypoint = pmove->ypoint;
            InsertNode(snake, xpoint, ypoint);
        }
        else {
            xpoint = pmove->xpoint + 1;
            ypoint = pmove->ypoint;
            InsertNode(snake, xpoint, ypoint);
        }break;
    }
    pmove = snake->next;
    MoveCursor(pmove->xpoint, pmove->ypoint);
    printf(SNAKE_MODE);

    if (g_is_del_tail)
       DelTail(&snake);
    g_is_del_tail = 1;
}

int IsSnakeDie(struct Snake* snake) {
    pmove = snake->next;
    //wall
    if (pmove->xpoint == 0 || pmove->xpoint * 2 == MAP_WIDTH - 2 ||
        pmove->ypoint == 0 || pmove->ypoint == MAP_HEIGHT - 1) {
        return 0;
    }
    //body
    int xpoint = pmove->xpoint;
    int ypoint = pmove->ypoint;
    pmove = pmove->next->next;

    while (pmove) {
        if (pmove->xpoint == xpoint && pmove->ypoint == ypoint)
            return 0;
        pmove = pmove->next;
    }
    return 1;
}

