#include "lib.h"

struct TIME {
	int hour;
	int minute;
	int second;
};

struct Student {
	string id;
	string name;
	string classid;
	string grade;
	float score;
};

struct Fraction {
	int TS;
	int MS;
};

bool isInteger(float number) {
	//Neu so thuc - (int)so thuc = 0 thi la so nguyen
	if (number - (int)number == 0)
		return true;

	return false;
}

bool isPrime(float number) {
	//Neu so x < 2 => Khong phai so nguyen to
	//Trong khoang tu [2, sqrt(x)] neu x co bat ky uoc nao => Khong phai so nguyen to
	int x = (int)number;

	if (x < 2)
		return false;

	for (int i = 2; i <= (int)sqrt(x); i++)
		if (x % i == 0)
			return false;

	return true;
}

bool isSquare(float number) {
	//Neu (int)binh phuong can bac 2 cua x bang x => La so chinh phuong
	int x = (int)number;

	if ((int)sqrt(x) * (int)sqrt(x) == x)
		return true;

	return false;
}

bool CheckNumber(float number, bool(*p)(float)) {
	//Dung con tro ham (*p) goi cac ham kiem tra tren de xu ly
	if ((*p)(number))
		return true;

	return false;
}

void inputfloat(float& number) {
	//Khong cho nguoi dung nhap ky tu khac (so)
	while (true) {
		printf("   > Nhap so can kiem tra: ");

		if (scanf("%f", &number) == 0) {
			fgetc(stdin);
			printf("   Loi nhap du lieu\n");
		}
		else
			break;
	}
}

void CheckInteger() {
	clrscr;

	string a[1] = { "KIEM TRA SO NGUYEN" };
	Menu(a, 1, ShowMiniMenu);

	//Cap phat dong
	float* number = new float;

	if (number != NULL) {
		inputfloat(*number);

		Separator();

		printf("   Ket qua: \n");

		if (CheckNumber(*number, isInteger))
			printf("   %d la so nguyen.\n", (int)*number);
		else
			printf("   %.2f khong phai so nguyen.\n", *number);

		delete number; //tra vung nho da cap phat cho he dieu hanh
		number = NULL; //tro den NULL de tranh ro ri du lieu
	}
	else {
		printf("   > Cap phat bo nho that bai!\n");
		exit(101);
	}
}

void CheckPrime() {
	clrscr;

	string a[1] = { "KIEM TRA SO NGUYEN TO" };
	Menu(a, 1, ShowMiniMenu);

	float* number = new float;

	if (number != NULL) {
		inputfloat(*number);

		Separator();

		printf("   Ket qua: \n");

		if (CheckNumber(*number, isPrime))
			printf("   %d la so nguyen to.\n", (int)*number);
		else
			printf("   %d khong phai so nguyen to.\n", (int)*number);

		delete number;
		number = NULL;
	}
	else {
		printf("   > Cap phat bo nho that bai!\n");
		exit(101);
	}
}

void CheckSquare() {
	SetConsoleTitle(TEXT("Kiem tra so chinh phuong"));

	clrscr;

	string a[1] = { "KIEM TRA SO CHINH PHUONG" };
	Menu(a, 1, ShowMiniMenu);

	float* number = new float;

	if (number != NULL) {
		inputfloat(*number);

		Separator();

		printf("   Ket qua: \n");

		if (CheckNumber(*number, isSquare))
			printf("   %d la so chinh phuong (%dx%d).\n", (int)*number, (int)sqrt(int(*number)), (int)sqrt(int(*number)));
		else
			printf("   %d khong phai so chinh phuong.\n", (int)*number);

		delete number;
		number = NULL;
	}
	else {
		printf("   > Cap phat bo nho that bai!\n");
		exit(101);
	}
}

void F1_Process() {
	clrscr;

	SetConsoleTitle(TEXT("KIEM TRA SO NGUYEN"));

	string func[1] = { "CHUONG TRINH KIEM TRA SO NGUYEN" };

	Menu(func, 1, ShowMiniMenu);

	Separator();

	string func2[3] = { "Kiem tra so nguyen","Kiem tra so nguyen to",
		"Kiem tra so chinh phuong" };

	Menu(func2, 3, ShowMenu);

Func1:
	while (!kbhit());
	char n = getch();

	switch (n) {
	case F1: {
		beep;
		CheckInteger();
		break;
	}
	case F2: {
		beep;
		CheckPrime();
		break;
	}
	case F3: {
		beep;
		CheckSquare();
		break;
	}
	default: {
		beep_err;
		goto Func1;
	}
	}
}

void Function1() {
	char key;

	while (true) {
		F1_Process();

		SetConsoleTitle(TEXT("Dang chuyen huong..."));

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tinh tiep\n   > ");

	Function1:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto Function1;
	}
}

int GCD(int number1, int number2) {
	//Giai thuat Euclid
	//return b neu so du r = 0
	//Neu r khac 0 tim GCD(b, r)
	if (number2 == 0)
		return number1;

	return(GCD(number2, number1 % number2));

	//Khu de quy
	/*
	int tmp;

	while(number2 != 0){
		tmp = number1 % number2;
		number1 = number2;
		number2 = tmp;
	}

	return number1;

	Hoac su dung ham co san __gcd(number1, number2) cua thu vien <Algorithm>
	*/
}

int LCM(int number1, int number2) {
	//Cong thuc: LCM = (a*b)/GCD(a, b)
	return (number1 * number2) / GCD(number1, number2);
}

int GCDorLCM(int number1, int number2, int(*p)(int, int)) {
	//Su dung con tro ham (*p) de goi GCD va LCM
	return (*p)(number1, number2);
}

void inputint(int& number) {
	while (true) {
		printf("   > Nhap so: ");
		if (scanf("%d", &number) == 0) {
			fgetc(stdin);
			printf("   Loi nhap du lieu\n");
		}
		else
			break;
	}
}

