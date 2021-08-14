#include <Stepper.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

Stepper my_Stepper(200, D5, D6, D7, D8);

bool Right = false;
bool Left = false;

char auth[] = "4X4MBvwjkrPfXfYS6XTigdE0A_Doo5En";
char ssid[] = "Home-net-102-03112051551";
char pass[] = "89102828";


void setup(){

  Serial.begin(9600);                                 // baudrate for serial comunication
  Blynk.begin(auth, ssid, pass);                      // network information 
  my_Stepper.setSpeed(200);                            // Speed for stepper motor
  
}


BLYNK_WRITE(V4){                                      // read input from virtual pin V1
  Right = param.asInt();                              // assigning incoming value from pin V§1 to a variable
  }
  
BLYNK_WRITE(V5){                                      // read input from virtual pin V2
  Left = param.asInt();                               // assigning incoming value from pin V0 to a variable
  }
  
void Steploop (int Direction, int Rotation){          // function for stepper motor control with 2 parameters
  for (int i = 0; i < Rotation; i++){                 // for loop 
  my_Stepper.step(Direction * 200);                   // 200 is 360 degree => change value if smaller then 360 degree is needing
  Blynk.run();
  }
}

void loop() {   
  
  Blynk.run();
  
  if (Right){                                          // if condition 
  Steploop(1, 1);                                     // steppermotor rotates 3 steps 360 degree right
  Serial.println("Right turn");
  }
  delay(10);                                           // delay 20ms
  
  if (Left){                                           // if condition 
  Steploop(-1, 1);                                    // steppermotor rotates 3 steps 360 degree left
  Serial.println("Left turn");
  }
  delay(10);                                           // delay 20ms
}
