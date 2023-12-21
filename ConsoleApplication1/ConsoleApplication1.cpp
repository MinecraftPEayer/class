#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int randNumber = (rand() % 100) + 1, answer = 0, counter = 1;
	int max = 100, min = 1;

	while (true) {
		if (answer == randNumber) {
			cout << "\x1b[32mcorrect\x1b[0m";
			break;
		}
		cout << "\x1b[33m" << min << "~" << max << "\x1b[0m\n";
		cout << "\x1b[0m(\x1b[32m" << counter << "\x1b[0m) input your guess: \x1b[94m";
		cin >> answer;
		
		if (answer < min || answer > max) {
			cout << "\x1b[31mout of range\x1b[0m\n";
			continue;
		}
		if (answer <= randNumber) min = answer;
		if (answer >= randNumber) max = answer;
		counter++;
	}
	return 0;
}