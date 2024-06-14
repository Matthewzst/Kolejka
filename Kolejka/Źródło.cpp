#include <iostream>
#include <windows.h>
#include <queue>
#include <string>
#include <future>

using namespace std;

queue<int> meal;

class Dialog {
public:
	//HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
	//GetConsoleScreenBufferInfo(hConsol, &csbi);
	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	//int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	void centerOutput(int width, const string& str) {
		int padding = (width - str.length()) / 2;
		for (int i = 0; i < padding; i++) {
			cout << " ";
		}
		cout << str << endl;
	}

	void WelcomeDialogy() {
		int width = 120; // szerokość konsoli
		centerOutput(width, "----------------------------------------------");
		centerOutput(width, "----- WELCOME IN ORDER MEAL  WITH AI BOT -----");
		centerOutput(width, "----------------------------------------------");
		cout << "\n";

	}
};


class waiter {
public:
	void OrderGenerator(int ValueOfOrder) {
		for (int i = 0; i <= ValueOfOrder; i++) {
			int OrderSize = rand() % 9 + 1; // max 9
			meal.push(OrderSize);
		}
	}

	void GivingList(int ValueOfOrder) {
		int loading = ValueOfOrder * 1000;
		int interval = loading / 20;
		cout << "+--------------------------------+\n";
		cout << "| Giving a meal list to the Chef |\n";
		cout << "|  -----------[----]-----------  |\n";
		cout << "|    [ ";
		for (int i = 0; i < 20; i++) {
			cout << ">"; Sleep(interval);
		}
		cout << " ]    |\n";
		cout << "+--------------------------------+\n\n";
	}

	void NextList(int ValueOfOrder) {
		int TimeToBringListOfOrders = rand() % 30 + 10; // 30 max
		Sleep(TimeToBringListOfOrders * 1000);
		OrderGenerator(ValueOfOrder);
	}
};

void CookingBar() {
	int timeOut = meal.front() * 1000;
	int interval = timeOut / 20;
	cout << "|  [ ";
	for (int i = 0; i < 20; i++) {
			cout << "#"; Sleep(interval);
	}
	cout << " ]  |\n";
};

class chef {
public:
	void cooking() {
		while(!meal.empty()){
			cout << "+----------------------------+\n";
			cout << "|     Cooking meal nr. " << meal.front() << "     |\n";
			cout << "|  ---------[----]---------  |\n";
			CookingBar();
			meal.pop();
		}

	}
	void finishCooking() {
		cout << "";
	}
	
};

int main() {

	chef show;
	waiter order;
	Dialog print;

	int ValueOfOrder = rand() % 5 + 1; //maks 15


	print.WelcomeDialogy();
	order.OrderGenerator(ValueOfOrder);
	order.GivingList(ValueOfOrder);
	show.cooking();




	return 0;
}

