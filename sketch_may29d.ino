#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
float temp;float volt;float readin;
int motor = 9;int led =13;
int button=8;
int state=LOW;
int previous = LOW; 
int reading;
void setup() {
lcd.begin(16,2);
lcd.setCursor(0,0);lcd.print("System Activated");delay(2000);lcd.clear();
lcd.setCursor(0,1);lcd.print("T=");lcd.setCursor(10,1);lcd.print("C");Serial.begin(9600);
pinMode(led,OUTPUT);pinMode(motor,OUTPUT);
pinMode(button,INPUT);
}

void loop() {
  reading= digitalRead(button);
  if (reading == HIGH && previous == LOW )
  {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
  }
    previous = reading;
  //cntrl----------------------------------------------------------------------------------------automatique 
 readin=analogRead(0);delay(10);
  Serial.print("analog temp est");Serial.print(volt);
   volt=readin*5/1024;//calcul voltage
   temp=volt*100;//calcul temp
   
   
  Serial.print("temperature est");Serial.println(temp);
  
  
    lcd.setCursor(3,1);lcd.print(temp); 
 if (temp>=100||state == HIGH) 
  { 
      digitalWrite(led,HIGH);delay(100);
      digitalWrite(led,LOW);delay(80);
    
    lcd.setCursor(0,0);lcd.print("go to P/N mode"); 
   digitalWrite(motor,HIGH);
   
    }       
  else if (temp<100||state == LOW)
  { digitalWrite(led,LOW);
    digitalWrite(motor,LOW);
    lcd.setCursor(0,0);lcd.setCursor(0,0);lcd.print("______________");
    
    }
    //cntrl----------------------------------------------------------------------------------------manual
    return temp;
}