void Function2() {
	char key;
	while (true) {
		clrscr;

		SetConsoleTitle(TEXT("UCLN & BCNN"));

		string func[2] = { "CHUONG TRINH TIM UCLN", "VA BCNN" };

		Menu(func, 2, ShowMiniMenu);

		Separator();

		int* number1 = new int;
		int* number2 = new int;

		if (number1 != NULL && number2 != NULL) {
			do {
				inputint(*number1);
				inputint(*number2);

				if (*number1 == 0 && *number2 == 0) {
					beep_err;
					printf("   > Loi nhap du lieu!\n");
				}
			} while (*number1 == 0 && *number2 == 0);

			Separator();

			printf("   Ket qua:\n");

			int gcd = GCDorLCM(*number1, *number2, GCD), lcm = GCDorLCM(*number1, *number2, LCM);

			printf("   UCLN(%d, %d): %d\n", *number1, *number2, gcd);
			printf("   BCNN(%d, %d): %d\n", *number1, *number2, lcm);

			delete number1;
			delete number2;
			number1 = number2 = NULL;
		}
		else {
			printf("   > Cap phat bo nho that bai!\n");
			exit(101);
		}
		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	GCDLCM:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto GCDLCM;
	}
}

//XU LY THOI GIAN
void Time_Process(int h1, int m1, int s1, int h2, int m2, int s2,
	int& hour, int& minute, int& second) {
	//Ap dung cong thuc tru thoi gian
	//Doi tat ca ra giay
	//Roi doi thanh gio hat thuc te
	//Tham chieu: hour, minute, second
	if (s2 < s1) {
		second = s2 + 60 - s1;
		m2--;
	}
	else
		second = s2 - s1;

	if (m2 < m1) {
		minute = m2 + 60 - m1;
		h2--;
	}
	else
		minute = m2 - m1;

	hour = h2 - h1;
}

//NHAP GIO HAT
void InputTime(int& h, int& m, int& s) {
	do {
		while (true) {
			printf("   > Gio: ");
			if (scanf("%d", &h) == 0) {
				fgetc(stdin);
				printf("   Loi nhap du lieu\n");
			}
			else
				break;
		}

		while (true) {
			printf("   > Phut: ");
			if (scanf("%d", &m) == 0) {
				fgetc(stdin);
				printf("   Loi nhap du lieu\n");
			}
			else
				break;
		}

		while (true) {
			printf("   > Giay: ");
			if (scanf("%d", &s) == 0) {
				fgetc(stdin);
				printf("   Loi nhap du lieu\n");
			}
			else
				break;
		}

		if (h < 12 || h > 23 || m > 59 || m < 0 ||
			s > 59 || s < 0) {
			beep_err;
			printf("   > Loi nhap lieu!\n");
		}
	} while (h < 12 || h > 23 || m > 59 || m < 0 ||
		s > 59 || s < 0);
}

void Function3() {
	char key;

	while (true) {
		SetConsoleTitle(TEXT("QUAN LY PHONG KARAOKE"));

		ShowKaraokeInfo();

		TIME begin, end;

		//Nhap gio hat
		printf("   Nhap gio hat (12:00:00 den 22:59:59)\n");
		printf("   > Bat dau: \n");

		InputTime(begin.hour, begin.minute, begin.second);

		Separator();

		printf("   > Ket thuc: \n");

		do {
			InputTime(end.hour, end.minute, end.second);

			if (end.hour <= begin.hour) {
				beep_err;
				printf("   > Loi nhap du lieu!\n");
			}
		} while (end.hour <= begin.hour);

		//Xu ly thoi gian
		int hour, minute, second, hour_process;

		//chuyen doi gio sang giay
		Time_Process(begin.hour, begin.minute, begin.second, end.hour, end.minute, end.second, hour, minute, second);

		hour_process = hour;

		//Neu so phut lon hon 30 thi lam tron thanh 1 gio
		if (minute >= 30) {
			hour_process++;
		}

		//Xu ly
		int flag = 0; //Co hieu gio hat bat dau luc 14, 15, 16, 17 (Giam 10% tong bill)
		double total = 0.0;

		if (begin.hour == 14 || begin.hour == 15 || begin.hour == 16 || begin.hour == 17)
			flag = 1; //Dang co chuong trinh giam gia 

		ShowKaraokeInfo();

		printf("   Tong gio hat: %d (Thoi gian thuc: %d:%d:%d)\n", hour_process, hour, minute, second);

		if (flag == 1) {
			//Xu ly giam 10% gio vang + giam 30% cho gio hat thu 4 tro di
			if (hour_process > 4) {
				printf("   Khuyen mai: 10%% Gio vang\n");
				printf("   Khuyen mai: Giam 30%% tu gio thu 4\n");
			}
			else
				//Chi ap dung giam gio vang
				printf("   Khuyen mai: 10%% Gio vang\n");
		}
		else {//Khong giam gio vang
			if (hour_process > 4)
				//Giam 30% cho gio thu 4
				printf("   Khuyen mai: Giam 30%% tu gio thu 4\n");
			else
				//Khong khuyen mai
				printf("   Khong co khuyen mai\n");
		}

		double total_ck = 0.0;

		//Xu ly
		if (flag != 1) {
			if (hour_process < 4)
				total += hour_process * 150000;
			else {
				total += 3 * 150000 + (hour_process - 3) * 150000 * 0.7;
				total_ck = (hour_process * 150000) - total;
			}
		}
		else {
			if (hour_process < 4)
				total += hour_process * 150000 * 0.9;
			else {
				total += (3 * 150000 + (hour_process - 3) * 150000 * 0.7) * 0.9;
				total_ck = (hour_process * 150000) - (3 * 150000 + (hour_process - 3) * 150000 * 0.7) * 0.9;
			}
		}

		Separator();

		string t_otal = to_string((int)total);
		string t_otal_ck = to_string((int)total_ck);
		string total_r = to_string((int)hour_process * 150000);

		printf("   Tong tien : ");
		fputs(ThoundsandSeparator(total_r).c_str(), stdout);
		printf(" (VND)\n");

		printf("   Chiet khau: ");
		fputs(ThoundsandSeparator(t_otal_ck).c_str(), stdout);
		printf(" (VND)\n");

		Separator();

		printf("   Thanh tien: ");
		fputs(ThoundsandSeparator(t_otal).c_str(), stdout);
		printf(" (VND)\n");

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	Karaoke:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto Karaoke;
	}
}

