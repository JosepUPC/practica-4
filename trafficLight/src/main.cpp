#include <Arduino.h>
#include <FreeRTOS.h>

#define pinRED 37
#define PinGreen 38
#define time 1000

TaskHandle_t * const taffic = NULL;
TaskHandle_t * const stop = NULL;
boolean x = true;
boolean m = 1;

void Changevalue(void * parameters);
void Wait(void * parameters);

void setup() {
  Serial.begin(115200);

  pinMode(pinRED,OUTPUT);
  pinMode(PinGreen,OUTPUT);

  xTaskCreate(
    Changevalue,
    "Red light",
    1000,
    NULL,
    1,
    taffic
  );

  xTaskCreate(
    Wait,
    "Green light",
    1000,
    NULL,
    2,
    stop
  );
  Changevalue;
}

void loop() {
}

void Changevalue(void * parameters){
  for(;;){
    if(x==true){
    digitalWrite(pinRED,HIGH);
    vTaskDelay(time);
    x=false;
    }
  }
}
void Wait(void * parameters){
  for(;;){
    if(x==false){
    digitalWrite(pinRED,LOW);
    vTaskDelay(time);
    x=true;
    }
  }
}