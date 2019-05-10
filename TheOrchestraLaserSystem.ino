
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;

const int lsr[19] = {2,4,5,12,13, 14,15,16,17,18 ,19,21,22,23,25 ,26,27,32,33};
const int lsr_order[19] = {23,12,32,33,25,26,27,14,13, 15,2,4,16,17,5,18,19,21,22};

void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("TheOrchestraLaserSystem"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
 
}
 
void loop() {
    if (ESP_BT.available()){
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); 
    Serial.println(incoming);
        if (incoming == 49){
            while (true){
                all_on();
            }
            
        }
        
        if (incoming == 48){
            while(true){
                loop_order();
            }      
        }   
}



void all_on(){
    for (int i = 0; i < 20; i++){
        digitalWrite(lsr_order[i], HIGH);
    }
}
 
void loop_order(){
        for (int i = 0; i < 20; i++){
          digitalWrite(lsr_order[i], HIGH);
          delay(50);
          digitalWrite(lsr_order[i], LOW);
          delay(50);
    }
}

void loop_random(){
    for (int i = 0; i < 20; i++){
        digitalWrite(lsr_order[i], HIGH);
        delay(50);
        digitalWrite(lsr_order[i], LOW);
        delay(50);
    }    
}