void Function4() {
	char key;

	while (true) {
		clrscr;

		SetConsoleTitle(TEXT("TINH TIEN DIEN"));

		string func[1] = { "CHUONG TRINH TINH TIEN DIEN" };

		Menu(func, 1, ShowMiniMenu);

		Separator();

		int* csc = new int;
		int* csm = new int;

		int cs, total = 0;

		//NHAP CHI SO DIEN (MOI & CU)
		if (csc != NULL && csm != NULL) {
			while (true) {
				printf("   > Nhap chi so cu: ");
				if (scanf("%d", &*csc) == 0) {
					fgetc(stdin);
					printf("   Loi nhap du lieu\n");
				}
				else
					break;
			}

			do {
				while (true) {
					printf("   > Nhap chi so moi: ");
					if (scanf("%d", &*csm) == 0) {
						fgetc(stdin);
						printf("   Loi nhap du lieu\n");
					}
					else
						break;
				}

				if (*csm < *csc) {
					beep_err;
					printf("   Chi so moi phai lon hon chi so cu!\n");
				}
			} while (*csm < *csc);

			clrscr;

			//CHISO CSM - CSC
			cs = *csm - *csc;

			//GIA DIEN /1kWh
			int s1 = 1678, s2 = 1734, s3 = 2014, s4 = 2536, s5 = 2834, s6 = 2927;

			//Xu ly
			if (cs <= 50)
				total += cs * s1;
			else if (cs <= 100)
				total += 50 * s1 + (cs - 50) * s2;
			else if (cs <= 200)
				total += 50 * s1 + 50 * s2 + (cs - 100) * s3;
			else if (cs <= 300)
				total += 50 * s1 + 50 * s2 + 100 * s3 + (cs - 200) * s4;
			else if (cs <= 400)
				total += 50 * s1 + 50 * s2 + 100 * s3 + 100 * s4 + (cs - 300) * s5;
			else
				total += 50 * s1 + 50 * s2 + 100 * s3 + 100 * s4 + 100 * s5 + (cs - 400) * s6;

			string func[1] = { "HOA DON" };

			Menu(func, 1, ShowMiniMenu);

			printf("\n\n");

			printf("   Khach hang: %s\n", getenv("USERNAME"));
			printf("   csc: %d\tcsm: %d\n", *csc, *csm);

			Separator();

			Space(3);
			printf("Tieu thu");
			Space(7);
			printf("Truoc thue");
			Space(5);
			printf("VAT");
			Space(12);
			printf("Thanh tien\n");

			Separator();

			//Chuyen tat ca cac bien so thanh chuoi (string) de xu ly dat dau ',' sau phan ngan
			Space(3);
			fputs(to_string(cs).c_str(), stdout);
			Space(15 - to_string(cs).length());
			fputs(ThoundsandSeparator(to_string(total)).c_str(), stdout);
			Space(15 - ThoundsandSeparator(to_string(total)).length());
			fputs(ThoundsandSeparator(to_string(total * 10 / 100)).c_str(), stdout);
			Space(15 - ThoundsandSeparator(to_string(total * 10 / 100)).length());
			fputs(ThoundsandSeparator(to_string(total + (total * 10 / 100))).c_str(), stdout);
			printf("\n");
			Separator();
			printf("                                 Lien he ho tro: 1900 545454\n");

			delete csc;
			delete csm;
			csc = csm = NULL;
		}
		else {
			printf("   > Loi cap phat bo nho!\n");

			exit(69);
		}

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	Electric:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto Electric;
	}
}

