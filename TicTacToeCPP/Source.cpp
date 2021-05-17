#include <iostream>;
#include <Windows.h>;
#include <conio.h>;
#include <ctime>;
#include <math.h>;
#include <string>;

using namespace std;

struct Coordinates {
	int X = 0;
	int Y = 0;
};

struct Options {
	//������ � ������� �--------------------�
	int map[3][3] = { {0,0,0,},
					  {0,0,0,},
					  {0,0,0,},
	};

	// int menu[3] = { 1,0,0 };
	int menuSelect = 0;
};

void Victory(Options& options, string winner) {
	Sleep(1500);
	system("cls");
	cout << "[!]������ �� " << winner << "[!]\n";
	Sleep(2000);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			options.map[i][j] = 0;
		}
	}
}

void Draw(Options& options) {
	Sleep(1500);
	system("cls");
	cout << "[!]������ �� �����!!! �. �. ���� ��� ���������� �����������[!]\n";
	Sleep(2000);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			options.map[i][j] = 0;
		}
	}
	system("CLS");
}

bool DrawCheck(Options& options) {
	// �������� �� ����� 
	int drawCounter = 0;
	for (int i = 0; i < 3; i++) //������������ �� �������
	{
		for (int j = 0; j < 3; j++)// ������������ �� ��������
		{
			if (options.map[i][j] == 0) {
				drawCounter++;
			}
		}
	}
	if (drawCounter == 0)
	{
		Draw(options);
		return true;
	}
	return false;
}

bool VictoryCheck(Options& options, bool Check) {
	// �������� ������ ������� "�"
	if (Check) {
		for (int i = 0; i < 3; i++) {
			int Ycheck = 0, Xcheck = 0, XYcheck = 0, YXcheck = 0;
			for (int j = 0; j < 3; j++) {
				if (options.map[i][j] == 1) {
					Ycheck++;
				}
				if (options.map[j][i] == 1) {
					Xcheck++;
				}
				if (options.map[j][j] == 1) {
					XYcheck++;
				}
				if (options.map[j][2 - j] == 1) {
					YXcheck++;
				}
			}
			if (Ycheck == 3 || Xcheck == 3 || XYcheck == 3 || YXcheck == 3)
			{
				Victory(options, "��������");
				return true;
				break;
			}
		}
	}
	else{
		// �������� ������ ����� "�"
		for (int i = 0; i < 3; i++) {
			int Ycheck = 0, Xcheck = 0, XYcheck = 0, YXcheck = 0;
			for (int j = 0; j < 3; j++) {
				if (options.map[i][j] == 2) {
					Ycheck++;
				}
				if (options.map[j][i] == 2) {
					Xcheck++;
				}
				if (options.map[j][j] == 2) {
					XYcheck++;
				}
				if (options.map[j][2 - j] == 2) {
					YXcheck++;
				}
			}
			if (Ycheck == 3 || Xcheck == 3 || XYcheck == 3 || YXcheck == 3)
			{
				Victory(options, "������");
				return true;
				break;
			}
		}
	}
	return false;
}

bool VictoryCheck(Options& options, char symbol) {
	if (symbol == 'X' || symbol == 'x') {
		return VictoryCheck(options, true);
	}
	else if (symbol == 'O' || symbol == 'o') {
		return VictoryCheck(options, false);
	}
	return false;
}

void showMap(Options options) {
	system("cls");
	cout << "  X 1   2   3  " << endl;
	cout << "Y +---+---+---+" << endl;
	// ����� ����� 
	for (int i = 0; i < 3; i++) //������������ �� �������
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 3; j++) // ������������ �� ��������
		{
			cout << "| ";
			if (options.map[i][j] == 3)
			{
				cout << ". ";
			}
			else if (options.map[i][j] == 0)
			{
				cout << "  ";
			}
			else if (options.map[i][j] == 1)
			{
				cout << "x ";
			}
			else if (options.map[i][j] == 2)
			{
				cout << "o ";
			}
		}
		cout << "| " << endl;
		cout << "  +---+---+---+" << endl;
	}
	Sleep(1000);
}

