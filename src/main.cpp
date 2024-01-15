#include <Wire.h>


int I2C_sda = 8;
int I2C_scl = 9;

 
void setup() 
{
  Wire.setSDA(I2C_sda);
  Wire.setSCL(I2C_scl);
  Wire.begin();
  Serial.begin(115200);
  

  while (!Serial);
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  //  for(address = 1; address < 127; address++ ) {
  for ( int address = 0x00; address < 0x80; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
      {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknow error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }
  delay(5000);
}