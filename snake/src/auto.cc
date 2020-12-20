#include "auto.h"

#include <iostream>
using namespace std;
extern Node food;
extern int g_snake_direction;
extern int g_enter_direction;
void Auto(queue<Node>& snake) {                               //憨憨行为
  if (snake.back().y == food.y && snake.back().x < food.x &&  //反向
      g_snake_direction == 'a')
    g_enter_direction = 'w';
  else if (snake.back().y == food.y && snake.back().x > food.x &&
           g_snake_direction == 'd')
    g_enter_direction = 's';
  else if (snake.back().x == food.x && snake.back().y > food.y &&
           g_snake_direction == 's')
    g_enter_direction = 'a';
  else if (snake.back().x == food.x && snake.back().y < food.y &&
           g_snake_direction == 'w')
    g_enter_direction = 'd';
  else if (snake.back().x <= food.x && snake.back().y <= food.y) {  //左上角
    if (g_snake_direction == 'a' || g_snake_direction == 's') {
      g_enter_direction = 's';
      if (snake.back().y == food.y) g_enter_direction = 'd';
    } else if (g_snake_direction == 'w' || g_snake_direction == 'd') {
      g_enter_direction = 'd';
      if (snake.back().x == food.x) g_enter_direction = 's';
    }
  } else if (snake.back().x >= food.x && snake.back().y < food.y) {  //右上角
    if (g_snake_direction == 'd' || g_snake_direction == 's') {
      g_enter_direction = 's';
      if (snake.back().y == food.y) g_enter_direction = 'a';
    } else if (g_snake_direction == 'w' || g_snake_direction == 'a') {
      g_enter_direction = 'a';
      if (snake.back().x == food.x) g_enter_direction = 's';
    }
  } else if (snake.back().x <= food.x && snake.back().y > food.y) {  //左下角
    if (g_snake_direction == 'a' || g_snake_direction == 'w') {
      g_enter_direction = 'w';
      if (snake.back().y == food.y) g_enter_direction = 'd';
    } else if (g_snake_direction == 's' || g_snake_direction == 'd') {
      g_enter_direction = 'd';
      if (snake.back().x == food.x) g_enter_direction = 'w';
    }
  } else if (snake.back().x >= food.x && snake.back().y >= food.y) {  //右下角
    if (g_snake_direction == 'd' || g_snake_direction == 'w') {
      g_enter_direction = 'w';
      if (snake.back().y == food.y) g_enter_direction = 'a';
    } else if (g_snake_direction == 's' || g_snake_direction == 'a') {
      g_enter_direction = 'a';
      if (snake.back().x == food.x) g_enter_direction = 'w';
    }
  }
}