void Function5() {
	char key;

	while (true) {
		SetConsoleTitle(TEXT("TINH LAI SUAT VAY"));

		BankInfo();

		clrscr;

		string func[1] = { "CHUONG TRINH TINH LAI SUAT KHOAN VAY" };

		Menu(func, 1, ShowMiniMenu);

		printf("   Toi thieu: 5,000,000 | Toi da: 100,000,000\n");

		Separator();

		long int* n = new long int;

		//Nhap khoan vay (5tr < n < 500tr)
		if (n != NULL) {
			do {
				while (true) {
					printf("   > Nhap so tien muon vay: ");
					if (scanf("%ld", &*n) == 0) {
						fgetc(stdin);
						printf("   Loi nhap du lieu\n");
					}
					else
						break;
				}

				if (*n < 5000000 || *n > 100000000) {
					beep_err;
					printf("   > Loi nhap du lieu\n");
				}
			} while (*n < 5000000 || *n > 100000000);

			clrscr;

			string func1[1] = { "BANG TINH LAI THAM KHAO" };

			Menu(func1, 1, ShowMiniMenu);

			Separator();

			//Xu ly
			printf("   Tong tien vay: ");
			fputs(ThoundsandSeparator(to_string(*n)).c_str(), stdout);
			printf("\n");
			printf("   Lai suat: 5%%/thang\n   Ky han: 12 thang\n");

			Separator();

			Space(3);
			printf("Ky han");
			Space(2);
			printf("Tien lai");
			Space(4);
			printf("Tien goc");
			Space(5);
			printf("Phai tra");
			Space(5);
			printf("Con lai\n");

			Separator();

				long int Interest, Install = *n / 12, Total, Rest = *n;
			long int tInterest = 0, tInstall = 0, tTotal = 0;
			string sInterest, sInstall, sTotal, sRest;

			for (int i = 0; i < 12; i++) {
				Interest = Rest * 0.05;
				Rest -= Install;
				Total = Interest + Install;

				tInterest += Interest;
				tInstall += Install;
				tTotal += Total;

				//XU LY CHUYEN TAT CA KET QUA SANG STRING DE THEM DAU ',' SAU PHAN NGAN
				sInterest = ThoundsandSeparator(to_string(Interest));
				sInstall = ThoundsandSeparator(to_string(Install));
				sTotal = ThoundsandSeparator(to_string(Total));

				if (i == 11)
					sRest = ThoundsandSeparator(to_string(0)); //Lam tron thanh 0
				else
					sRest = ThoundsandSeparator(to_string(Rest));

				Space(3);
				printf("%d", i + 1);
				Space(8 - to_string(i + 1).length());
				fputs(sInterest.c_str(), stdout);
				Space(12 - sInterest.length());
				fputs(sInstall.c_str(), stdout);
				Space(13 - sInstall.length());
				fputs(sTotal.c_str(), stdout);
				Space(13 - sTotal.length());
				fputs(sRest.c_str(), stdout);

				printf("\n");
			}

			string stInt, stIns, stTot;
			stInt = ThoundsandSeparator(to_string(tInterest + (*n - tInstall)));
			stIns = ThoundsandSeparator(to_string(tInstall + (*n - tInstall)));
			stTot = ThoundsandSeparator(to_string(tTotal + (*n - tInstall) * 2)); //Lam tron

			Separator();

			//XUAT RA TONG: LAI, GOC, GOC + LAI TRONG 12 THANG
			Space(3);
			printf("-");
			Space(7);
			fputs(stInt.c_str(), stdout);
			Space(12 - stInt.length());
			fputs(stIns.c_str(), stdout);
			Space(13 - stIns.length());
			fputs(stTot.c_str(), stdout);
			Space(13 - stTot.length());
			printf("-\n");

			delete n;
			n = NULL;
		}
		else {
			printf("   > Cap phat bo nho that bai!\n");
			exit(101);
		}

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	Loan:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto Loan;
	}
}

//NHAP DANH SACH SINH VIEN
void Input(Student st[], int n) {
	int check = 1;
	string menu[1] = { "NHAP DU LIEU" };

	Menu(menu, 1, ShowMiniMenu);

	Separator();

	fgetc(stdin);

	for (int i = 0; i < n; i++) {
		printf("   > Nhap thong tin sinh vien [%d]\n", i);

		do {
			printf("   > Nhap ma so sinh vien: ");
			getline(cin, st[i].id);

			for (int j = 0; j < i; j++)
				if (st[i].id.compare(st[j].id) == 0)
					check = 0;
				else
					check = 1;

			if (check != 1)
				printf("   > Ma so sinh vien da ton tai\n");
		} while (check != 1);

		printf("   > Nhap ho ten: ");
		getline(cin, st[i].name);

		printf("   > Nhap ma lop hoc: ");
		getline(cin, st[i].classid);

		fflush(stdin);

		do {
			while (true) {
				printf("   > Nhap diem trung binh: ");
				if (scanf("%f", &st[i].score) == 0) {
					fgetc(stdin);
					printf("   Loi nhap du lieu\n");
				}
				else
					break;
			}

			if (st[i].score < 0 || st[i].score > 10)
				printf("   > Diem khong hop le\n");
		} while (st[i].score < 0 || st[i].score > 10);

		fgetc(stdin);

		if (st[i].score >= 9)
			st[i].grade = "Xuat sac";
		else if (st[i].score >= 8)
			st[i].grade = "Gioi";
		else if (st[i].score >= 6.5)
			st[i].grade = "Kha";
		else if (st[i].score >= 5)
			st[i].grade = "Trung binh";
		else
			st[i].grade = "Yeu";
	}
}

//XUAT DANH SACH SINH VIEN
void Output(Student st[], int n) {
	clrscr;

	string menu[1] = { "DANH SACH SINH VIEN" };

	Menu(menu, 1, ShowMiniMenu);

	Separator();

	printf("   ");
	printf("MSSV");
	Space(4);
	printf("HO VA TEN");
	Space(14);
	printf("LOP HOC");
	Space(3);
	printf("HOC LUC");
	Space(4);
	printf("DIEM\n");

	Separator();

	for (int i = 0; i < n; i++) {
		printf("   ");
		fputs(st[i].id.c_str(), stdout);
		Space(8 - st[i].id.length());
		fputs(st[i].name.c_str(), stdout);
		Space(23 - st[i].name.length());
		fputs(st[i].classid.c_str(), stdout);
		Space(10 - st[i].classid.length());
		fputs(st[i].grade.c_str(), stdout);
		Space(11 - st[i].grade.length());
		printf("%.2f", st[i].score);
		printf("\n");
	}
}

//XOA DANH SACH SINH VIEN HIEN TAI
void Delete(Student st[], int n) {
	for (int i = 0; i < n; i++) {
		st[i].classid = "";
		st[i].grade = "";
		st[i].id = "";
		st[i].name = "";
		st[i].score = 0;
	}
}

void Array(Student st[], int n, void(*p)(Student[], int)) {
	//Dung con tro ham (*p) goi ham nhap xuat mang
	(*p)(st, n);
}

//KIEM TRA SO LON HON
bool isGreater(float number1, float number2) {
	return number1 > number2;
}

