#include <SoftwareSerial.h>
SoftwareSerial atmega(2, 3);

String inputString = "";  // 수신 데이터를 저장할 변수
const int ledPin = 9;     // LED가 연결된 핀 번호

void setup() {
  Serial.begin(9600);
  atmega.begin(9600);
  pinMode(ledPin, OUTPUT);  // LED 핀을 출력 모드로 설정
}

void loop() {
  while (atmega.available()) {
    char receivedChar = atmega.read();  // 수신된 문자를 읽음
    if (receivedChar == '\r') {         // \r 문자 기준으로 처리
      if (inputString == "LEDON") {      // 입력이 "test"라면
        digitalWrite(ledPin, HIGH);     // 9번 핀 LED 켜기
        Serial.println(inputString);       // 시리얼 모니터에 메시지 출력
      } else {
        digitalWrite(ledPin, LOW);      // 다른 입력이 들어오면 LED 끄기
        Serial.println(inputString);
      }
      inputString = "";                 // 입력 문자열 초기화
    } else if (receivedChar != '\n') {  // \n은 무시
      inputString += receivedChar;      // 문자를 문자열에 추가
    }
  }
}
