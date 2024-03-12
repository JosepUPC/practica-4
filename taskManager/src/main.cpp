#include<Arduino.h>
#include<FreeRTOS.h>


 TaskHandle_t * const task = NULL;
void anotherTask( void * parameter );

void setup()
{
Serial.begin(115200);
/* we create a new task here */
xTaskCreate(
  anotherTask, /* Task function. */
  "another Task", /* name of task. */
  10000, /* Stack size of task */
  NULL, /* parameter of the task */
  1, /* priority of the task */
  task); /* Task handle to keep track of created task */
}
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
Serial.println("this is ESP32 Task");
delay(500);
}
/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter ){
/* loop forever */
  for(;;)
  {
    Serial.println("this is another Task");
    vTaskDelay(500);
  }
}
