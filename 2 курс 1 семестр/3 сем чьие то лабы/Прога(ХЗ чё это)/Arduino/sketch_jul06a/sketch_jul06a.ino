#define led 8
#define button 2


int fire = 255;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
}

void loop() {
    while(digitalRead(button) == LOW)
        ;
    fire--;
    analogWrite(led, fire);
}
