//// Datum 06-06-2018
//// Board Nano
//// Programmer USBasp


int relais1=8; //Relais Input 1
int relais2=9; //Relais Input 2
int relais3=10; //Relais Input 3
int relais4=11; //Relais Input 3

int RC11= 14; /// RC Signal Port CH11
int RC11d ; /// RC Signal
int RC12= 15; /// RC Signal Port CH12
int RC12d ; /// RC Signal
int RC13= 16; /// RC Signal Port CH13
int RC13d ; /// RC Signal
int RC14= 18; /// RC Signal Port CH13
int RC14d ; /// RC Signal


int CheckMode = 0;

unsigned long previousMillis = 0; ///Zeitaufnahme starten
unsigned long currentMillis = 0;

const long interval = 10000;
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial toDuino (12,13);  //12 RX ----13 TX //



int Status=0; // Systemstatus 0= sleep 1=Wakeup 2=Run 3=Shutdown

int Sensor = 7;

int DriveMode() {

            //Serial.println("3-3 Move Mode ");
            digitalWrite(relais1, LOW);
            digitalWrite(relais2, LOW);
            digitalWrite(relais3, LOW);
            digitalWrite(relais4, LOW);
            toDuino.print("@3MMOVE MODE \r");
            toDuino.print("@3T100\r");
            delay(2000);
            
}

int MoveMode(){

          //Serial.println("Drive Mode ");     
          digitalWrite(relais1, HIGH);   
          digitalWrite(relais2, HIGH);  
          digitalWrite(relais3, HIGH);  
          digitalWrite(relais4, HIGH);  
          
         
          
          
}


void setup() //Hier beginnt das Setup.
{
// initialize serial:
Serial.begin(9600);  
toDuino.begin(9600);

pinMode(relais1, OUTPUT); //Hauptenergie.
pinMode(relais2, OUTPUT); //Sound
pinMode(relais3, OUTPUT); //Dome
pinMode(relais4, OUTPUT); //Dome

pinMode(Sensor, INPUT); //Der Pin mit dem RC Eingang

pinMode(RC11, INPUT);
pinMode(RC12, INPUT);
pinMode(RC13, INPUT);
pinMode(RC14, INPUT);




}

void loop() //Der Loop-Teil beginnt
{ 
        
       // Serial.print("data: ");
       // Serial.println(pirValue);
    CheckMode = pulseIn(Sensor,HIGH);
    //Serial.print("CheckMode ");
    //Serial.println(CheckMode);

    RC11d = pulseIn(RC11,HIGH);
    RC12d = pulseIn(RC12,HIGH);
    RC13d = pulseIn(RC13,HIGH);
    RC14d = pulseIn(RC14,HIGH);
    
    //Serial.print("RC11 =  ");
    //Serial.println(RC11d);
  

    //if ((RC11d >= 900) && (RC11d <= 1300)) { Serial.print ("rc11 top"); }   
    if ((RC11d >= 900) && (RC11d <= 1300)) { 
      
      Serial.print (":SE07\r");
      delay(500);
      toDuino.print(":SE07\r");
      delay(1000);
      
      }   
      
    //if ((RC11d >= 1350) && (RC11d <= 1500)) { Serial.print ("rc11 null");}


     // if ((RC11d >= 1550) && (RC11d <= 2000)) { Serial.print ("rc11 down");}
    if ((RC11d >= 1550) && (RC11d <= 2000)) { 
     Serial.print (":SE13\r");
      delay(500);
      toDuino.print(":SE13\r");
      toDuino.print("@3T1\r");
      delay(1000);
      }
    
    

    //Serial.print("RC12 =  ");
    //Serial.println(RC12d);

    //RC12 top
    if ((RC12d >= 900) && (RC12d <= 1300)) {
      Serial.print (":OP11\r");
      delay(500);
      toDuino.print(":OP11\r");
      delay(1000);
      
      }   
    //if ((RC12d >= 1350) && (RC12d <= 1500)) { Serial.print ("rc12 null");}

    //RC12 Down
    
    if ((RC12d >= 1550) && (RC12d <= 2000)) { 
       
       
       toDuino.print(":SE14\r");
       delay(1000);
       
      }
    

    //Serial.print("RC13 =  ");
    //Serial.println(RC13d);

    //if ((RC13d >= 900) && (RC13d <= 1300)) { Serial.print ("rc13 top");}   

    if ((RC13d >= 900) && (RC13d <= 1300)) { 
      Serial.print (":OP02\r");
       toDuino.print(":OP02\r");
       delay(1000);
       toDuino.print("$28\r");
       delay(1000);
      }   

    
    //if ((RC13d >= 1350) && (RC13d <= 1500)) { Serial.print ("rc13 null");}

    
    //if ((RC13d >= 1550) && (RC13d <= 2000)) { Serial.print ("rc13 down");}
    if ((RC13d >= 1550) && (RC13d <= 2000)) { 
      Serial.print (":OP04\r");
      toDuino.print(":OP04\r");
       delay(1000);
       toDuino.print("$29\r");
       delay(1000);
      }


    

    //Serial.print("RC14 =  ");
    //Serial.println(RC14d);

    //if ((RC14d >= 900) && (RC14d <= 1300)) { Serial.print ("rc14 top");} 
    if ((RC14d >= 900) && (RC14d <= 1300)) { 
      Serial.print (":OP05\r");
      toDuino.print(":OP05\r");
       delay(1000);
       toDuino.print("$21\r");
       delay(1000);
       
      } 
      
    //if ((RC14d >= 1350) && (RC14d <= 1500)) { Serial.print ("rc14 null");}
    //if ((RC14d >= 1550) && (RC14d <= 2000)) { Serial.print ("rc14 down");}
     if ((RC14d >= 1550) && (RC14d <= 2000)) { 
      Serial.print (":OP06\r");
      toDuino.print(":OP06\r");
      delay(1000);
      toDuino.print("$22\r");
      delay(1000);
      }
    

    if (CheckMode <= 1000)
    {
      DriveMode();

     // Serial.print(":CL00\r");
     // toDuino.print(":CL00\r");
                  
      delay(1000);
      
    } else {
      MoveMode();
    //  Serial.print(":OP00\r");
    //  toDuino.print(":OP00\r");
       delay(1000);
    }

    
 
    
                    
        
       
          
} //Mit dieser letzten Klammer wird der Loop-Teil geschlossen.