void BOTRandomXY(Options& options) {
	Coordinates cord;

	cout << "��� ����";

	srand(time(0) % (rand() / 2 - 5 / 3 * 2));
	bool isStop = true;
	do{
		cord.X = rand() % 3;
		cord.Y = rand() % 3;

		isStop = !(options.map[cord.X][cord.Y] == 2 || options.map[cord.X][cord.Y] == 1);
		cout << ". ";
	} while (!isStop);
	options.map[cord.X][cord.Y] = 2;
	cout << endl;
}

void PlayerMove(Options& options, int player) {

	// �������� �������� ������� ln(n)
	Coordinates cord;

	do {
		cout << "������� ���������� Y: ";
		cin >> cord.X;
		cout << "������� ���������� X: ";
		cin >> cord.Y;
		cout << "\n";
		cord.X = cord.X > 0 || cord.X <= 3 ? cord.X - 1 : cord.X % 3;
		cord.Y = cord.Y > 0 || cord.Y <= 3 ? cord.Y - 1 : cord.Y % 3;
		// cord.X -= 1; cord.Y -= 1;
		if (options.map[cord.X][cord.Y] == 0) {
			options.map[cord.X][cord.Y] = player;
			break;
		}
		cout << "[!]������� ���������� ��������\n";

	} while (true);

	/* for (;;) {

		if (options.map[cord.X][cord.Y] == 2 || options.map[cord.X][cord.Y] == 1) {
			cout << "[!]������� ���������� ��������\n";
			cout << "������� ���������� Y: ";
			cin >> cord.X;
			cout << "������� ���������� X: ";
			cin >> cord.Y;
			cord.X -= 1; cord.Y -= 1;
		}
		if (options.map[cord.X][cord.Y] == 0) {
			options.map[cord.X][cord.Y] = 1;
			break;
		}
	} */
}

void PlayerMove(Options& options, char symbol)
{
	if (symbol == 'X' || symbol == 'x') {
		PlayerMove(options, 1);
	}
	else if (symbol == 'O' || symbol == 'o') {
		PlayerMove(options, 2);
	}
}

void Single(Options& options) {
	showMap(options);
	do {
		PlayerMove(options,'X');
		// �������� �� ������ X
		if (VictoryCheck(options, 'X')) { break; }
		BOTRandomXY(options);
		// �������� �� ������ O
		if (VictoryCheck(options, 'O')) { break; }
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		showMap(options);
		if (DrawCheck(options)) { break; }
	} while (true);
}

void Duo(Options& options) {
	bool isXO = true;
	showMap(options);
	do {
		string move = isXO ? "��������" : "������";
		char check = isXO ? 'X' : 'O';
		cout << "����� - " << move << "!" << endl;
		PlayerMove(options, check);
		// �������� �� ������ X
		if (VictoryCheck(options, check)) { break; }
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		showMap(options);
		isXO = !isXO;
		/*
		cout << "����� - ������!" << endl;
		PlayerMove(options, 'O');
		// �������� �� ������ O
		if (VictoryCheck(options, 'O')) { break; }
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		showMap(options);*/
		if (DrawCheck(options)) { break; }
	} while (true);
}

void showMenu(Options& options) {
	while (true) {
		cout << "[!]��������-������[!]\n";
		char checker = options.menuSelect == 0 ? '/' : ' ';
		cout << "[" << checker << "] ���� �����" << endl;
		checker = options.menuSelect == 1 ? '/' : ' ';
		cout << "[" << checker << "] ��� ������" << endl;
		checker = options.menuSelect == 2 ? '/' : ' ';
		cout << "[" << checker << "] �����" << endl;
		switch (_getch()) {
		case 'w':
		case 'W':
		case '�':
		case '�':
		case 72:
			if (options.menuSelect - 1 >= 0)
				options.menuSelect--;
			break;
		case 's':
		case 'S':
		case '�':
		case '�':
		case 80:
			if (options.menuSelect + 1 <= 2)
				options.menuSelect++;
			break;
		case 13: // ENTER
			if (options.menuSelect == 0) {
				system("CLS");
				Single(options);
			}
			else if (options.menuSelect == 1) {
				system("CLS");
				Duo(options);
			}
			else if (options.menuSelect == 2) {
				exit(0);
			}
			break;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	}
}

int main()
{
	setlocale(0, "");

	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	Options options;

	for (;;) {
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // ������ ��������� ��, � ������������ ����
		showMenu(options);
	}
}