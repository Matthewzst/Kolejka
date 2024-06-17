#include <iostream>
#include <windows.h>
#include <queue>
#include <string>
#include <chrono>
#include <random>

using namespace std;

queue<int> meal;

class waiter {
public:
	void OrderGenerator(int ValueOfOrder) {
		for (int i = 0; i <= ValueOfOrder; i++) {
			random_device rd;
			uniform_int_distribution<int> dist(1, 9);
			int OrderSize = dist(rd); // max 9
			meal.push(OrderSize);
		}
	}
	void GivingList(int ValueOfOrder) {
		int loading = ValueOfOrder * 1000;
		int interval = loading / 20;
		cout << "[ ";
		for (int i = 0; i < 20; i++) {
			cout << ">"; Sleep(interval);
		}
		cout << " ]";
	}
	void NextList(int ValueOfOrder) {
		random_device rd;
		uniform_int_distribution<int> dist(10, 30);
		int TimeToBringListOfOrders = dist(rd); // 30 max
		Sleep(TimeToBringListOfOrders * 1000);
		OrderGenerator(ValueOfOrder);
	}
};

void CookingBar() {
	int timeOut = meal.front() * 1000;
	int interval = timeOut / 20;
	cout << "[ ";
	for (int i = 0; i < 20; i++) {
		cout << "#"; Sleep(interval);
	}
	cout << " ]";
};


class ObjectDraw {
public:
	void PrintOneCookingSpace() {
		string text = "Cooking meal nr. ";
		string space = "---------[----]---------";
		int interval = (1 * 1000) / 20;
		for (int height = 0; height <= 4; height++) {
			cout << "\n";
			switch (height) {
			case 0:
				for (int width = 0; width <= 29; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "  +";
						break;
					case 29:
						cout << "+";
						break;
					default:
						cout << "-";
						break;
					}
				}
				break;
			case 1:
				for (int width = 0; width < 13; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "  |";
						break;
					case 6:
						for (int i = 0; i < text.length(); i++) {
							cout << text[i];
							Sleep(interval);
						}
						cout << meal.front();
						break;
					case 12:
						cout << "|";
						break;
					default:
						cout << " ";
						break;
					}
				}
				break;
			case 2:
				for (int width = 0; width < 7; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "  |";
						break;
					case 3:
						for (int i = 0; i < space.length(); i++) {
							cout << space[i];
							Sleep(interval);
						}
						break;
					case 6:
						cout << "|";
						break;
					default:
						cout << " ";
						break;
					}
				}
				break;
			case 3:
				for (int width = 0; width < 7; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "  |";
						break;
					case 3:
						CookingBar();
						break;
					case 6:
						cout << "|";
						break;
					default:
						cout << " ";
						break;
					}
				}
				break;
			case 4:
				for (int width = 0; width <= 29; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "  +";
						break;
					case 29:
						cout << "+";
						break;
					default:
						cout << "-";
						break;
					}
				}
				break;
			default:
				break;
			}
		}
	}
	void PrintGivingList(int ValueOfOrder) {
		waiter data;
		string sentence = "Giving a meal list to the Chef";
		string space = "-----------[----]-----------";
		int interval = (1 * 1000) / 20;
		for (int height = 0; height <= 4; height++) {
			cout << "\n";
			switch (height) {
			case 0:
				for (int width = 0; width <= 33; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "+";
						break;
					case 33:
						cout << "+";
						break;
					default:
						cout << "-";
						break;
					}
				}
				break;
			case 1:
				for (int width = 0; width <= 5; width++) {
					Sleep(interval);
					switch (width) {
						case 0:
							cout << "|";
							break;
						case 2:
							for (int i = 0; i <= sentence.length(); i++) {
								cout << sentence[i];
								Sleep(interval);
							}
							break;
						case 4:
							cout << "|";
							break;
						default:
							cout << " ";
							break;
					}
				}
				break;
			case 2:
				for (int width = 0; width <= 6; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "|";
						break;
					case 3:
						for (int i = 0; i <= space.length(); i++) {
							cout << space[i];
							Sleep(interval);
						}
						break;
					case 6:
						cout << "|";
						break;
					default:
						cout << " ";
						break;
					}
				}
				break;
			case 3:
				for (int width = 0; width <= 12; width++) {
					Sleep(interval);
					switch (width) {
					case 0: 
						cout << "|";
						break;
					case 5: 
						data.GivingList(ValueOfOrder);
						break;
					case 10: 
						cout << "|";
						break;
					default:
						cout << " ";
						break;
					}
				}
				break;
			case 4:
				for (int width = 0; width <= 33; width++) {
					Sleep(interval);
					switch (width) {
					case 0:
						cout << "+";
						break;
					case 33:
						cout << "+";
						break;
					default:
						cout << "-";
						break;
					}
				}
				break;
			default:
				break;
			}
		}
	}
};
class chef {
public:
	ObjectDraw show2;
	void cooking() {
		while (!meal.empty()) {
			show2.PrintOneCookingSpace();
			meal.pop();
		}
	}
};

int main() {
	// Wywołanie klas
	chef show;
	waiter order;
	ObjectDraw print2;
	// losowanie liczb 
	random_device rd;
	uniform_int_distribution<int> dist(1, 5);
	int ValueOfOrder = dist(rd); //maks 5
	// Wyświetlenie Funkcji 
	order.OrderGenerator(ValueOfOrder);
	print2.PrintGivingList(ValueOfOrder);
	show.cooking();
	return 0;
}