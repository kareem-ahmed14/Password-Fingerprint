#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38,16,2);
#include <Keypad.h>
const byte cols=4;
const byte rows=4; 
int counter=0;
int counter1=0;

byte button0=A0;
byte button1=A1;
byte button2=A2;
byte button3=A3;
byte button4=10;
byte button5=A5;

char g[4]={'1','3','4','5'};
char keys[rows][cols]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
 byte row_pins[]={2,3,4,5};
 byte col_pins[]={6,7,8,9};
Keypad myKeypad(makeKeymap(keys),row_pins,col_pins,rows,cols);
void setup() {
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0); 
lcd.print("Enter password:");
pinMode(button0,INPUT_PULLUP);
pinMode(button1,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
pinMode(button3,INPUT_PULLUP);
pinMode(button4,INPUT_PULLUP);
pinMode(button5,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
char m=myKeypad.getKey();
if(m){
 

if(m==g[counter]){
 counter1++; 
}
counter++; 
if(m=='D'){
  if(counter1>=4){
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("User authorized");
delay(3000);
lcd.clear();
counter=0;
counter1=0;
lcd.setCursor(0,0);

lcd.print("Enter your finger");
}
else{
   lcd.clear();
  lcd.setCursor(0,0);
lcd.print("Wrong password");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
counter=0;
counter1=0;
lcd.print("Enter your finger");
}

}
if(counter==1){
lcd.setCursor(0,1);
lcd.print("*");
}
if(counter==2){
lcd.setCursor(1, 1);
lcd.print("*");
}
if(counter==3){
lcd.setCursor(2, 1);
lcd.print("*");
}
if(counter==4){
lcd.setCursor(3, 1);
lcd.print("*");
}
if(m=='C'){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Enter password:");
counter=0;
counter1=0;
}
  
}
  if(!digitalRead(button0)){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ID is : 1");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
  }
   if(!digitalRead(button1)){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ID is : 2");
         delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
  }
   if(!digitalRead(button2)){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ID is : 3");
         delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
  }
   if(!digitalRead(button3)){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ID is : 4");
         delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
  }
   if(!digitalRead(button4)){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ID is : 5");
         delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
  }
   if(!digitalRead(button5)){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ID is : 6");
         delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
  }

}