#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SoftwareSerial.h>

char buff;
bool reverse_status = 0;
SoftwareSerial uart_gate(3,1);

const char* ssid = "A,Son";
const char* password = "minhhieu1130";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
 
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>

<head>
  <title>RARM control WebServer</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
  html {
    font-family: Consolas;
    display: inline-block;
    margin: 0px auto;
    text-align: center;
  }
  h3 {
    color: #1e0f76;
    padding: 0vh;
  }
  p {
    font-size: 1rem;
  }
  .button {
    display: inline-block;
    background-color: #00ba4d;
    border: none;
    border-radius: 6px;
    color: white;
    padding: 15px 20px;
    text-decoration: none;
    font-size: 14px;
    margin: 0px auto;
    cursor: pointer;
  }
  .button_stop {
    background-color: #f44336;
  }

   </style>
</head>

<body>
  <h3>WebServer of RARM</h3>
  <h5>Edited by Luu Quang Minh</h5>
  <p><a href="/Joint1"><button class="button button1">Joint1</button></a>
    <a href="/Joint2"><button class="button button2">Joint2</button></a>
    <a href="/Joint3"><button class="button button3">Joint3</button></a></p>
  <p><a href="/Reverse"><button class="button button_stop">Reverse</button></a>
    <a href="/StepChange"><button class="button button_stop">StepChange</button></a></p>
  <p><a href="/Turning"><button class="button button4">Turning</button></a>
    <a href="/Rotate"><button class="button button5">Rotate</button></a>
    <a href="/Gripper"><button class="button button6">Gripper</button></a></p>
    
<div class="footer">
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <h6> More info: <a href="mailto:minhmark47@gmail.com">minhmark47@gmail.com</a>
                    <a href="https://www.facebook.com/profile.php?id=100004186217509">
                        <img src="img/avatar.jpg" alt="Facebook account" width="20" height="20"></a></h6>
                <tt>Last modified:10/05/2021</tt> 
            </div>    
        </div>
    </div>
</div>
</body>

</html>)rawliteral";

void setup(){
  Serial.begin(115200);
  uart_gate.begin(9600);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("..");
  }
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });
 
  server.on("/Joint1", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('a');
    else uart_gate.write('A');
    request->send(200, "text/html", index_html);
  });
  
  server.on("/Joint2", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('b');
    else uart_gate.write('B');
    request->send(200, "text/html", index_html);
  });

  server.on("/Joint3", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('c');
    else uart_gate.write('C');
    request->send(200, "text/html", index_html);
  });

  server.on("/Reverse", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) reverse_status = 1;
    else reverse_status = 0;
    request->send(200, "text/html", index_html);
  });
  
  server.on("/StepChange", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('s');;
    else uart_gate.write('S');
    request->send(200, "text/html", index_html);
  });
  
  server.on("/Turning", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('t');
    else uart_gate.write('T');
    request->send(200, "text/html", index_html);
  });
  
  server.on("/Rotate", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('r');
    else uart_gate.write('R');
    request->send(200, "text/html", index_html);
  });
  
  server.on("/Gripper", HTTP_GET, [](AsyncWebServerRequest *request){
    if(reverse_status == 0) uart_gate.write('g');
    else uart_gate.write('G');
    request->send(200, "text/html", index_html);
  });
  // Start server
  server.begin();
}
void loop(){}
