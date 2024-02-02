#include <WiFiManager.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#include  "mountHtmlPage.h"

#define TRACE(...) Serial.println(__VA_ARGS__)

#define HOST_SSID_NETWORK "ESP-DRIVER"
#define HOST_PASSWORD_NETWORK "strongpass"

const uint16_t kRecvPin = 4;
const uint16_t buttonStartKRecv = 5;
const uint16_t relay1 = 3;
const uint16_t relay2 = 15;
const uint16_t relay3 = 13;
const uint16_t relay4 = 12;
const uint16_t relay5 = 14;

const uint16_t keyArrowUp     = 683865;
const uint16_t keyArrowCenter = 49140;
const uint16_t keyArrowRight  = 692055;
const uint16_t keyArrowLeft   = 696150;
const uint16_t keyArrowDown   = 687960;


bool isIRrecvEnable;
IRrecv irrecv(kRecvPin);
decode_results results;

WiFiManager wm;
ESP8266WebServer webServer(80);

void toggle(uint16_t pin){
  
  if (digitalRead(pin)==0){
    digitalWrite(pin, HIGH);
    delay(50);
  }else{
    digitalWrite(pin, LOW);
    delay(50);

  }
}

void switchValues(decode_results results){
   switch(results.value){
      case keyArrowUp:
        TRACE("UP");
        toggle(relay1);
        break;

      case keyArrowDown:
        TRACE("DOWN");
        toggle(relay2);
        break;

      case keyArrowLeft:
        TRACE("LEFT");
        toggle(relay3);
        break; 

      case keyArrowRight:
        TRACE("RIGHT");
        toggle(relay4);
        break; 

      case keyArrowCenter:
        TRACE("CENTER");
        toggle(relay5);
        break; 
    }
}


void handleRemoteControl(){

  bool buttonRecvValue = digitalRead(buttonStartKRecv);

  if (buttonRecvValue == 0) {
    isIRrecvEnable = !isIRrecvEnable;
    
    Serial.println("button pressed");

    if (isIRrecvEnable == 1){
      irrecv.enableIRIn();
      TRACE("IR demodulator ON");
      TRACE("Waiting IR signal.");
      delay(500);
    }else{
      irrecv.disableIRIn();
      TRACE("IR demodulator OFF");
      delay(500);

    }

    delay(500);
  }


  if(irrecv.decode(&results)){
    switchValues(results);
    serialPrintUint64(results.value);
    TRACE("");
    irrecv.resume();
  }
}


void configModeCallback(WiFiManager *myWiFiManager){
 Serial.println("Entered config mode");
 Serial.println(WiFi.softAPIP());
 Serial.println(myWiFiManager->getConfigPortalSSID());
  ESP.restart();
}


void connectWiFi(){
  wm.setAPCallback(configModeCallback);
  bool connected = wm.autoConnect(HOST_SSID_NETWORK, HOST_PASSWORD_NETWORK);

  while(!connected){
    delay(500);
    Serial.print(".");
  }
  
  TRACE("connected.\n");
}


void handleRoot() {

  String htmlPage = mountHtmlPage(
    relay1,
    relay2,
    relay3,
    relay4,
    relay5
  );
 
    webServer.send(200, "text/html", htmlPage);
}


void handlePostSubmit(){
  if (webServer.method() != HTTP_POST){
    webServer.send(405, "text/plain", "Method not allowed.");
  }else{

    String plainTextData = webServer.arg("plain");

    // Obtém o valor de cada relé usando indexOf e substring
    int relay1Index = plainTextData.indexOf("relay1=");
    int relay2Index = plainTextData.indexOf("relay2=");
    int relay3Index = plainTextData.indexOf("relay3=");
    int relay4Index = plainTextData.indexOf("relay4=");
    int relay5Index = plainTextData.indexOf("relay5=");

    // Os índices indicam onde cada relé começa na string
    // Adicione 7 aos índices para pular "relayX=" e obter o valor do relé
    int relay1Value = plainTextData.substring(relay1Index + 7, relay2Index).toInt();
    int relay2Value = plainTextData.substring(relay2Index + 7, relay3Index).toInt();
    int relay3Value = plainTextData.substring(relay3Index + 7, relay4Index).toInt();
    int relay4Value = plainTextData.substring(relay4Index + 7, relay5Index).toInt();
    int relay5Value = plainTextData.substring(relay5Index + 7).toInt();

    // Agora você pode usar relay1Value, relay2Value, etc., como inteiros
    digitalWrite(relay1, relay1Value);
    digitalWrite(relay2, relay2Value);
    digitalWrite(relay3, relay3Value);
    digitalWrite(relay4, relay4Value);
    digitalWrite(relay5, relay5Value);
      
    String htmlPage = mountHtmlPage(
      relay1,
      relay2,
      relay3,
      relay4,
      relay5
    );

   webServer.send(200, "text/html", htmlPage);

  }

}


void setup() {

  pinMode(buttonStartKRecv, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, LOW);

  Serial.begin(9600);
  while (!Serial) delay(500);
  
  isIRrecvEnable = false;

  connectWiFi();
  webServer.on("/", HTTP_GET, handleRoot);
  webServer.on("/", HTTP_POST, handlePostSubmit);
  webServer.begin();

}

void loop() {

  handleRemoteControl();
  webServer.handleClient();
  delay(100);
}