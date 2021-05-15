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
}

void DrawCheck(Options& options) {
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
	}
}

void VictoryCheck(Options& options, bool Check) {
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
				break;
			}
		}
	}
}

void VictoryCheck(Options& options, char symbol) {
	if (symbol == 'X' || symbol == 'x') {
		VictoryCheck(options, true);
	}
	else if (symbol == 'O' || symbol == 'o') {
		VictoryCheck(options, false);
	}
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

void PlayerMove(Options& options) {

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
			options.map[cord.X][cord.Y] = 1;
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

void Single() {

}

void showMenu(Options& options) {
	cout << "[!]��������-������[!]\n";

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
	bool isStop = true;
	showMap(options);

	for (; isStop;) {
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // ������ ��������� ��, � ������������ ����
		PlayerMove(options);
		//VictoryCheck(options, true); // �������� �� ������ X
		VictoryCheck(options, 'X'); // �������� �� ������ X
		BOTRandomXY(options);
		//VictoryCheck(options, false); // �������� �� ������ O
		VictoryCheck(options, 'O'); // �������� �� ������ O
		showMap(options);
		DrawCheck(options);
	}
}