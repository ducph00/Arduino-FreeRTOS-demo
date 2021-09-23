// #include <LiquidCrystal_I2C.h>
// #include <Wire.h>
// #include <Sim800L.h>
// #include <SoftwareSerial.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);
// SoftwareSerial sim(10, 11);

// int _timeout;
// String _buffer;
// #define buzzer 8
// #define ir 9
// Sim800L Sim800L;
// String textSms;
// String number = "+84335944076";
// uint8_t index1;
// int demSms = 0;

// void setup() {
//   Serial.begin(9600);
//   _buffer.reserve(50);
//   sim.begin(9600);
//   Sim800L.begin();
//   lcd.init();
//   lcd.backlight();
//   pinMode(buzzer, OUTPUT);
//   pinMode(ir, INPUT);
//   lcd.setCursor(5, 0);
//   lcd.print("WELCOME");
//   chaychu();
//   delay(1000);
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("   ANTI THEFT   ");
//   lcd.setCursor(0, 1);
//   lcd.print("Status:");
//   Sim800L.delAllSms();
//   Serial.println("<<Connected>>");
// }

// void loop() {
//   if (digitalRead(ir) == 1) {
//     lcd.setCursor(0, 1);
//     lcd.print("Status: ");
//     lcd.setCursor(8, 1);
//     lcd.print("NORMAL  ");
//     Serial.println("normal");
//   }
//   if (digitalRead(ir) == 0) {
//     lcd.setCursor(8, 1);
//     lcd.print("WARNING ");
//     digitalWrite(buzzer, HIGH);
//     Serial.println("WARNING");
//     Serial.println(number);
//     Serial.println("send meggase");
//     lcd.setCursor(0, 1);
//     Serial.println("Calling to phone");
//     lcd.print("Calling to phone");
//     callNumberr();
//     lcd.setCursor(0, 1);
//     lcd.print("Sending message ");
//     SendMessage();
//     lcd.setCursor(0, 1);
//     lcd.print("Send message    ");
//     while (1) {
//       textSms = Sim800L.readSms(1);
//       Serial.println("Ready");
//       if (textSms.indexOf("OFF") != -1) {
//         lcd.setCursor(0, 1);
//         lcd.print("Turn OFF BUZZER ");
//         digitalWrite(buzzer, LOW);
//         Serial.println("off");
//         Sim800L.delAllSms();
//         Serial.println("delete");
//       }
//     }
//   }
// }

// void SendMessage() {
//   Serial.println("Sending Message");
//   sim.println("AT+CMGF=1");  //Sets the GSM Module in Text Mode
//   delay(1000);
//   sim.println("AT+CMGS=\"" + number + "\"\r");  //Mobile phone number to send message
//   delay(1000);
//   String SMS = "WARNING";
//   sim.println(SMS);
//   delay(100);
//   sim.println((char)26);  // ASCII code of CTRL+Z
//   delay(5000);
// }

// void callNumberr() {
//   sim.println("AT");
//   updateSerial();
//   sim.println("ATD+ " + number + ';');
//   updateSerial();
//   Serial.println("calling");
//   delay(20000);  // wait for 20 seconds...
//   sim.println("ATH");
//   updateSerial();
// }
// void updateSerial() {
//   delay(500);
//   while (Serial.available()) {
//     sim.write(Serial.read());
//   }
//   while (sim.available()) {
//     Serial.write(sim.read());
//   }
// }

// void chaychu() {
//   for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
//     lcd.scrollDisplayLeft();
//     delay(150);
//   }
//   for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
//     lcd.scrollDisplayRight();
//     delay(150);
//   }
//   for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
//     lcd.scrollDisplayLeft();
//     delay(150);
//   }
// }

// #include "Arduino_FreeRTOS.h"

// int count1 = 0;
// int count2 = 0;

// TaskHandle_t task1_handle = NULL;
// TaskHandle_t task2_handle = NULL;

// void task1 (void *parameters) {
//   while (1)
//   {
//     Serial.print("Task 1 counter: ");
//     Serial.println(count1++);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);

//     if (count1 > 3) {
//       vTaskDelete(NULL);
//     }
//   }
// }

// void task2 (void *parameters) {
//   while (1)
//   {
//     Serial.print("Task 2 counter: ");
//     Serial.println(count2++);
//     vTaskDelay (1000 / portTICK_PERIOD_MS);
//   }
// }

// void setup() {
//   Serial.begin(9600);

//   xTaskCreate(task1, "Task 1", 1000, NULL, 1, &task1_handle);
//   xTaskCreate(task2, "Task 2", 1000, NULL, 1, NULL);

// }

// void loop() {
//   if (count1 > 3 && task1_handle != NULL) {
//     vTaskDelete(task1_handle);
//   }

//   if (count2 == 5 && task1_handle != NULL) {
//     vTaskResume(task1_handle);
//   }
// }

// void superImportantTask() {
//   vTaskSuspendAll();

//   // Run out mission critical code here.

//   xTaskResumeAll();
// }

#include "Arduino_FreeRTOS.h"

int count1 = 0;
int count2 = 0;

void task1(void* parameters) {
  while (1) {
    Serial.print("Task 1 counter: ");
    Serial.println(count1++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void task2(void* parameters) {
  while (1) {
    Serial.print("Task 2 counter: ");
    Serial.println(count2++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
  xTaskCreate(task2, "Task 2", 1000, NULL, 1, NULL);
}

void loop() {
}