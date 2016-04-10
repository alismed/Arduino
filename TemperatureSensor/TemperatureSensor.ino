
/*
  Temperature sensor LM35
  with
  EtherCard library from: https://github.com/jcw/ethercard
*/

#include <EtherCard.h>

int pin = 0;           // analogic pin
float tempc = 0;       // Celsius
float tempf = 0;       // Celsius and Fahrenheit
float rawVoltage = 0;  // to convert volts in degree
float milliVolts = 0;  //  to convert volts in degree

long t = 0;            // to show the time
word h;                // to show the time
byte m;                // to show the time
byte s;                // to show the time

// MAC Address da interface ethernet, should be uniq
static byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };
byte Ethernet::buffer[500];


char bufferf[5];       // to convert float to string
char bufferc[5];       // to convert float do string
BufferFiller bfill;    // to print the web page

void setup() {
  Serial.begin(9600);

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
    Serial.println( "Failed to access Ethernet controller");

  if (!ether.dhcpSetup())
    Serial.println("DHCP failed");

  ether.printIp("IP:\t", ether.myip);
  ether.printIp("GW:\t", ether.gwip);
  ether.printIp("DNS:\t", ether.dnsip);
}

static word homePage() {
  t = millis() / 1000;
  h = t / 3600;
  m = (t / 60) % 60;
  s = t % 60;

  String celsiusValue = dtostrf(tempc, 3, 2, bufferc);
  String fahrenheittValue = dtostrf(tempf, 4, 3, bufferf);

  bfill = ether.tcpOffset();

  bfill.emit_p(PSTR(
                 "HTTP/1.0 200 OK\r\n"
                 "Content-Type: text/html\r\n"
                 "Pragma: no-cache\r\n"
                 "\r\n"
                 "<meta http-equiv='refresh' content='1'/>"
                 "<title>RBBB server</title>"
                 "<h1>$D$D:$D$D:$D$D</h1>"
                 "<p>$S C - $S F</p>"),
               h / 10, h % 10, m / 10, m % 10, s / 10, s % 10, celsiusValue.c_str(), fahrenheittValue.c_str());
  return bfill.position();
}

void loop() {
  rawVoltage = analogRead(pin);
  milliVolts = (rawVoltage / 1024.0) * 5000;
  tempc = milliVolts / 10;
  tempf = (tempc * 9) / 5 + 32;

  Serial.print(tempc, 2);
  Serial.print("  ºC\t");
  Serial.print(tempf, 2);
  Serial.println(" ºF\t");

  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);

  if (pos)  // check if valid tcp data is received
    ether.httpServerReply(homePage()); // send web page data

  tempc = 0;
  tempf = 0;
}


