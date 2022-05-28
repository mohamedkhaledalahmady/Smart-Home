#include <SoftwareSerial.h>   
      
SoftwareSerial esp8266(2, 3);
#define serialCommunicationSpeed 9600
#define DEBUG true
int redLED = 13;
int blueLED = 12;
String data;
int pinNumber;
int pinState;
int connectionID;
String test = "+IPD,";

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, HIGH);
  Serial.begin(serialCommunicationSpeed);
  esp8266.begin(serialCommunicationSpeed);
  InitWifiModule();
  digitalWrite(blueLED, LOW);
}
void loop()
{
  if (esp8266.available())
  {
    data = esp8266.readString();
    Serial.println(data);
    Get_Pin_Number(data, &connectionID, &pinNumber, &pinState);
    Serial.print("connectionID: ");
    Serial.println(connectionID);
    Serial.print("pinNumber: ");
    Serial.println(pinNumber);
    Serial.print("pinState: ");
    Serial.println(pinState);
    digitalWrite(pinNumber, pinState);
    String closeCommand = "AT+CIPCLOSE=";
    closeCommand += connectionID;
    closeCommand += "\r\n";
    sendData(closeCommand, 1000, DEBUG);
  }
}
void Get_Pin_Number(String data, int* connectionID, int* pinNumber, int* pinState)
{
  int count = 0;
  int count2 = 0;
lable:
  if (data[count] == test[count2])
  {
    count++;
    count2++;
  }
  else
    count++;
  if (count2 <= 4)
    goto lable;
  *connectionID =  data[count] - '0';
  while (data[count] != '=')
    count++;
  count++;
  *pinNumber = (data[count++] - '0') * 10 + data[count++] - '0';
  *pinState = data[count] - '0';
}
String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (esp8266.available())
    {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}
void InitWifiModule()
{
  sendData("AT+RST\r\n", 2000, DEBUG);                                                  //reset the ESP8266 module.
  //delay(1000);
  sendData("AT+CWJAP=\"THEKING\",\"862021TOKA##\"\r\n", 2000, DEBUG);                   //connect to the WiFi network.
  delay (3000);
  sendData("AT+CWMODE=1\r\n", 1500, DEBUG);                                             //set the ESP8266 WiFi mode to station mode.
  delay (1000);
  sendData("AT+CIFSR\r\n", 1500, DEBUG);                                                //Show IP Address, and the MAC Address.
  delay (1000);
  sendData("AT+CIPMUX=1\r\n", 1500, DEBUG);                                             //Multiple conections.
  delay (1000);
  sendData("AT+CIPSERVER=1,80\r\n", 1500, DEBUG);                                       //start the communication at port 80, port 80 used to communicate with the web servers through the http requests.
}