//KIEM TRA SO NHO HON
bool isSmaller(float number1, float number2) {
	return number1 < number2;
}

//HOAN VI 2 struct Student
void swap(Student& st1, Student& st2) {
	//Hoan vi
	Student tmp;
	tmp = st1;
	st1 = st2;
	st2 = tmp;
}

//PHAN HOACH MANG, TRA VE VI TRI <j> DE CHIA DOI MANG
int Partition(Student st[], int left, int right,
	bool(*compare1)(float, float), bool(*compare2)(float, float)) {
	//Cho p la phan tu dau tien
	Student p = st[left];
	int i = left + 1;
	int j = right;

	while (true) {
		//So sanh p với phan tu i va i chua den vi tri cuoi cung ben phai
		//Tang i
		while (compare1(p.score, st[i].score) && i < right)
			++i;
		//So sanh p với phan tu j va j chua den vi tri cuoi cung ben trai
		//Giam j
		while (compare2(p.score, st[j].score) && j > left)
			--j;

		if (i >= j) {
			//Neu xet i vuot qua j
			//Hoan vi phan tu j voi phan tu dau tien
			//Tra ve vi tri j de chia doi mang
			swap(st[j], st[left]);
			return j;
		}
		else
			//Neu j van lon hon i
			//Hoan vi phan tu j va i
			swap(st[i], st[j]);
	}
}

//GOI DE QUY SAP XEP QUICKSORT
void Sort(Student st[], int left, int right, int type) {
	//type = 0: Giam dan
	//type = 1: Tang dan
	int p;

	if (type == 0) { //Sap xep Giam dan
		if (left < right) {
			//Lay vi tri p de chia doi mang
			p = Partition(st, left, right, isSmaller, isGreater);
			//Sort nua ben trai
			Sort(st, left, p - 1, 0);
			//Sort nua ben phai
			Sort(st, p, right, 0);
		}
	}
	else { //Sap xep Tang dan
		if (left < right) {
			p = Partition(st, left, right, isGreater, isSmaller);
			Sort(st, left, p - 1, 0);
			Sort(st, p, right, 0);
		}
	}
}

//TRA VE VI TRI SINH VIEN CAN TIM KIEM
int Pos(Student st[], int n, string check) {
	//Tra ve vi tri phan tu co mssv trung voi mssv tim kiem
	for (int i = 0; i < n; i++)
		if (check.compare(st[i].id) == 0)
			//ham compare giong nhu strcmp neu khai bao mang char
			return i;

	//TRA VE -1 NEU KHONG CO MSSV CAN TIM
	return -1;
}

//HIEN SINH VIEN VI TRI "POS" NEU TIM THAY
void ShowPos(Student st[], int pos) {
	//Giong ham Output 
	//Nhung chi show thong tin sinh vien o vi tri pos
	clrscr;

	string a[1] = { "TIM KIEM SINH VIEN THEO MA SO SINH VIEN" };
	Menu(a, 1, ShowMiniMenu);

	Separator();

	printf("   ");
	printf("MSSV");
	Space(4);
	printf("HO VA TEN");
	Space(14);
	printf("LOP HOC");
	Space(3);
	printf("HOC LUC");
	Space(4);
	printf("DIEM\n");

	Separator();

	printf("   ");
	fputs(st[pos].id.c_str(), stdout);
	Space(8 - st[pos].id.length());
	fputs(st[pos].name.c_str(), stdout);
	Space(23 - st[pos].name.length());
	fputs(st[pos].classid.c_str(), stdout);
	Space(10 - st[pos].classid.length());
	fputs(st[pos].grade.c_str(), stdout);
	Space(11 - st[pos].grade.length());
	printf("%.2f", st[pos].score);
	printf("\n");
}

//NHAP LAI DANH SACH SINH VIEN
void Function61(Student st[], int &n) {
	clrscr;

	string menu[1] = { "NHAP DANH SACH SINH VIEN" };

	Menu(menu, 1, ShowMiniMenu);

	Array(st, n, Delete);

	do {
		printf("   > Nhap so luong phan tu: ");
		scanf("%d", &n);

		if (n < 1) {
			beep_err;
			printf("   > Loi nhap du lieu\n");
		}
	} while (n < 1);

	Array(st, n, Input);

	fgetc(stdin);

	Separator();
}

//SAP XEP SINH VIEN THEO DIEM SO
void Function62(Student st[], int n) {
	clrscr;

	string a[1] = { "SAP XEP DANH SACH SINH VIEN THEO DIEM" };
	Menu(a, 1, ShowMiniMenu);

	int type; //Kieu sap xep

	//0: Giam dan, 1: Tang dan
	while (true) {
		printf("   > Sap xep theo [0: Giam dan, 1: Tang dan]: ");
		if (scanf("%d", &type) == 0) {
			printf("   Loi nhap du lieu\n");
			fgetc(stdin);
		}
		else
			break;
	}
	
	if (type == 0)
		Sort(st, 0, n - 1, 0); //Giam dan
	else
		Sort(st, 0, n - 1, 1); //Tang dan

	Sleep(1500); //Dung chuong trinh, tao hieu ung cho chuong trinh chay

	printf("   Sap xep hoan tat!\n");

	fgetc(stdin); //Xoa '\n' khi nhap type, de khi neu nguoi dung quay lai chon F1 khong bi loi

	Separator();
}

//TIM KIEM SINH VIEN THEO MA SO SINH VIEN
void Function63(Student st[], int n) {
	clrscr;

	string a[1] = { "TIM KIEM SINH VIEN THEO MA SO SINH VIEN" };
	Menu(a, 1, ShowMiniMenu);

	string input;
	int p;

	do {
		printf("   > Nhap ma so sinh vien can tim: ");
		getline(cin, input);

		p = Pos(st, n, input);

		Separator();

		char x;

		if (p != -1)
			ShowPos(st, p);
		else {
			beep_err;
			printf("   Ma so sinh vien khong ton tai\n   Nhap ESC de thoat, hoac phim bat ky de tiep tuc tra cuu\n");

			while (!kbhit());
			x = getch();

			if (x == ESC)
				break;
		}
	} while (p == -1);

	Separator();
}

