#include "main.h"

#include <conio.h>

#include <iostream>
using std::cin;
using std::cout;

int main() {
  int num;
  char name[100];
  DWORD sp;
  char temp;
  system("mode con cols=30 lines=20");
  system("color f0");

  if (MessageBoxA(NULL, "勿滥用！！！", "v0.01", MB_YESNO | MB_ICONWARNING) == IDNO)
    exit(0);
  do {
    temp = 'N';
    system("cls");
    fflush(stdin);
    cout << "好友: ";
    cin >> name;
    cout << "次数: ";
    cin >> num;
    cout << "速度(s>0): ";
    cin >> sp;
    if (MySent(num, name, sp)) {
      cout << "Do you want do it again?<y/n>";
      temp = _getch();
    } else {
      MessageBoxA(NULL, "发送失败！！！", "v0.01", MB_OK);
      temp = 'Y';
    }
  } while (temp == 'Y' || temp == 'y');
  return 0;
}