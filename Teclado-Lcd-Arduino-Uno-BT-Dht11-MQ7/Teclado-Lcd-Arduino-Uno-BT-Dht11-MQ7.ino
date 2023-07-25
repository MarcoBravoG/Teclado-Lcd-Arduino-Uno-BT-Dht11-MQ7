#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //
#include <Keypad.h>

int limite;
int a=0;
int b=0;
//////////////////////////////////////////////////////////////

#include "DHT.h"

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11

////////////////////////////////////////////////////////////////
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

const int DHTPin = 2;     // what digital pin we're connected to

DHT dht(DHTPin, DHTTYPE);

const byte rowsCount = 4;
const byte columsCount = 4;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { 11, 10, 9, 8 };
const byte columnPins[columsCount] = { 7, 6, 5, 4 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 
void setup() {
   Serial.begin(9600);
   lcd.init();                         // Se inicializa el LCD 16x2
   lcd.backlight();                           
   lcd.clear(); 
   pinMode(13,OUTPUT); //ventilador   
   pinMode(12,OUTPUT); //led Verde
   // Serial.println("DHTxx test!");
   dht.begin();

}
 
void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

         char key = keypad.getKey();
         limite=analogRead(0);
         
         if (key) {
          lcd.setCursor(0,0);                  
          lcd.print("k: ");
          lcd.print(key);
           }

          lcd.print(" Co2: ");
          lcd.print(limite);


          lcd.setCursor(0,1);                

          lcd.print("H: ");
          lcd.print(h);
          lcd.print("T: ");
          lcd.print(t);

        // puerto serial
        /*
           Serial.print(" Key: ");         
           Serial.print(key);
           Serial.print(" Co2: ");         
           Serial.print(limite);
           Serial.print(" H: ");
           Serial.print(h);
           Serial.print(" %");
           Serial.print(" T: ");
           Serial.print(t);
           Serial.println("*C");
*/
            if(key=='1'){        
             Serial.print(" Co2: ");         
             Serial.println(limite);
             }
            
             if(key=='2'){        
           Serial.print(" H: ");
           Serial.print(h);
           Serial.print(" %");
             }
             
             if(key=='3'){                       
           Serial.print(" T: ");
           Serial.print(t);
           Serial.println("*C");
             }

             

        // accion neuronal

        if(a=1){
        digitalWrite(13,HIGH);

          }
          else{
            digitalWrite(13,LOW);
           } 

         if(b=1){
        digitalWrite(12,HIGH);
          }
          else{
            digitalWrite(12,LOW);
           } 



           delay(100);
   
}