//XUAT DANH SACH SINH VIEN
void Function64(Student st[], int n) {
	clrscr;

	Array(st, n, Output);

	Separator();
}

void Function6() {
	SetConsoleTitle(TEXT("CHUONG TRINH QUAN LY SINH VIEN"));
	string menu[1] = { "CHUONG TRINH QUAN LY SINH VIEN" };

	int n;

	clrscr;

	Menu(menu, 1, ShowMiniMenu);

	do {
		printf("   > Nhap so luong phan tu: ");
		scanf("%d", &n);

		if (n < 1 || n > 100) {
			beep_err;
			printf("   > Loi nhap du lieu\n");
		}
	} while (n < 1 || n > 100);

	clrscr;

	Student st[100];
	
	Array(st, n, Input);

	while (true) {
		clrscr;

		string menu2[4] = { "Nhap lai danh sach","Sap xep danh sach","Tim kiem theo ma so",
			"In danh sach" };
		Menu(menu, 1, ShowMiniMenu);
		Menu(menu2, 4, ShowMenu);

		char key;

	Func6:
		while (!kbhit());
		key = getch();

		switch (key) {
		case F1: {
			beep;
			SetConsoleTitle(TEXT("Nhap danh sach sinh vien"));
			//Array(st, n, Function61);
			Function61(st, n);
			break;
		}
		case F2: {
			beep;
			SetConsoleTitle(TEXT("Sap xep danh sach sinh vien"));
			Array(st, n, Function62);
			break;
		}
		case F3: {
			beep;
			SetConsoleTitle(TEXT("In danh sach sinh vien"));
			Array(st, n, Function63);
			break;
		}
		case F4: {
			beep;
			SetConsoleTitle(TEXT("Tim kiem theo ma so sinh vien"));
			Array(st, n, Function64);
			break;
		}
		default: goto Func6;
		}

		char choice;

		printf("   > Nhan ESC de thoat, HOME de tiep tuc\n   > ");

	Func6_end:
		while (!kbhit());
		choice = getch();

		switch (choice) {
		case HOME: {
			beep;
			continue;
		}
		case ESC: {
			beep;
			return;
		};
		default: goto Func6_end;
		}
	}
}

//NHAP PHAN SO
void FractionInput(Fraction& ps) {
	printf("   Nhap phan so: \n");
	while (true) {
		printf("   > Tu so: ");
		if (scanf("%d", &ps.TS) == 0) {
			printf("   Loi nhap du lieu\n");
			fgetc(stdin);
		}
		else
			break;
	}

	do {
		while (true) {
			printf("   > Mau so: ");
			if (scanf("%d", &ps.MS) == 0) {
				printf("   Loi nhap du lieu\n");
				fgetc(stdin);
			}
			else
				break;
		}

		if (ps.MS == 0)
			printf("   Loi nhap du lieu\n");
	} while (ps.MS == 0);
}

//XUAT PHAN SO
void FOut(Fraction ps) {
	if (ps.TS == ps.MS) {
		setTextColor(BLUE_COLOR);
		printf("1");
		setTextColor(WHITE_COLOR);
	}
	else if (ps.MS == 1) {
		setTextColor(BLUE_COLOR);
		printf("%d", ps.TS);
		setTextColor(WHITE_COLOR);
	}
	else {
		printf("%d", ps.TS);

		setTextColor(BLUE_COLOR);
		printf("/");

		setTextColor(WHITE_COLOR);

		printf("%d", ps.MS);
	}
}

//XUAT KET QUA PHAN SO SAU KHI TINH TOAN
void FractionOutput(Fraction ps, Fraction ps1, Fraction ps2, char oper) {
	Space(3);

	FOut(ps);

	printf(" %c ", oper); //in ra phep tinh

	FOut(ps1);

	printf(" = ");

	FOut(ps2);

	printf("\n");
}

//NAP CHONG TOAN TU + - * / VA XU LY TINH TOAN PHAN SO
Fraction operator +(Fraction ps1, Fraction ps2) {
	Fraction tmp;

	tmp.TS = (ps1.TS * ps2.MS) + (ps2.TS * ps1.MS);
	tmp.MS = ps1.MS * ps2.MS;

	//Rut gon
	int compact = GCD(abs(tmp.TS), abs(tmp.MS));
	tmp.TS /= compact;
	tmp.MS /= compact;

	return tmp;
}

Fraction operator -(Fraction ps1, Fraction ps2) {
	Fraction tmp;

	tmp.TS = (ps1.TS * ps2.MS) - (ps2.TS * ps1.MS);
	tmp.MS = ps1.MS * ps2.MS;

	//Rut gon
	int compact = GCD(abs(tmp.TS), abs(tmp.MS));
	tmp.TS /= compact;
	tmp.MS /= compact;

	return tmp;
}

Fraction operator *(Fraction ps1, Fraction ps2) {
	Fraction tmp;

	tmp.TS = ps1.TS * ps2.TS;
	tmp.MS = ps1.MS * ps2.MS;

	//Rut gon
	int compact = GCD(abs(tmp.TS), abs(tmp.MS));
	tmp.TS /= compact;
	tmp.MS /= compact;

	return tmp;
}

Fraction operator /(Fraction ps1, Fraction ps2) {
	Fraction tmp;

	tmp.TS = ps1.TS * ps2.MS;
	tmp.MS = ps1.MS * ps2.TS;

	//Rut gon
	int compact = GCD(abs(tmp.TS), abs(tmp.MS));
	tmp.TS /= compact;
	tmp.MS /= compact;

	return tmp;
}

