#include <Keypad.h>
#include <Servo.h>

const byte rows = 4;
const byte columns = 3;

char keys[rows][columns] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'},
};

byte pinRows[] = {5, 4, 3, 2};
byte pinColumns[] = {A0, A1, A2};

Keypad keypad = Keypad(makeKeymap(keys), pinRows, pinColumns, rows, columns);

char key;

byte R = 6;
byte G = 7;
byte B = 8;

byte pinBuzzer = 9;

Servo myServo;

void setup() {
	Serial.begin(9600);

	pinMode(R, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(B, OUTPUT);

	pinMode(pinBuzzer, OUTPUT);

	myServo.attach(10);
	myServo.write(0);
}

void loop() {
	key = keypad.getKey();

	if (key){
		switch(key){
			case '1':
				digitalWrite(R, HIGH);
				digitalWrite(G, LOW);
				digitalWrite(B, LOW);
				break;
			case '2':
				digitalWrite(R, LOW);
				digitalWrite(G, HIGH);
				digitalWrite(B, LOW);
				break;
			case '3':
				digitalWrite(R, LOW);
				digitalWrite(G, LOW);
				digitalWrite(B, HIGH);
				break;
			case '4':
				digitalWrite(R, LOW);
				digitalWrite(G, LOW);
				digitalWrite(B, LOW);
				digitalWrite(pinBuzzer, HIGH);
				delay(1000);
				digitalWrite(pinBuzzer, LOW);
				break;
			case '5':
				digitalWrite(R, LOW);
				digitalWrite(G, LOW);
				digitalWrite(B, LOW);
				myServo.write(180);
				delay(1000);
				myServo.write(0);
				break;
			case '6':
				digitalWrite(R, LOW);
				digitalWrite(G, LOW);
				digitalWrite(B, LOW);
				digitalWrite(pinBuzzer, HIGH);
				myServo.write(180);
				delay(1000);
				digitalWrite(pinBuzzer, LOW);
				myServo.write(0);
				break;
			default:
				digitalWrite(R, LOW);
				digitalWrite(G, LOW);
				digitalWrite(B, LOW);
				break;
		}

		Serial.println(key);
	}

}
