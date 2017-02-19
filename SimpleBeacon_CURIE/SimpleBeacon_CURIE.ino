#include <CurieBLE.h>
#include <string.h>

BLEService lineService("FE6F"); // "0xFE6F" 16bits UUID of LINE
BLEPeripheral ble;

// LINE Simple Beacon Frame
const unsigned char FrameType = 0x02;                         // 0x02のみ使用可
const unsigned char HWID[5] = {0x01, 0xde, 0xad, 0xfa, 0xce}; // 各自が取得したHWIDを使用
const unsigned char MeasuredTxPower = 0x7F;                   // 0x7Fのみ使用可

# define MAX_MESSAGE_LENGTH 13
unsigned char DeviceMessage[MAX_MESSAGE_LENGTH] = {0x00};     // 未使用の場合は0x00を設定する

#define MAX_FRAME_LENGTH MAX_MESSAGE_LENGTH+1+5+1

void createBeaconFrameData(unsigned char *data){
  data[0] = FrameType;
  memcpy(&data[1], HWID, 5);
  data[6] = MeasuredTxPower;
  memcpy(&data[7], DeviceMessage, MAX_MESSAGE_LENGTH);
}

void setup() {
  Serial.begin(9600);

  ble.setAdvertisedServiceUuid(lineService.uuid());

  // フレームを設定する
  unsigned char data[MAX_FRAME_LENGTH] = {0x00};
  createBeaconFrameData(data);
  ble.setAdvertisedServiceData(lineService.uuid(), data, MAX_FRAME_LENGTH);

  ble.begin();
}

void loop() {

}
