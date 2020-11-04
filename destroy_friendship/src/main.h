#ifndef MAIN_H
#define MAIN_H
#include <windows.h>
bool MySent(int& num, const char name[], DWORD sp) {
  if (sp <= 0) {
    MessageBox(NULL, TEXT("速度应为正数！"), TEXT("呵~"), MB_OK | MB_ICONERROR);
    return false;
  }
  if (MessageBox(NULL, TEXT("复制内容（复制完再关闭此窗口，勿使用快捷键）"),
                 TEXT("呵~"), MB_YESNO) == IDYES) {
    HWND H = FindWindowA(0, name);  //找到对话框句柄
    if (H) {
      for (; num > 0; num--) {
        SendMessageA(H, WM_PASTE, 0, 0);  //粘贴先前复制的内容
        SendMessageA(H, WM_KEYDOWN, VK_RETURN,
                     0);   //发送！
        Sleep(1000 / sp);  //控制速度
      }
    } else {
      MessageBox(NULL, TEXT("找不到窗口！"), TEXT("WTF"), MB_ICONWARNING);
      return false;
    }
  } else
    return false;
  return true;
}
#endif