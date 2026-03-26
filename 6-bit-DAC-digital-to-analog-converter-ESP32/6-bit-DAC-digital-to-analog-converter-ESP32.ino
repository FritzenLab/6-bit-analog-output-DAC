#define potentiometer 2
#define LED 10
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 21

unsigned long LEDtime= 0;
unsigned long analogConversion= 0;
int rawAnalogValue= 0;
int sixBitValue= 0;
int bitValue= 0;
const int bitPins[] = {D1, D2, D3, D4, D5, D6};

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
      bitValue = (sixBitValue >> i) & 1;
      digitalWrite(bitPins[i], bitValue);
    }
  }
}
