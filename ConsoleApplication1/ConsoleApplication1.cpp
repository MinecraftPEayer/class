#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Jewel {
public:
	bool gameOver = false;
	int p1Take, p2Take;
	int jewel;
	int turn;

	void init() {
		gameOver = false;
		p1Take = 0, p2Take = 0;
		srand(time(NULL));
		jewel = rand() % 10 + 20;
		turn = rand() % 2 + 1;
	}

	void input(int input) {
		if (turn == 1) {
			if (input > 3) return;
			if (input <= 0) return;

			jewel -= input;
			p1Take += input;

			if (jewel <= 0) {
				gameOver = true;
				gameEnd();
				return;
			}

			turn = 2;
		}
		else {
			if (input > 3) return;
			if (input <= 0) return;

			jewel -= input;
			p2Take += input;

			if (jewel <= 0) {
				gameOver = true;
				gameEnd();
				return;
			}

			turn = 1;
		}
	}

	void renderGame() {
		system("cls");
		cout << "\x1b[0m聚寶盆: ";
		for (int i = 0; i < jewel; i++) {
			int color = rand() % 10 + 90;
			cout << "\x1b[" << color << "mo";
		}
		cout << "\x1b[0m (" << jewel << ")";

		cout << "\n玩家1: ";
		for (int i = 0; i < p1Take; i++) {
			int color = rand() % 10 + 90;
			cout << "\x1b[" << color << "mo";
		}
		cout << "\x1b[0m (" << p1Take << ")";

		cout << "\x1b[0m\n玩家2: ";
		for (int i = 0; i < p2Take; i++) {
			int color = rand() % 10 + 90;
			cout << "\x1b[" << color << "mo";
		}
		cout << "\x1b[0m (" << p2Take << ")";

		cout << "\n\x1b[0m目前輪到: " << (turn == 1 ? "玩家1" : "玩家2") << "\n";
	}

	void gameEnd() {
		if (!gameOver) return;
		system("cls");
		cout << "\x1b[0m遊戲結束! " << (turn == 1 ? "玩家2獲得勝利!" : "玩家1獲得勝利!");
	}
};

int main() {
	Jewel game = Jewel();
	game.init();
	
	while (true) {
		if (game.gameOver) break;
		game.renderGame();
		int input;
		cout << "請輸入寶石數量: ";
		cin >> input;
		game.input(input);
	}
	return 0;
}
