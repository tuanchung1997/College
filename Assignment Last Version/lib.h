#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <thread>
#include <math.h>
#include <string>
#include <iomanip>
#include <ctime>

#define beep MessageBeep(MB_ICONINFORMATION)
#define beep_err MessageBeep(MB_ICONERROR)
#define clrscr system("cls");
#define MAX 100

#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15

#define ESC					27
#define HOME				71
#define F1					59
#define F2					60
#define F3					61
#define F4					62
#define F5					63
#define F6					64
#define F7					65
#define F8					66
#define F9					67

using namespace std;

void gotoxy(int x, int y);
string ThoundsandSeparator(string number);
string marquee(string& text, size_t limit);
void marqueeTitle(atomic<bool>& on, atomic<bool>& cont);
void CenterScreen();
void Menu(string a[], int n, void(*p)(int, string[]));
void Separator();
void Space(int n);
void ShowMenu(int n, string array[]);
void ShowMiniMenu(int n, string array[]);
void Info();
void setTextColor(int color);
void noCursorType();
void Sepa(int n);
void BankInfo();
void PolyLottInfo();
void ShowKaraokeInfo();
