#define 2 potentiometer
#define 10 LED
#define 3 D1
#define 4 D2
#define 5 D3
#define 6 D4
#define 7 D5
#define 21 D6

unsigned long LEDtime= 0;
unsigned long analogConversion= 0;
int rawAnalogValue= 0;
int sixBitValue= 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(21, OUTPUT);

  analogReadResolution(12);
}

void loop() {
  
  if (millis() - LEDtime >= 200) {
    LEDtime += 200;
    digitalWrite(LED, !digitalRead(LED));
  }
  if(millis() - analogConversion >= 100){
    analogConversion += 100;
    rawAnalogValue= analogRead(potentiometer);
    // Convert 12-bit → 6-bit by shifting right 6 bits
    sixBitValue = rawAnalogValue >> 6;  // 0–63

    // Output each bit to the LEDs
    for (int i = 0; i < 6; i++) {
      int bitValue = (sixBitValue >> i) & 1;
      digitalWrite(bitPins[i], bitValue);
    }

}
