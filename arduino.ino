int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

    if (data == '1') digitalWrite(led1, HIGH);
    if (data == '2') digitalWrite(led2, HIGH);
    if (data == '3') digitalWrite(led3, HIGH);
    if (data == '4') digitalWrite(led4, HIGH);
    if (data == '5') digitalWrite(led5, HIGH);
  }
}
