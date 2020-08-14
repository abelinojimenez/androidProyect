#include <VirtualWire.h>
const int dataPin=9;
//const int ledPin=12;
void setup() {
  vw_setup(2000);
  vw_set_rx_pin(dataPin);
  vw_rx_start();
}

void loop() {
  // declaramos los tipos de datos que se leen
  uint8_t data;
  uint8_t dataLength=8;
  if(vw_get_message(&data,&dataLength)){
    ///  if(atoi(data)==254){
        
       // }else{
          
       // }
       Serial.println((char *)data);
    
    }
}
