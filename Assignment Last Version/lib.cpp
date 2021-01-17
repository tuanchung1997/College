#include "lib.h"

void setTextColor(int color) {
	//Thay doi thuoc tinh cua text tren console (mau chu)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void noCursorType() {
	CONSOLE_CURSOR_INFO info;
	//an con tro nhay tren console
	info.bVisible = FALSE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void CenterScreen() {
	HWND ConsoleWindow;
	ConsoleWindow = GetForegroundWindow();

	//Getting the desktop handle and rectangule
	HWND   hwndScreen;
	RECT   rectScreen;
	hwndScreen = GetDesktopWindow();
	GetWindowRect(hwndScreen, &rectScreen);

	//Set windows size(see the width problem)
	SetWindowPos(ConsoleWindow, NULL, 0, 0, 490, 500, SWP_SHOWWINDOW);

	// Get the current width and height of the console
	RECT rConsole;
	GetWindowRect(ConsoleWindow, &rConsole);
	int Width = rConsole.left = rConsole.right;
	int Height = rConsole.bottom - rConsole.top;

	//caculate the window console to center of the screen	
	int ConsolePosX;
	int ConsolePosY;
	ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
	ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
	SetWindowPos(ConsoleWindow, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);
}

void Info() {
	string a[4] = { "CAO DANG THUC HANH FPT POLYTECHNIC", "LAB 05",
		"Student: Chung Nguyen Anh Tuan", "Student ID: PS15194" };

	setTextColor(DARK_GREEN_COLOR);

	ShowMiniMenu(4, a);

	setTextColor(WHITE_COLOR);
}

void ShowMiniMenu(int n, string array[]) {
	int space;

	for (int i = 0; i < 57; i++) {
		if (i == 0)
			printf("   .");
		else
			printf(".");
	}

	printf("\n");

	for (int i = 0; i < n; i++) {
		space = (57 - array[i].length() - 3) / 2;
		printf("   .");
		Space(space);
		cout << array[i];
		space = 60 - 5 - space - array[i].length();
		Space(space);
		printf(".\n");
	}

	for (int i = 0; i < 57; i++) {
		if (i == 0)
			printf("   .");
		else
			printf(".");
	}

	printf("\n");
}

void Sepa(int n) {
	for (int i = 0; i < n; i++)
		printf("-");

	printf("\n");
}

void Separator() {
	setTextColor(DARK_GREEN_COLOR);

	for (int i = 0; i < 57; i++) {
		if (i == 0)
			printf("   -");
		else if (i == 57 - 1)
			printf("-\n");
		else
			printf("-");
	}

	setTextColor(WHITE_COLOR);
}

void Space(int n) {
	for (int i = 0; i < n; i++)
		printf(" ");
}

void ShowMenu(int n, string array[]) {
	stringstream ss;

	for (int i = 0; i < n; i++) {
		ss << "F" << i + 1 << " - " << array[i];
		array[i] = ss.str();
		ss.str("");
	}

	for (int i = 0; i < 57; i++) {
		if (i == 0)
			printf("   .");
		else if (i == 57 - 1)
			printf(".\n");
		else if (i == 27)
			printf("M");
		else if (i == 28)
			printf("E");
		else if (i == 29)
			printf("N");
		else if (i == 30)
			printf("U");
		else
			printf(".");
	}

	int max = array[0].length();

	for (int i = 1; i < n; i++) {
		if (array[i].length() > max)
			max = array[i].length();
	}

	max = (57 - max) / 2 - 1;

	for (int i = 0; i < n; i++) {
		printf("   .");
		Space(max);
		cout << array[i];
		Space(59 - 4 - max - array[i].length());
		printf(".\n");
	}

	for (int i = 0; i < 57; i++) {
		if (i == 0)
			printf("   .");
		else
			printf(".");
	}

	printf("\n");

	printf("   > Moi chon chuc nang: Nhan F%d - F%d tren ban phim\n   > ", 1, n);
}

void Menu(string a[], int n, void (*p)(int, string[])) {
	setTextColor(DARK_GREEN_COLOR);

	p(n, a);

	setTextColor(WHITE_COLOR);
}

string marquee(string& text, size_t limit) {
	//cho bien tmp = text
	string tmp = text;
	//xoa ky tu dau tien
	text.erase(0, 1);
	//them ky tu dau tien vao cuoi chuoi
	text += tmp[0];

	return text.substr(0, limit);
}

void marqueeTitle(atomic<bool>& on, atomic<bool>& cont) {
	string title = "  ..:: PS15194 | CHUNG NGUYEN ANH TUAN | ASSIGNMENT | FPT POLYTECHNIC ::..  ";
	while (cont) {
		while (on) {
			SetConsoleTitleA(marquee(title, 45).c_str());

			Sleep(300);
		}
	}
}

string ThoundsandSeparator(string number){
	char thousandSep = ',';

	//lay chieu dai cua so
	int len = number.length();
	//dat dau ',' sau 3 ky tu so
	int dlen = 3;

	while (len > dlen) {
		//chen dau ',' sau 3 ky tu so tu phai qua trai
		number.insert(len - dlen, 1, thousandSep);
		//1,000,000
		//tang dlen len 4, vi co them dau ','
		dlen += 4;
		//tong chieu dai chuoi so tang 1 vi co them dau ','
		len += 1;
	}
	return number;
}

void gotoxy(int x, int y){
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y }; //x chieu ngang, y chieu doc
	SetConsoleCursorPosition(h, c); //Di chuyen con tro den toa do c
}

void BankInfo() {
	clrscr;

	string bank[5] = { "Kinh chao quy khach!", "Hien tai ngan hang Poly dang co uu dai vay tieu dung",
		"voi lai suat 5%/thang, ky han 12 thang", "Quy khach co the nhap so tien can vay",
		"Chung toi se tinh toan qua trinh thanh toan chi tiet." };

	printf("\n\n\n\n\n\n\n\n\n");

	Menu(bank, 5, ShowMiniMenu);

	Space(22);

	printf("> Nhan Enter\n");

	getch();
}

void PolyLottInfo() {
	clrscr;

	string lott[5] = { "Poly Lott 2/15 xin chao,", "The le tham gia",
		"Ban se chon 02 so bat ky tu 01 den 15", "Dat giai dac biet neu trung 02 so",
		"va giai khuyen khich neu trung 01 so" };

	printf("\n\n\n\n\n\n\n\n\n");

	Menu(lott, 5, ShowMiniMenu);

	Space(22);

	printf("> Nhan Enter\n");

	getch();
}

void ShowKaraokeInfo() {
	clrscr;

	string func[1] = { "CHUONG TRINH QUAN LY PHONG KARAOKE" };

	Menu(func, 1, ShowMiniMenu);

	Separator();
}