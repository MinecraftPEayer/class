int input[2] = { 10, 11 };
int output[8] = { 9, 8, 7, 6, 5, 4, 3, 2 };

unsigned long buttonTime;
unsigned long lightTime;

void setup() {
	for (int i = 0; i < 2; i++) {
		pinMode(input[i], INPUT_PULLUP);
	}
	for (int i = 0; i < 8; i++) {
		pinMode(output[i], OUTPUT);
	}
	Serial.begin(9600);
	buttonTime = millis();
	lightTime = millis();
}

bool lastStatus[2] = { 1, 1 };
bool nowStatus[2] = { 1, 1 };

bool running = false;

void turnoffAllLED() {
	for (int i = 0; i < 8; i++) {
		digitalWrite(output[i], 0);
	}
}

int delayInMS = 50;

short index = 7;
void mode1() {
	if (index < 2) index = 7;

	turnoffAllLED();
	
	for (int i = index; i >= (index - 2); i--) {
		digitalWrite(output[i], 1);
	}
	
	index--;
}

bool filled = true;
short mode2And3Index = 0;
bool reversing = false;
void mode2And3() {
	if (!filled || reversing) turnoffAllLED();
	
	if (!filled) {
		digitalWrite(output[mode2And3Index], 1);
		digitalWrite(output[7-mode2And3Index], 1);
	} else {
		for (int i = 0; i <= mode2And3Index; i++) {
			digitalWrite(output[i], 1);
		}
		
		for (int i = 7; i >= (7-mode2And3Index); i--) {
			digitalWrite(output[i], 1);
		}
	}
	
	reversing ? mode2And3Index-- : mode2And3Index++;
	
	if (mode2And3Index >= 4) {
		reversing = 1;
		mode2And3Index = 2;
	}
	if (mode2And3Index < 0) {
		reversing = 0;
		mode2And3Index = 1;
	}
}

short mode = 0;
void loop() {
	if (millis() - buttonTime >= 20) {
		nowStatus[0] = digitalRead(input[0]);
		nowStatus[1] = digitalRead(input[1]);
		
		if (!nowStatus[0] && lastStatus[0]) {
			running = !running;
		}
		
		if (!nowStatus[1] && lastStatus[1]) {
			mode++;
			if (mode >= 3) mode = 0;
			if (mode == 2) filled = true;
			if (mode == 1) filled = false;
		}
		
		lastStatus[0] = nowStatus[0];
		lastStatus[1] = nowStatus[1];
		buttonTime = millis();
	}
	
	if (millis() - lightTime >= delayInMS && running) {
		switch (mode) {
			case 0:
				mode1();
				break;
			
			case 1:
			case 2:
				mode2And3();
				break;
		}
		lightTime = millis();
	}
	
	if (Serial.available()) {
		delayInMS = Serial.parseInt();
		while (Serial.available()) Serial.read();
	}
}
