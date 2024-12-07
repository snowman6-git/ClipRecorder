#include <TFT_eSPI.h>
#include <SPI.h>
#include <WiFi.h>
#include <Arduino.h>

const char* ssid = "snowman6ip";       // WiFi 네트워크의 SSID
const char* password = "snowman6+@"; 

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
#define TFT_BLACK 0x0000 // Black color
int displayed = 0;
int wait = 0;
// 함수 프로토타입 선언 (기본 인자 설정)
void cl(String text, int pos = 0);

void setup(void) {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  cl("bootup...");
  delay(1000);

  WiFi.mode(WIFI_STA);
  cl("Setting MODE: STATION");
  // WiFi 연결 시작
  WiFi.begin(ssid, password);
  String ssid_target = "Target: " + String(ssid);
  cl(ssid_target);
  // WiFi 연결 대기
  while (WiFi.status() != WL_CONNECTED) {
    String tryto = "Try To Connect: " + String(wait) + "s";
    cl(tryto, 40);
    delay(1000);
    wait += 1;
  }
  String ssid_ip = "IP: " + String(WiFi.localIP());
  String ssid_mac = "MAC: " + String(WiFi.macAddress());
  cl(ssid_ip);
  cl(ssid_mac);
}

void loop() {
  String ssid_signal = "Signal: " + String(WiFi.RSSI());
  cl(ssid_signal, 50);
  // cl("A");
  // 메인 루프는 비워둡니다.
}

// 함수 정의 (기본 인자 생략)
void cl(String text, int pos) {
  if (displayed == 120) {
    // tft.fillRect(0, 0, tft.width(), 16, TFT_BLACK); // 텍스트가 출력될 영역을 지움
    tft.setCursor(0, 120, 1); // 커서를 다시 설정하여 같은 위치에 출력
    displayed = 0;
  }
  if (pos == 0) {
    tft.setCursor(0, displayed, 1); // 커서를 설정하여 같은 위치에 출력
    displayed += 10;
  } else {
    tft.setCursor(0, pos, 1); //pos 미 지정시 원하는 위치에 출력
  }
  String linerText = String(displayed) + ": " + text;
  tft.print(linerText);
}
