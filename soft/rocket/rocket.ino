#include <TinyGPS++.h>

#include <qbcan.h>
#include <Wire.h>
#include <SPI.h>
#include "rocket.h"


//Radio Parameters
#define NODEID        2    //unique for each node on same network
#define NETWORKID     100  //the same on all nodes that talk to each other
#define GATEWAYID     1    //Receiving node
#define ENCRYPTKEY    "sampleEncryptKey" //exactly the same 16 characters/bytes on all nodes!

RFM69 radio;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Rocket start!"));

  //Initialize radio
  radio.initialize(FREQUENCY, NODEID, NETWORKID);
  radio.setHighPower();
  radio.encrypt(ENCRYPTKEY);
}

void loop() {
  receive_gps();
  prepare_data();
  radio.send(GATEWAYID, my_tx_buffor, strlen(my_tx_buffor));
  Serial.println("Send complete");
}


