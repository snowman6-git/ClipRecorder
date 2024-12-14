#include <TFT_eSPI.h>
#include <SPI.h>
#include <WiFi.h>
#include <Arduino.h>
#include <HTTPClient.h>

const char* ssid = "snowman6ip";       // WiFi 네트워크의 SSID
const char* password = "snowman6+@"; 

HTTPClient http;
TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
#define TFT_BLACK 0x0000 // Black color/

int wait = 0;
int displayed = 0;


const char* STATION_ADDRESS = "http://aa2.uk";

// 함수 프로토타입 선언 (기본 인자 설정)
void cl(String text, int pos = 0);

void setup(void) {
  Serial.begin(115200);
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


  if (WiFi.status() == WL_CONNECTED) {
    cl("try to request", 50);
    http.begin(STATION_ADDRESS); // 원하는 URL로 변경
    cl(STATION_ADDRESS, 50);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String payload = http.getString();
      cl(String(httpResponseCode), 60);
      cl(payload, 70);
      // Serial.println(httpResponseCode); // 응답 코드 출력
      // Serial.println(payload); // 응답 내용 출력
    } else {
      cl(String(httpResponseCode), 60);
    }
    // 연결 종료
    // http.end();
  } else {
    cl("device is offline", 50);
  }
  delay(1000);
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
  String linerText = String(displayed) + ": " + text; //출력되는 줄 넘버 + 텍스트
  tft.print(linerText);
}
