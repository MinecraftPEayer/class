int output[8] = { 9, 8, 7, 6, 5, 4, 3, 2 };

void setup() {
	for (int i = 0; i < 8; i++) {
		pinMode(output[i], OUTPUT);
	}
	pinMode(A1, INPUT);
	Serial.begin(9600);
}

void turnoffAllLED() {
	for (int i = 0; i < 8; i++) {
		digitalWrite(output[i], 0);
	}
}

void loop() {
	int lights = analogRead(A1) / (1000 / 8);
	Serial.println(lights);
	
	turnoffAllLED();
	
	for (int i = 0; i < lights; i++) {
		digitalWrite(output[i], 1);
	}
}

// 1010