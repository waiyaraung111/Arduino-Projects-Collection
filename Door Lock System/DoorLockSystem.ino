#include <Keypad.h>
#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
int relay = 11;    // relay
const byte numRows= 4;          //number of rows on the keypad
const byte numCols= 4;          //number of columns on the keypad
 
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
 
char keypressed;   
char password[]= {'1','2','3','4'};  //The default code
 
char check1[sizeof(password)];  
char check2[sizeof(password)];  
 
short a=0,b=0,i=0,j=0;    
 
byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols]= {5,4,3,2}; 

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
 
void setup()
{
  lcd.init();      
  lcd.backlight();
  lcd.print("AustonUniversity");
  lcd.setCursor(0,1);
  lcd.print("DoorLockSystem");
  delay(3000);

  lcd.clear(); 
  lcd.print("*-unlock B-lock");
  lcd.setCursor(0,1);
  lcd.print("#-ChangePassword");
         
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);  // relay OFF
 
  // for(i=0 ; i<sizeof(password);i++){         //When you upload the code the first time keep it commented
  //  EEPROM.get(i, password[i]);               //Upload the code and change it to store it in the EEPROM
  // }                                          //Then uncomment this for loop and reupload the code (It's done only once) 
}
 
void loop()
{
  keypressed = myKeypad.getKey();  
    if(keypressed == '*'){      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter password"); 
      EnterPassword();              
        if (a==sizeof(password)) {   
        OpenDoor();
        }            
        else{
        lcd.clear();               
        lcd.print("Wrong password");  
        delay(2000);
        
        lcd.clear(); 
        lcd.print("*-unlock B-lock");
        lcd.setCursor(0,1);
        lcd.print("#-ChangePassword");
        }
    }
 
    if(keypressed == '#'){    
      ChangePassword();
      
      lcd.clear(); 
      lcd.print("*-Unlock B-Lock");
      lcd.setCursor(0,1);
      lcd.print("#-ChangePassword");
    }
 
     
    if(keypressed == 'B'){    
      
    lcd.clear();
    digitalWrite(relay, HIGH);
    lcd.print("Locked!");
    delay(2000); 
    lcd.clear(); 
    lcd.print("*-unlock B-lock");
    lcd.setCursor(0,1);
    lcd.print("#-ChangePassword");
    }     
}
 
void EnterPassword(){  
i=0; a=0; j=0;       
                              
  while(keypressed != 'A'){ 
    keypressed = myKeypad.getKey();                         
      if(keypressed != NO_KEY && keypressed != 'A' ){      
        lcd.setCursor(j,1);                 
        lcd.print("*");
        j++;
        if(keypressed == password[i]&& i<sizeof(password)){ 
          a++;                                              
          i++;
        }
        else{
          a--;
        }    
      }
  }
  keypressed = NO_KEY;
}

void OpenDoor(){             //Lock opening function open for 3s
  lcd.clear();
  lcd.print("Unlocked!");
  lcd.setCursor(0,1);
  lcd.print("Welcome Home..");
  digitalWrite(relay,LOW);  // relay ON
  }
 
void ChangePassword(){   
  lcd.clear();                   
  lcd.print("EnterOldPassword");
  EnterPassword();                      
      
    if(a==sizeof(password)){      
      lcd.clear();
      lcd.print("Changing password");
      GetNewPassword1();      
      GetNewPassword2();     
      b=0;

      for(i=0 ; i<sizeof(password) ; i++){   
        if(check1[i]==check2[i]){
          b++;
        }                                
      }
      if(b==sizeof(password)){            
      
      for(i=0 ; i<sizeof(password) ; i++){
      password[i]=check2[i];        
      EEPROM.put(i, password[i]);  
      }
      lcd.clear();
      lcd.print("Password Changed");
      delay(2000);
      }
      
      else{  
      lcd.clear();
      lcd.print("Passwords Are");
      lcd.setCursor(0,1);
      lcd.print(" Not Matching!!");
      delay(2000);
      }
    }
          else{ 
          lcd.clear();
          lcd.print("Wrong Password");
          delay(2000);
          }
}
 
void GetNewPassword1(){                      
  i=0;
  j=0;
  lcd.clear();
  lcd.print("EnterNewPassword");   
             
         while(keypressed != 'A'){            
             keypressed = myKeypad.getKey();
               if(keypressed != NO_KEY && keypressed != 'A' ){
                lcd.setCursor(j,1);
                lcd.print("*");              
                check1[i]=keypressed;     //Store characters in the array
                i++;
                j++;                    
                }
          }
          
keypressed = NO_KEY;
}
 
void GetNewPassword2(){     
  i=0;
  j=0;
  
  lcd.clear();
  lcd.print("ConfirmPassword");
 
         while(keypressed != 'A'){
             keypressed = myKeypad.getKey();
               if(keypressed != NO_KEY && keypressed != 'A' ){
                lcd.setCursor(j,1);
                lcd.print("*");
                check2[i]=keypressed;
                i++;
                j++;                    
                }
                }
keypressed = NO_KEY;
}