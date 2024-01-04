#include <iostream>
#include <iomanip>
#include <ctime> 
#include <cstdlib>
using namespace std;

void question1() { // 第一題 
	float height, weight;
	cout << "請輸入身高: ";
	cin >> height;
	cout << "請輸入體重: ";
	cin >> weight;
	
	float floatBMI = (weight / ((height / 100) * (height / 100)));
	int intBMI = (weight / ((height / 100) * (height / 100)));
	cout << "BMI: " << (floatBMI == intBMI ? setprecision(2) : setprecision(4)) << floatBMI;
	if (intBMI >= 24 ) {
		cout << "\nBMI過高，該運動囉！"; 
	} else if (intBMI < 18) {
		cout << "\nBMI過低，注意營養！";
	} else {
		cout << "\nBMI正常，繼續保持！";
	}
}

void question2() { // 第二題
	while (true) {
		srand(time(NULL));
		char player;
		cout << "請問你要出什麼？(P：布，R：石頭，S：剪刀) ";
		cin >> player;
		if (player == 'e') break; // 離開
		int playerChoice;
		switch (player) { // 0: 布, 1: 石頭, 2: 剪刀
			case 'P':
			case 'p':
				playerChoice = 0;
				break;
				
			case 'R':
			case 'r':
				playerChoice = 1;
				break;
				
			case 'S':
			case 's':
				playerChoice = 2;
				break;
		}
		int computer = rand() % 3;
		cout << "你出：" << (playerChoice == 0 ? "布": playerChoice == 1 ? "石頭" : "剪刀") << "，電腦出：" << (computer == 0 ? "布": computer == 1 ? "石頭" : "剪刀") << endl;
		int result; // 0: 玩家獲勝, 1: 電腦獲勝, 2: 平手
		switch (playerChoice) {
			case 0:
				cout << (computer == 0 ? "平手！" : computer == 1 ? "你獲勝囉！" : "電腦獲勝！");
				break;
			
			case 1:
				cout << (computer == 1 ? "平手！" : computer == 2 ? "你獲勝囉！" : "電腦獲勝！");
				break;
				
			case 2:
				cout << (computer == 2 ? "平手！" : computer == 0 ? "你獲勝囉！" : "電腦獲勝！");
				break;
		}
		cout << endl;
	}

}

void question3() { // 第三題
	float a, b;
	cout << "請輸入數字A: ";
	cin >> a;
	
	cout << "請輸入數字B: ";
	cin >> b;
	
	cout << "結果 " << (a > b ? "A > B" : a < b ? "A < B" : "A = B"); 
}

void question4() { // 第四題
	int layer;
	while (true) {
		cout << "請問要幾層(1~19): ";
		cin >> layer;
		if (layer > 19) continue;
		if (layer % 2 == 1) break;
	}
	
	for (int l1 = 1; l1 <= layer / 2; l1++) {
		for (int i = 0; i < l1; i++) {
			cout << "*";
		}
		cout << endl;
	}
	
	for (int l2 = (layer - (layer / 2)); l2 >= 0; l2--) {
		for (int i = 0; i < l2; i++) {
			cout << "*";
		}
		cout << endl;
	}
}

void question5() { // 第五題
	while (true) {
		int month;
		cout << "請輸入月份: ";
		cin >> month;
		
		if (month > 12) {
			cout << "輸入錯誤，請重新輸入";
			continue;
		}
		if (month == 0) break; // 離開
		switch (month) {
			case 1:
			case 2:
			case 3:
				cout << "春季";
				break;
			
			case 4:
			case 5:
			case 6:
				cout << "夏季";
				break;
				
			case 7:
			case 8:
			case 9:
				cout << "秋季";
				break;
				
			case 10:
			case 11:
			case 12:
				cout << "冬季";
				break;
		}
		cout << endl;
	}
}

void question6() { // 第六題
	int start, end;
	cout << "請輸入起始範圍: ";
	cin >> start;
	cout << "請輸入結束範圍: ";
	cin >> end;
	
	for (int i = 1; i <= 9; i++) {
		for (int j = start; j <= end; j++) {
			cout << j << "x" << i << "=" << setw(2) << j*i << " ";		
		}
		cout << endl;
	} 
}

int main() {
	return 0;
} 
