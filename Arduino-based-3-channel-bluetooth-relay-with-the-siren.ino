// Developed by Maxim Bortnikov
// This code was automatically generated here: https://remotexy.com/en/
// For more information and for the circuit visit: https://github.com/Northstrix/Arduino-based-3-channel-bluetooth-relay-with-the-siren
// You can download RemoteXY app here: https://remotexy.com/en/download/


#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,0,0,68,0,10,25,0,
  2,0,9,7,29,13,31,26,25,24,
  79,78,0,79,70,70,0,2,0,9,
  25,29,13,31,26,25,24,79,78,0,
  79,70,70,0,2,0,9,43,29,13,
  31,26,25,24,79,78,0,79,70,70,
  0,1,0,55,13,37,37,204,31,83,
  105,114,101,110,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t button_1; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

#define PIN_SWITCH_1 10
#define PIN_SWITCH_2 11
#define PIN_SWITCH_3 12
#define PIN_BUTTON_1 9


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  pinMode (PIN_BUTTON_1, OUTPUT);
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
  


}
