#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void question1() {
	// 產隨機數 
	int random[6];
	for (int i = 0; i < 6; i++) {
		srand(time(NULL) + 1000*i);
		int ran = rand() % 11 + 50;
		bool repeated;
		for (int j = 0; j < i; j++) {
			while (random[j] == ran) {
				repeated = true;
				ran = rand() % 11 + 50;
			}
			if (repeated) {
				repeated = false;
				j = 0;
				continue;
			}
		}
		random[i] = ran;
	}
	
	cout << "原陣列: ";
	for (int i = 0; i < 6; i++) {
		cout << random[i] << " ";
	}
	cout << '\n';
	
	// 排隨機數
	for (int i = 0; i < 6; i++) {
		for (int j = i; j > 0; j--) {
			if (random[j] > random[j-1]) {
				int temp = random[j];
				random[j] = random[j-1];
				random[j-1] = temp;
			}
		}
	}
	
	cout << "排序後: ";
	for (int i = 0; i < 6; i++) {
		cout << random[i] << " ";
	}
}

float question2_calA(float V, float R) {
	// I = V/R
	return V/R;
}

void question2() {
	float V, R;
	cout << "請輸入電壓(伏特): "; cin >> V;
	cout << "請輸入電阻(歐姆): "; cin >> R;
	
	cout << "電流: " << question2_calA(V, R) << " A(安培)";
}

int question3_getN(int N) {
	if (N == 0) return 0;
	if (N < 3) return 1;
	
	int array[N] = {1, 1, 1};
	
	for (int i = 3; i < N; i++) {
		array[i] = question3_getN(i) + question3_getN(i-2);
	}
	
	return array[N-1];
}

void question3() {
	int N;
	cout << "N="; cin >> N;
	cout << "第 " << N << " 項為: " << question3_getN(N);
	cout << "\n前 " << N << " 項: "; 
	for (int i = 0; i < N; i++) {
		cout << question3_getN(i+1) << " ";
	}
}

void question4() {
	int m, n;
	cout << "m="; cin >> m;
	cout << "n="; cin >> n;
	int result[n], index = 0;
	for (int x = 1; x <= n; x++) {
		if (x % m == 1) {
			result[index] = x;
			cout << "m=" << m << ",x=" << x << endl; 
			index++;
		}
	}
	
	cout << "結果: ";
	for (int i = 0; i < index; i++) {
		if (result[i] == 0) break;
		cout << result[i] << " ";
	}
	
	int total = 0;
	for (int i = 0; i < index; i++) {
		if (result[i] == 0) break;
		total += result[i];
	}
	cout << "\n總和: " << total;
}

int main() {
	while (true) {
		int question;
		cout << "題號: "; cin >> question;
		if (question == 0) break;
		
		switch (question) {
			case 1:
				question1();
				break;
			case 2:
				question2();
				break;
			case 3:
				question3();
				break;
			case 4:
				question4();
				break;
			default:
				cout << "未知題號!";
		}	
		cout << '\n';
	}
	return 0;
}
