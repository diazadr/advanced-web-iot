#include <WiFi.h>
#include <MQTT.h>
#include "DHTesp.h"
#include <NusabotSimpleTimer.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

const int DHT_PIN = 15;
const int SERVO_PIN = 18;

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

WiFiClient net;
MQTTClient client;
DHTesp dhtSensor;
NusabotSimpleTimer timer;
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

String temp, humid;
int posServo = 0;

void publishDHT() {
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  temp = String(data.temperature, 2);
  humid = String(data.humidity, 1);

  client.publish("example/suhu", temp, true, 1);
  client.publish("example/kelembapan", humid, true, 1);
}

void subscribe(String &topic, String &data) {
  if (topic == "example/servo") {
    posServo = data.toInt();
    servo.write(posServo);
  }
  if (topic == "example/lcd"){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(data);
  }
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("5678", "learniot", "Q9kct1p8Qw7l9G9C")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
  client.publish("example/serial_number/5678", "Online", true, 1);
  client.subscribe("example/#", 1);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  client.begin("learniot.cloud.shiftr.io", net);
  timer.setInterval(2000, publishDHT);
  client.onMessage(subscribe);
  servo.attach(SERVO_PIN, 500, 2400);
  lcd.init();
  lcd.backlight();
  servo.write(posServo);
  client.setWill("example/serial_number/5678", "Offline", true, 1 );
  connect();
}

void loop() {
  timer.run();
  if (!client.connected()) {
    connect();
  }
  delay(10);

}