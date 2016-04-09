/*
  library from: https://github.com/jcw/ethercard

*/
#include <EtherCard.h>

// for static ip use 1
#define STATIC 0

#if STATIC
  static byte myip[] = { 192, 168, 1, 200 };
  // Gateway
  static byte gwip[] = { 192, 168, 1, 1 };
#endif

// MAC Address da interface ethernet - deve ser único na sua rede local
static byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };

byte Ethernet::buffer[500];

const char page[] PROGMEM =
  "HTTP/1.0 200 OK\r\n"
  "Content-Type: text/html\r\n"
  "Refresh: 10\r\n"
  "\r\n"
  "<html>"
  "   <head>"
  "      <title>Arduino Web Server</title>"
  "   </head>"
  "   <body>"
  "      <h3>P&aacute;gina resposta do seu Arduino.</h3>"
  "      <p id='date'></p>"
  "      <script>"
  "          var d = new Date();"
  "          document.getElementById('date').innerHTML = d;"
  "      </script>"
  "   </body>"
  "</html>"
  ;

void setup() {
  Serial.begin(9600);
  Serial.println("[webserver]");

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
    Serial.println( "Failed to access Ethernet controller");
   
  #if STATIC
    ether.staticSetup(myip, gwip);
  #else
    if (!ether.dhcpSetup())
      Serial.println("DHCP failed");
  #endif

  ether.printIp("IP:\t", ether.myip);
  ether.printIp("GW:\t", ether.gwip);
  ether.printIp("DNS:\t", ether.dnsip);
}

void loop() {
  if (ether.packetLoop(ether.packetReceive())) {
    memcpy_P(ether.tcpOffset(), page, sizeof page);
    ether.httpServerReply(sizeof page - 1);
  }
}

