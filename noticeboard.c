#include <LiquidCrystal.h>

char str[34],L=2;
int temp=0,i=0;
int Pass=0,p=0;
 int c,x,d;
 int LED1=6;
 int LED2=5;
 int Li          = 17;
int Lii         = 1; 
int Ri          = -1;
int Rii         = -1;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("BLUETOOTH CONTROLLED");
  lcd.setCursor(0,1);
  lcd.print("Speech Recognition");
  Serial.begin(9600);
   pinMode(LED1,OUTPUT);
 pinMode(LED2,OUTPUT);
}


void loop() 
{ 
  if(temp==1)
  {
    //check();
     temp=0;
    i=0;
    delay(1000);
  }

for (int i = 0; i <= 15; i++) {
    lcd.setCursor(0, 0);
    lcd.print(Scroll_LCD_Left("  BLUETOOTH CONTROLLED"));
     lcd.setCursor(0, 1);                                                
    lcd.print(Scroll_LCD_Left("SPEECH RECOGNITION SYSTEM"));
    delay(400);
   
  }
}

void serialEvent() {
while (Serial.available()) 
      {
      char inChar=Serial.read();
      str[i++]=inChar;
      delay(10);
      }
       for (p=i+1;p<34;p++)
      {
        str[i++]=32;
      }
    temp=1;
  Serial.write(str);
  Clear_Scroll_LCD_Left();    // Use if the text in the string is changed / different from before
  Clear_Scroll_LCD_Right();
  lcd.setCursor(0, 0);
 lcd.print(str);
  if(i>16)
  {
    d=16;
    for (x=0;x<=17;x++)
    {
    lcd.setCursor(x,2);
    lcd.print(str[d]);
    d++;
    }
  }
  delay(2000);
 if (str=="turn on LED")  
  {
    digitalWrite(LED1,HIGH);
   }

if (str=="turn off LED") 
  {
    digitalWrite(LED1,LOW);
   }
  
}
//----------------------------------
String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}
//----------------------------------
String Scroll_LCD_Right(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  if (Rii<1){
    Ri  = StrProcess.length();
    Rii = Ri-16;
  }
  result = StrProcess.substring(Rii,Ri);
  Ri--;
  Rii--;
  return result;
}

void Clear_Scroll_LCD_Right(){
  Ri=-1;
  Rii=-1;
}