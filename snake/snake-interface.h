#pragma once
#include<math.h>

int GameOver(int speed) {
    system("cls");
    char sel = '0';
    GameMap();
    MoveCursor((MAP_WIDTH - 42) / 2, MAP_HEIGHT / 3 - 1);
    printf(RED "Game    Over!"WHITE);

    MoveCursor((MAP_WIDTH - 49) / 2, MAP_HEIGHT / 3 + 1);
    printf(LIGHT_GREEN " name:    \t    \t    "WHITE"NULL");

    MoveCursor((MAP_WIDTH - 49) / 2, MAP_HEIGHT / 3 + 3);
    printf(LIGHT_GREEN" rank:    \t    \t    "WHITE"NULL");

    MoveCursor((MAP_WIDTH - 49) / 2, MAP_HEIGHT / 3 + 5);

    printf(LIGHT_GREEN" score:    \t    \t    "WHITE"%.2f", (double)g_num_of_food_eaten * log((speed - 4.0) + 1.0));

    MoveCursor((MAP_WIDTH - 54) / 2, MAP_HEIGHT - 12);
    printf(RED" <0.exit>     \t\t    <1.again>"WHITE);

    do {
        sel = _getch();
        if (sel == '1') {
            return 1;
        }
        else if (sel == '0')
            exit(0);
    } while (1);
    return 0;
}

void Setting(int* pspeed) {
    int speed;
    while(1){
        system("cls");
        printf("\n\n\n\n\n\n\n   \t   \t   speed<1-20>: ");
        scanf("%d", &speed);
        if (speed >= 1 && speed <= 20) {
            *pspeed = speed + 5;
            return;
        }
        else {
            MessageBox(NULL, TEXT("Please enter the correct option!"), TEXT("Greedy Snake"), MB_OK | MB_ICONERROR);
        }
    }
}

void Welcome(int *pspeed) {
    system("mode con cols=60 lines=18");
    char sel;
    printf("\n\n\n\t********************************************\n");
    printf("\t*                                          *\n");
    printf("\t*              Greedy  Snake               *\n");
    printf("\t*                                          *\n");
    printf("\t*        1.simple          2.medium        *\n");
    printf("\t*                                          *\n");
    printf("\t*        3.difficult       4.setting       *\n");
    printf("\t*                                          *\n");
    printf("\t*                                          *\n");
    printf("\t* V1.3                              By IAN *\n");
    printf("\t********************************************\n");
    while (1) {
        sel = _getch();
        if (sel >= '0' && sel <= '4') {
            switch (sel) {
            case '1':*pspeed = 8; return;
            case '2':*pspeed = 10; return;
            case '3':*pspeed = 25; return;
            case '4':; Setting(pspeed);return;
            }
        }
        else {
            MessageBox(NULL, TEXT("Please enter the correct option!"), TEXT("Greedy Snake"), MB_OK | MB_ICONERROR);
        }
    }
}
