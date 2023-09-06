#include <Keypad.h>
#include <Key.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);
byte counter = 0 ;
byte pass_count = 0 ;
char pass[6]= {'1','2','3','4','5','6'};
char pas[6]={0};
char keys[4][4]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'},
};
byte i=0;
char y;
byte row_pins[]={2,3,4,5};
byte col_pins[]={6,7,8,9};
Keypad  myKeypad(makeKeymap(keys),row_pins,col_pins,4,4);

void setup() {
 lcd.init();
 lcd.backlight();
}
void loop() {
lcd.home();
lcd.setCursor(0,0);
lcd.print("Enter Password :"); 
  y = myKeypad.getKey();
  if(y){ 
    lcd.setCursor(i,1);
    lcd.print("*");
    i++;
    if (y=='C')
     {
  lcd.clear(); 
  lcd.home(); 
  lcd.print("Reset Password");  
  delay(2000);
  lcd.clear();     
  pass_count=0;counter=0;i=0 ;   
     }
  if (y!='D')
  {
  pas[counter++]=y; 
  if (i==6)i=0;
  }
    else{
for (byte i=0 ; i<=5 ; i++) 
{
if(pas[i]==pass[i])pass_count++;
} ///for
if (pass_count>=6){
lcd.clear();
lcd.home();  
lcd.setCursor(0,0);
lcd.print("Correct Password");
delay(1500);
lcd.clear();
lcd.home(); 
 pass_count=0;counter=0;i=0 ;
}
else{
lcd.clear();  
lcd.home();  
lcd.setCursor(1,0);
lcd.print("Wrong Password");
delay(1500);
lcd.clear();
lcd.home();   
counter=0;pass_count=0;i=0;
}    
} /// else 
} /// if y 
} ////loop