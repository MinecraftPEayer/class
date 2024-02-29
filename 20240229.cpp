#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int lotte[7];
    for (int i = 0; i < 7; i++) {
        srand(time(NULL) + i*100);
        lotte[i] = rand() % 9 + 1;
        while (true) {
            bool repeated = false;
            for (int j = i - 1; j >= 0; j--) {
                
                if (lotte[i] == lotte[j]) repeated = true;
            }

            if (!repeated) break;
        }
    }
  
    for (int i = 0; i < 7; i++) {
        cout << "" << lotte[i] << " ";
    }

    cout << endl;

    for (int i = 6; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lotte[j] < lotte[j + 1]) {
                int temp = lotte[j + 1];
                lotte[j + 1] = lotte[j];
                lotte[j] = temp;
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        cout << "" << lotte[i] << " ";
    }
    
    return 0; 
}
