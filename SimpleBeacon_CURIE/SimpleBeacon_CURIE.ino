#include <CurieBLE.h>

BLEService lineService("FE6F"); // "0xFE6F" 16bits UUID of LINE
BLEPeripheral ble;

// LINE Simple Beacon Frame
const unsigned char FrameType = 0x02;                         // 0x02のみ使用可
const unsigned char HWID[5] = {0x01, 0x00, 0x4b, 0x58, 0xc7}; // 各自が取得したHWIDを使用
const unsigned char MeasuredTxPower = 0x7F;                   // 0x7Fのみ使用可

unsigned char MessageLength = 1                               // 最大13bytesまで使用可
unsigned char DeviceMessage[MessageLength] = {0x00};          // 未使用の場合は0x00を設定する

void setup() {
  Serial.begin(9600);

  ble.setAdvertisedServiceUuid(lineService.uuid());
  unsigned char data[19] = {0x02, 0x01, 0x00, 0x4b, 0x58, 0xc7, 0x7f, 0x00};
  ble.setAdvertisedServiceData(lineService.uuid(), data, (MessageLength + 7));

  ble.begin();
}

void loop() {

}
