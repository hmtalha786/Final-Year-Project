#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
//Motor PINs
#define IN1 D0
#define IN2 D1
#define IN3 D2
#define IN4 D3
 
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;

char auth[] = "4X4MBvwjkrPfXfYS6XTigdE0A_Doo5En"; //Enter your Blynk application auth token
char ssid[] = "Samsung galaxy j7prime";         //Enter your WIFI name
char pass[] = "89102828";                         //Enter your WIFI passowrd
 
 
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}
 
BLYNK_WRITE(V0) {
  forward = param.asInt();
}
 
BLYNK_WRITE(V1) {
  backward = param.asInt();
}
 
BLYNK_WRITE(V2) {
  left = param.asInt();
}
 
BLYNK_WRITE(V3) {
  right = param.asInt();
}
 
void smartcar() {
  if (forward == 1) {
    carforward();
    Serial.println("carforward");
  } else if (backward == 1) {
    carbackward();
    Serial.println("carbackward");
  } else if (left == 1) {
    carturnleft();
    Serial.println("carfleft");
  } else if (right == 1) {
    carturnright();
    Serial.println("carright");
  } else if (forward == 0 && backward == 0 && left == 0 && right == 0) {
    carStop();
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();
  smartcar();
}
 
void carforward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carbackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carturnleft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
