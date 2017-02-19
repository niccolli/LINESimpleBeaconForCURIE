#include <CurieBLE.h>

BLEService lineService("FE6F"); // "0xFE6F" 16bits UUID of LINE
BLEPeripheral ble;

void setup() {
  Serial.begin(9600);

  ble.setAdvertisedServiceUuid(lineService.uuid());
  unsigned char data[19] = {0x02, 0x01, 0x00, 0x4b, 0x58, 0xc7, 0x7f, 0x00};
  ble.setAdvertisedServiceData(lineService.uuid(), data, 8);

  ble.begin();
}

void loop() {

}
