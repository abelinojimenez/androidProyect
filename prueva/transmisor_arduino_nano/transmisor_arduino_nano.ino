
#include <VirtualWire.h>
const int dataPin=9;
float temperatura;
float pintemp=0;
void setup() {
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_tx_pin(dataPin);
}

void loop() {
// leemos la temperatura
  temperatura = analogRead(pintemp);
  //aplicamos la formula para conocerla 
  temperatura = (5.0 * temperatura * 100.0)/1024.0; 
    // declaramos una varible donde almacenaremos los 
    char data[8];
    // se convierte el float a char para poderlo enviar
    dtostrf(temperatura, 6, 2, data);

    //se envia por el pin 9 pwn ose dataPin
    vw_send((uint8_t *)data,sizeof(data));
    // esperar
    vw_wait_tx();
    //se espera cierto tiempo 200 milisegundos para la proxima lectura
    delay(200);
}
