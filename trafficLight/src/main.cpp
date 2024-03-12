#include <Arduino.h>
#include <FreeRTOS.h>

#define pinRED 18
#define PinGreen 22

TaskHandle_t * const Red = NULL;
TaskHandle_t * const Green = NULL;
boolean x = false;

void RedUP(void * parameters);
void GreenUP(void * parameters);

void setup() {
  Serial.begin(115200);

  pinMode(pinRED,OUTPUT);
  pinMode(PinGreen,OUTPUT);

  xTaskCreatePinnedToCore(
    RedUP,
    "Red light",
    10000,
    NULL,
    1,
    Red,
    1
  );

  xTaskCreatePinnedToCore(
    GreenUP,
    "Green light",
    10000,
    NULL,
    2,
    Green,
    1
  );

  digitalWrite(pinRED,HIGH);
  digitalWrite(PinGreen,LOW);
  delay(500);

  GreenUP;
};

void loop() { 
}

void RedUP(void * parameters){
  digitalWrite(pinRED,HIGH);
  digitalWrite(PinGreen,LOW);
  vTaskDelay(500);

  GreenUP;
  vTaskSuspend(Red);
}
void GreenUP(void * parameters){
  digitalWrite(pinRED,LOW);
  digitalWrite(PinGreen,HIGH);
  vTaskDelay(500);

  RedUP;
  vTaskSuspend(Green);
}