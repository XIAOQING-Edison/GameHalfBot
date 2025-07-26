#ifndef _IPC_WINDOW_H_
#define _IPC_WINDOW_H_
#include "../Global/public.h"
bool RegisterMessageWindow(HINSTANCE hInst,STRING &szClassName);
bool UnRegisterWindow(HINSTANCE hInst);
WPARAM MessageLoop(HINSTANCE hInst);
HWND CreateMessageWindow(HMODULE hModule,STRING &title,STRING &szClassName,int w,int h);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif