#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;
int incoming2;
int currentState;

const int lsr[19] = {2,4,5,12,13, 14,15,16,17,18 ,19,21,22,23,25 ,26,27,32,33};
const int lsr_order[19] = {23,12,32,33,25,26,27,14,13, 15,2,4,16,17,5,18,19,21,22};

void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600

  
  ESP_BT.begin("TheOrchestraLaserSystem2"); //Name of your Bluetooth Signal
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

void all_off(){
      for (int i = 0; i < 20; i++){
        digitalWrite(lsr_order[i], LOW);
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

void loop_order3(){
  
            for (int i = 0; i < 18; i++){
          digitalWrite(lsr_order[i], HIGH);
          digitalWrite(lsr_order[i+1], HIGH);
          digitalWrite(lsr_order[i+2], HIGH);
          delay(50);
          digitalWrite(lsr_order[i], LOW);
          digitalWrite(lsr_order[i+1], LOW);
          digitalWrite(lsr_order[i+2], LOW);
          delay(50);
    }
}
void loop_random(){
    for (int i = 0; i < 20; i++){
        digitalWrite(lsr[i], HIGH);
        delay(50);
        digitalWrite(lsr[i], LOW);
        delay(50);
    }    
}

void loop_inverse(){
     for (int i = 0; i < 20; i++){
          digitalWrite(lsr_order[i], HIGH);
    }
    for (int i = 0; i < 20; i++){
          digitalWrite(lsr_order[i], LOW);
          delay(50);
          digitalWrite(lsr_order[i], HIGH);
          delay(50);
    }
    
    
}

void strobe(){
  all_on();
  delay(100);
  all_off();
  delay(100);
}

void loop_inverse3(){
     for (int i = 0; i < 20; i++){
          digitalWrite(lsr_order[i], HIGH);
    }
    for (int i = 0; i < 18; i++){
          digitalWrite(lsr_order[i], LOW);
          digitalWrite(lsr_order[i+1], LOW);
          digitalWrite(lsr_order[i+2], LOW);
          delay(50);
          digitalWrite(lsr_order[i], HIGH);
          digitalWrite(lsr_order[i+1], HIGH);
          digitalWrite(lsr_order[i+2], HIGH);
          delay(50);
    }
    
    
}


 
void loop() {

  
  
    if (ESP_BT.available()){
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); 
    Serial.println(incoming);



        if (incoming == 48){
          all_off();
        }
        
        if (incoming == 49){
            
                all_on();
        }
        
        if (incoming == 50){
            while(true){
              loop_order();
              
              incoming2 = ESP_BT.read();
              Serial.println("Received2:");
              Serial.println(incoming2);
              if(incoming2 == 48){
                break;
              }
            }
        }

        if (incoming == 51){
          while(true){

            strobe();            
            incoming2 = ESP_BT.read();
            Serial.println("Received2:");
            Serial.print(incoming2);
            if(incoming2 == 48){
                break;
            }
          }
        }

        if(incoming == 52){
          while(true){
            loop_inverse();
            incoming2 = ESP_BT.read();
            Serial.println("Received2:");
            Serial.println(incoming2);
            if(incoming2 == 48){
                break;
            }
          }
        }

                if(incoming == 53){
          while(true){
            loop_order3();
            incoming2 = ESP_BT.read();
            Serial.println("Received2:");
            Serial.println(incoming2);
            if(incoming2 == 48){
                break;
            }
          }
        }

//random
        if(incoming == 54){
            while(true){
              loop_inverse3();
              incoming2 = ESP_BT.read();
              Serial.println("Received2:");
              Serial.println(incoming2);
            if(incoming2 == 48){
                break;
            }
          }
        }
//pattern
        if(incoming == 55){
  while(true){
    
loop_random();
          
          incoming2 = ESP_BT.read();
          Serial.println("Received2:");
          Serial.println(incoming2);
          if(incoming2 == 48){
                break;
          }
  }

          
        }
        
    }
}