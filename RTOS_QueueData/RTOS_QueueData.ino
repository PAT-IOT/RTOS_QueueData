#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

#define QUEUE_SIZE 20
QueueHandle_t dataQueue;
int dataToSend;
int receivedData;
//---------------------------------------------------------------------------------------------------------
void task_core0_IncrementalData(void *pvParameters) {
  int IncrementalData = 0;
  while (1) {
    for (int i = 0; i < 10; i++) {
       IncrementalData++;
      xQueueSend(dataQueue, &IncrementalData, portMAX_DELAY);
    }
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}
//---------------------------------------------------------------------------------------------------------
void task_core1_FixedData(void *pvParameters) {
  int fixedData = 999;
  while (1) {
    xQueueSend(dataQueue, &fixedData, portMAX_DELAY);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
//--------------------------------------------------------------------------------------------------------
void task_core1_Receiver(void *pvParameters) {  //core 1
  int receivedData;
  while (1) {
    Serial.print("Received data: ");
    while (xQueueReceive(dataQueue, &receivedData, 10) == pdTRUE) {
      Serial.print("    " + String(receivedData));
    }
    Serial.println();
    Serial.println("__________________________________________________________");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
//______________________________________________________________________________________________________
void setup() {
  Serial.begin(115200);
  dataQueue = xQueueCreate(QUEUE_SIZE, sizeof(int));
  xTaskCreatePinnedToCore(task_core0_IncrementalData, "Core0 IncrementalData", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(task_core1_FixedData, "Core1 FixedData", 10000, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(task_core1_Receiver, "Core1 Receiver", 10000, NULL, 2, NULL, 1);
}
//-------------------------------------------------------------------------------------------------------
void loop() {
}