void Function7() {
	char key;
	char oper;

	while (true) {
		SetConsoleTitle(TEXT("TINH PHAN SO"));

		clrscr;

		string frmenu[1] = { "CHUONG TRINH TINH PHAN SO" };

		Menu(frmenu, 1, ShowMiniMenu);

		Separator();
		
		Fraction fr1, fr2;

		printf("   Nhap phan so thu nhat\n");

		//Nhap phan so 1
		FractionInput(fr1);

		Separator();

		printf("   Nhap phan so thu hai\n");

		//Nhap phan so 2
		FractionInput(fr2);

		Separator();

		printf("   > Chon operator (+ | - | * | /) tu ban phim\n");

	OPERATOR:
		while (!kbhit());
		oper = getch();

		switch (oper) {
		case '+': {
			clrscr;

			Menu(frmenu, 1, ShowMiniMenu);

			Separator();

			printf("   Ket qua (da rut gon):\n");

			Separator();

			//Tham tri: phan so 1, phan so 2, phep tinh, toan tu
			FractionOutput(fr1, fr2, fr1 + fr2, oper);

			break;
		}
		case '-': {
			clrscr;

			Menu(frmenu, 1, ShowMiniMenu);

			Separator();

			printf("   Ket qua (da rut gon):\n");

			Separator();

			FractionOutput(fr1, fr2, fr1 - fr2, oper);
			break;
		}
		case '*': {
			clrscr;

			Menu(frmenu, 1, ShowMiniMenu);

			Separator();

			printf("   Ket qua (da rut gon):\n");

			Separator();

			FractionOutput(fr1, fr2, fr1 * fr2, oper);

			break;
		}
		case '/': {
			clrscr;

			Menu(frmenu, 1, ShowMiniMenu);

			Separator();

			printf("   Ket qua (da rut gon):\n");

			Separator();

			FractionOutput(fr1, fr2, fr1 / fr2, oper);

			break;
		}
		default: goto OPERATOR;
		}

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	Fr:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto Fr;
	}
}

void Function8() {
	//Y tuong
	//Mang value chua menh gia 9 loai tien tai Viet Nam
	//Mang amount[] chua so luong to tien co the doi thanh theo thu tu tu lon den nho
	//Xu ly neu nguoi dung nhap dung menh gia tien hien hanh => Doi thu cong:: VD 500k thanh 2x200k + 1x100k
	//Neu khong tien hanh / de lay so to va % de xu ly tiep
	//Xuat so luong to tien co the doi theo amount[] va value[]
	char key;

	while (true) {
		SetConsoleTitle(TEXT("DOI TIEN"));

		long int* n = new long int;
		//Mang chua so luong to tien co the doi
		int amount[9] = { 0,0,0,0,0,0,0,0,0 };
		string value[9] = { "500000","200000","100000","50000","20000","10000","5000","2000","1000" };
		string a[1] = { "CHUONG TRINH DOI TIEN" };

		clrscr;

		Menu(a, 1, ShowMiniMenu);

		Separator();

		if (n != NULL) {
			do {
				while (true) {
					printf("   > Nhap so tien can doi: ");
					if (scanf("%ld", &*n) == 0) {
						fgetc(stdin);
						printf("   Loi nhap du lieu\n");
					}
					else
						break;
				}

				if (*n < 0 || *n % 1000 != 0)
					printf("   > Loi nhap du lieu\n");
			} while (*n < 0 || *n % 1000 != 0);

			int tmp = *n;

			//Xu ly neu nguoi dung nhap vao so tien chan
			if (*n == 500000) {
				amount[1] = 2;
				amount[2] = 1;
			}
			else if (*n == 200000)
				amount[2] = 2;
			else if (*n == 100000)
				amount[3] = 2;
			else if (*n == 50000) {
				amount[4] = 2;
				amount[5] = 1;
			}
			else if (*n == 20000)
				amount[5] = 2;
			else if (*n == 10000)
				amount[6] = 2;
			else if (*n == 5000) {
				amount[7] = 2;
				amount[8] = 1;
			}
			else if (*n == 2000)
				amount[8] = 2;
			else if (*n == 1000)
				amount[8] = 1;
			else {
				for (int i = 0; i < 8; i++) {
					if (tmp / 500000 > 0) {
						amount[0] = tmp / 500000;
						tmp = tmp % 500000;
					}

					if (tmp / 200000 > 0) {
						amount[1] = tmp / 200000;
						tmp = tmp % 200000;
					}

					if (tmp / 100000 > 0) {
						amount[2] = tmp / 100000;
						tmp = tmp % 100000;
					}

					if (tmp / 50000 > 0) {
						amount[3] = tmp / 50000;
						tmp = tmp % 50000;
					}

					if (tmp / 20000 > 0) {
						amount[4] = tmp / 20000;
						tmp = tmp % 20000;
					}

					if (tmp / 10000 > 0) {
						amount[5] = tmp / 10000;
						tmp = tmp % 10000;
					}

					if (tmp / 5000 > 0) {
						amount[6] = tmp / 5000;
						tmp = tmp % 5000;
					}

					if (tmp / 2000 > 0) {
						amount[7] = tmp / 2000;
						tmp = tmp % 2000;
					}

					if (tmp / 1000 > 0) {
						amount[8] = tmp / 1000;
						tmp = tmp % 1000;
					}
				}
			}

			Separator();

			printf("   Ket qua:\n   ");
			fputs(ThoundsandSeparator(to_string(*n)).c_str(), stdout);
			printf(" (VND) co the doi thanh:\n");
			printf("   --------------------\n");
			Space(3);
			printf("MENH GIA");
			Space(4);
			printf("SO LUONG\n");

			printf("   --------------------\n");

			for (int i = 0; i < 9; i++) {
				if (amount[i] != 0) {
					Space(3);
					fputs(ThoundsandSeparator(value[i]).c_str(), stdout);
					Space(12 - ThoundsandSeparator(value[i]).length());
					Space(8 - to_string(amount[i]).length());
					printf("%d", amount[i]);
					printf("\n");
				}
			}

			delete n;
			n = NULL;
		}
		else {
			beep_err;
			printf("   > Loi cap phat bo nho!\n");
			exit(101);
		}

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	MoneyExchange:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto MoneyExchange;
	}
}

