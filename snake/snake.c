/**********************
 * IAN
 * 2020.6.1
 ********************/

#include<stdio.h>
#include<stdlib.h>
#include"snake-data.h"
#include"snake.h"
#include"snake-interface.h"

int main(){
    int speed;
    int* pspeed = &speed;

    //hide CURSOR
    HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(h_out, &cursor_info);
    cursor_info.bVisible = false;
    SetConsoleCursorInfo(h_out, &cursor_info);

    srand((unsigned int)time(NULL));

    //playing
    do {
        Welcome(pspeed);
        struct Snake* snake = CreateList();
        GameMap();
        GameInit(snake);
        while (1) {
            //speed 
            Sleep(1000 / speed);
            CreateFood();
            MoveSnake(snake);
            SnakeGrowUp(snake);
            if (!IsSnakeDie(snake)) {
                break;
            }
        }
        FreeData(snake);
    } while (GameOver(speed));

    return 0;
}
