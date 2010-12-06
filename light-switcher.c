int switchPin = 2;
int val;
int buttonState;
int ledPinOrange = 12;
int ledPinYellow = 11;

int lightMode = 0;

void setup() {
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinOrange, OUTPUT);
  pinMode(switchPin, INPUT);

  digitalWrite(ledPinOrange, LOW);
  digitalWrite(ledPinYellow, HIGH);

  Serial.begin(9600);

  buttonState = digitalRead(switchPin);
}

void loop(){
  val = digitalRead(switchPin);

  if (val != buttonState && val == LOW) {
    if(lightMode == 0 && digitalRead(ledPinOrange) == HIGH) {
      digitalWrite(ledPinOrange, LOW);
      digitalWrite(ledPinYellow, HIGH);

      lightMode = 1;
    } else {
      digitalWrite(ledPinOrange, HIGH);
      digitalWrite(ledPinYellow, LOW);
      lightMode = 0;
    }
  }
  
}

