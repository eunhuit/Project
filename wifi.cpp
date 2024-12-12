 #include <ESP8266WiFi.h>
 
const char* ssid = "iptime";
const char* password = "12345678";
int Gas = 0;
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  pinMode(2, OUTPUT);
}



void loop() {
 
  // Check if a client has connected

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  if(Serial.available()){
    char Data = (char)Serial.read();
    if(Data = '1') {
      digitalWrite(2, HIGH);
    }else {
      digitalWrite(2, LOW);
    }
  }
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  Gas = digitalRead(D0);
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("HELLO WORLD!<br>");
  client.print("Gasstatus: ");
  client.print(GG);
  client.print("<br>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