void Function9() {
	char key;

	while (true) {
		SetConsoleTitle(TEXT("TRO CHOI POLY LOTT"));

		PolyLottInfo();

		clrscr;

		string func[1] = { "POLY LOTT 2/15" };

		Menu(func, 1, ShowMiniMenu);

		Separator();

		int* lucky_number1 = new int;
		int* lucky_number2 = new int;
		int* number1 = new int;
		int* number2 = new int;

		if (lucky_number1 != NULL && lucky_number2 != NULL && number1 != NULL & number2 != NULL) {
			srand(time(NULL));
			*lucky_number1 = rand() % 15 + 1;
			*lucky_number2 = rand() % 15 + 1;

			do {
				while (true) {
					printf("   > Nhap so thu nhat: ");
					if (scanf("%d", &*number1) == 0) {
						fgetc(stdin);
						printf("   Loi nhap du lieu\n");
					}
					else
						break;
				}
				while (true) {
					printf("   > Nhap so thu hai: ");
					if (scanf("%d", &*number2) == 0) {
						fgetc(stdin);
						printf("   Loi nhap du lieu\n");
					}
					else
						break;
				}

				if (*number1 < 1 || *number1 > 15 || *number2 < 1 || *number2 > 15) {
					beep_err;
					printf("   Loi nhap du lieu!\n");
				}
			} while (*number1 < 1 || *number1 > 15 || *number2 < 1 || *number2 > 15);

			clrscr;

			Menu(func, 1, ShowMiniMenu);

			Separator();

			printf("   Lucky Number:\t%d\t%d\n", *lucky_number1, *lucky_number2);

			Separator();

			printf("   Your Number:\t\t%d\t%d\n", *number1, *number2);

			Separator();

			//xu ly
			if ((*lucky_number1 == *number1 && *lucky_number1 == *number2)
				&& (*lucky_number2 == *number1 && *lucky_number2 == *number2)) {
				setTextColor(GREEN_COLOR);
				printf("   Ban da trung giai dac biet!\n");
			}
			else if ((*lucky_number1 == *number1 || *lucky_number1 == *number2)
				&& (*lucky_number2 != *number1 || *lucky_number2 != *number2) ||
				(*lucky_number2 == *number1 || *lucky_number2 == *number2)
				&& (*lucky_number1 != *number1 || *lucky_number1 != *number2)) {
				setTextColor(BLUE_COLOR);
				printf("   Ban da trung giai khuyen khich!\n");
			}
			else {
				printf("   Chuc ban may man lan sau!\n");
			}

			delete lucky_number1;
			delete lucky_number2;
			delete number1;
			delete number2;

			lucky_number1 = lucky_number2 = number1 = number2 = NULL;
		}
		else {
			beep_err;
			printf("   > Loi cap phat bo nho!\n");
			exit(101);
		}

		setTextColor(WHITE_COLOR);

		Separator();

		printf("   > Nhan ESC quay lai MENU chinh, HOME de tiep tuc\n   >\n");

	PolyL:
		while (!kbhit());
		key = getch();

		if (key == ESC)
			break;
		else if (key == HOME)
			continue;
		else
			goto PolyL;
	}
}

void Process() {
	//Bien co hieu de chay/dung thread chu chay
	atomic<bool> on = true;
	atomic<bool> cont = true;

	//Tao thread chu chay tren thanh tieu de
	thread mythread(marqueeTitle, ref(on), ref(cont));

Pr:
	on = true;

	noCursorType();

	CenterScreen();

	clrscr;

	char n;

	Info();

	string a[9] = { "Kiem tra so nguyen","UCLN & BCNN","Quan ly Karaoke","Tinh tien dien",
		"Tinh lai suat","Quan ly sinh vien","Tinh phan so", "Doi tien", "Tro choi Poly Lott" };

	Menu(a, 9, ShowMenu);

	while (!kbhit());
	n = getch();

	switch (n) {
	case F1: {
		on = false;
		beep;
		Function1();
		break;
	}
	case F2: {
		on = false;
		beep;
		Function2();
		break;
	}
	case F3: {
		on = false;
		beep;
		Function3();
		break;
	}
	case F4: {
		on = false;
		beep;
		Function4();
		break;
	}
	case F5: {
		on = false;
		beep;
		Function5();
		break;
	}
	case F6: {
		on = false;
		beep;
		Function6();
		break;
	}
	case F7: {
		on = false;
		beep;
		Function7();
		break;
	}
	case F8: {
		on = false;
		beep;
		Function8();
		break;
	}
	case F9: {
		on = false;
		beep;
		Function9();
		break;
	}
	default: {
		beep_err;
		goto Pr;
	}
	}

	clrscr;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n   > Nhan ESC de thoat, HOME de quay lai chuong trinh chinh\n   > ");

ES:
	while (!kbhit());
	n = getch();

	switch (n) {
	case HOME: {
		goto Pr;
		break;
	}
	case ESC: {
		on = false;
		cont = false;
		mythread.join();
		//Hoan tat thread chu chay, ket thuc chuong trinh
		exit(0);
	}
	default:goto ES;
	}
}

int main() {
	Process();

	getch();
	return 0;
}

