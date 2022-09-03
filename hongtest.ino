/*
 * UIPEthernet TcpClient example.
 *
 * UIPEthernet is a TCP/IP stack that can be used with a enc28j60 based
 * Ethernet-shield.
 *
 * UIPEthernet uses the fine uIP stack by Adam Dunkels <adam@sics.se>
 *
 *      -----------------
 *
 * This TcpClient example gets its local ip-address via dhcp and sets
 * up a tcp socket-connection to 192.168.0.1 port 5000 every 5 Seconds.
 * After sending a message it waits for a response. After receiving the
 * response the client disconnects and tries to reconnect after 5 seconds.
 *
 * Copyright (C) 2013 by Norbert Truchsess <norbert.truchsess@t-online.de>
 */

#include <UIPEthernet.h>

EthernetClient client;
signed long next;
#define PORT 65000
int a;
void setup() {
  
  Serial.begin(9600);
  
  uint8_t mac[6] = {0x00,0x01,0x02,0x03,0x04,0x05};
  Ethernet.begin(mac);

  Serial.print("localIP: ");
  Serial.println(Ethernet.localIP());
  Serial.print("subnetMask: ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("gatewayIP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("dnsServerIP: ");
  Serial.println(Ethernet.dnsServerIP());

  next = 0;
}

void loop() {
  a = analogRead(A0);
  
  if(a == 0){
    for(int k = 0; k < 2; k++){
      if (client.connect(IPAddress(112, 214, 41, 242),PORT))
        {
          
          Serial.println("Client connected");
          client.println("GET /danger?msg=danger1-1 HTTP/1.1");
          client.println();
          
          client.stop();
          delay(500);
          
          
        }
        
    }
    client.connect(IPAddress(127,0,0,1),60000);
    client.stop();
    
  }  
}
