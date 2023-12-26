#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define PAUSE 0
#define pinSpk 7  //pino do speaker

int t1 = 20; //posição das notas na tela
int t2 = 22;
int t3 = 23;
int t4 = 27;
int t1b,t2b,t3b,t4b;
int t11b,t22b,t33b,t44b;
int t11,t22,t33,t44;
int escm = 2;
float tempo = 6.5;
int ini = 0;

LiquidCrystal_I2C lcd_1(0x27,20,4);

const int b1 = 6,b2 = 5,b3 = 4,b4 = 3;
int count1 = 0, count2 = 0,count3 = 0,count4 = 0;

void setup() {
  
  pinMode(pinSpk,OUTPUT);
  pinMode(b1, INPUT_PULLUP); //Botao 1
  pinMode(b2, INPUT_PULLUP); //Botao 2
  pinMode(b3, INPUT_PULLUP); //Botao 3
  pinMode(b4, INPUT_PULLUP); //Botao 4
  
  lcd_1.init();
  lcd_1.clear();
  lcd_1.setBacklight(HIGH);
  delay(200);

  lcd_1.print("O");
  lcd_1.setCursor(0, 1); //muda a linha e avança caracteres
  lcd_1.print("O"); //Printa na tela
  lcd_1.setCursor(0, 2);
  lcd_1.print("O");
  lcd_1.setCursor(0, 3);
  lcd_1.print("O");
  delay(500);

  //Marcha imperial
  tone(pinSpk,NOTE_G5,100*tempo); //Speaker (pino, frequência, duração)
  delay(100*tempo); //espera a nota acabar pra tocar a proxima
  lcd_1.setBacklight(LOW);
  
  tone(pinSpk,NOTE_G5,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_G5,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(LOW);
  tone(pinSpk,NOTE_DS5,75*tempo);
  delay(75*tempo);
  
  tone(pinSpk,NOTE_AS5,40*tempo);
  delay(40*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_G5,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(LOW);
  tone(pinSpk,NOTE_DS5,75*tempo);
  delay(75*tempo);
  
  tone(pinSpk,NOTE_AS5,40*tempo);
  delay(40*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_G5,200*tempo);
  delay(200*tempo);
  lcd_1.setBacklight(LOW);
  
  delay(100*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_D6,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(LOW);
  tone(pinSpk,NOTE_D6,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_D6,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(LOW);
  tone(pinSpk,NOTE_DS6,75*tempo);
  delay(75*tempo);
  
  tone(pinSpk,NOTE_AS5,40*tempo);
  delay(40*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_FS5,100*tempo);
  delay(100*tempo);
  
  lcd_1.setBacklight(LOW);
  tone(pinSpk,NOTE_DS5,75*tempo);
  delay(75*tempo);
  
  tone(pinSpk,NOTE_AS5,40*tempo);
  delay(40*tempo);
  
  lcd_1.setBacklight(HIGH);
  tone(pinSpk,NOTE_G5,200*tempo);
  delay(200*tempo);
  //Fim Marcha

}

void loop() {

  switch(escm)
  {
    case 1:
      // Sequencia para descer notas e mudar caractere
      lcd_1.setBacklight(HIGH);
      
      delay(125);
      
      t1--;
      t11 = t1 + 1;
      
      if(t11 >= 1 && t11 <= 20)
      {
        lcd_1.setCursor(t11, 0); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t1 >= 1 && t1 <= 20)
      {
        lcd_1.setCursor(t1, 0); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t1 == 0)
      {
        lcd_1.setCursor(0, 0); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b1))
        {
          tone(pinSpk, NOTE_F5, 30 * tempo);
        }
      }
      else
      {
        lcd_1.setCursor(0, 0);
        lcd_1.print("O");
      }
      
      // fim da sequencia
      
      // Sequencia 2
      
      t2--;
      t22 = t2 + 1;
      
      if(t22 >= 1 && t22 <= 20)
      {
        lcd_1.setCursor(t22, 1); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t2 >= 1 && t2 <= 20)
      {
        lcd_1.setCursor(t2, 1); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t2 == 0)
      {
        lcd_1.setCursor(0, 1); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b2))
        {
          tone(pinSpk, NOTE_D5, 30 * tempo);
        }
      }
      else
      {
        lcd_1.setCursor(0, 1);
        lcd_1.print("O");
      }
      // Fim da sequencia 2
      
      // Seq 3
      
      t3--;
      t33 = t3 + 1;
      
      if(t33 >= 1 && t33 <= 20)
      {
        lcd_1.setCursor(t33, 2); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t3 >= 1 && t3 <= 20)
      {
        lcd_1.setCursor(t3, 2); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t3 == 0)
      {
        lcd_1.setCursor(0, 2); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b3))
        {
          tone(pinSpk, NOTE_G5, 30 * tempo);
        }
      }
      else
      {
        lcd_1.setCursor(0, 2);
        lcd_1.print("O");
      }
      
      // Fim seq 3
      
      // sec4
      
      t4--;
      t44 = t4 + 1;
      
      if(t44 >= 1 && t44 <= 20)
      {
        lcd_1.setCursor(t44, 3); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t4 >= 1 && t4 <= 20)
      {
        lcd_1.setCursor(t4, 3); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t4 == 0)
      {
        lcd_1.setCursor(0, 3); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b4))
        {
          tone(pinSpk, NOTE_C5, 30 * tempo);
        }
      }
      else
      {
        lcd_1.setCursor(0, 3);
        lcd_1.print("O");
      }
      

      if(t1 < 0){
          t1 = 20;
      }
      if(t2 < 0){
          t2 = 22;
      }

      if(t3 < 0){
          t3 = 23;
      }
      if(t4 < 0){
          t4 = 27;
      }
      
      // fim sec4
      
      break;
      
    case 2:
      if(ini == 0){
        t1 = 20;
        t2 = 24;
        t3 = 29;
        t4 = 32;
        t1b = 42;
        t2b = 43;
        t3b = 37;
        t4b = 34;
      }

      lcd_1.setBacklight(HIGH);
      
      delay(125);
      
      t1--;
      t11 = t1 + 1;
      
      if(t11 >= 1 && t11 <= 20)
      {
        lcd_1.setCursor(t11, 0); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t1 >= 1 && t1 <= 20)
      {
        lcd_1.setCursor(t1, 0); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t1 == 0)
      {
        lcd_1.setCursor(0, 0); // Muda para 0
        lcd_1.print("0");
        if((!digitalRead(b1)) && (count1 = 0))
        {
          tone(pinSpk,NOTE_D5,150*tempo);
        }
          else if((!digitalRead(b1)) && (count1 = 1)){
          tone(pinSpk,NOTE_C5,100*tempo);
          }
        count1++;
      }
      else
      {
        lcd_1.setCursor(0, 0);
        lcd_1.print("O");
      }
      
      // fim da sequencia

      // Sec 1B

      t1b--;
      t11b = t1b + 1;
      
      if(t11b >= 1 && t11b <= 20)
      {
        lcd_1.setCursor(t11b, 0); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t1b >= 1 && t1b <= 20)
      {
        lcd_1.setCursor(t1b, 0); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t1b == 0)
      {
        lcd_1.setCursor(0, 0); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b1))
        {
           tone(pinSpk,NOTE_C6,25*tempo);;
        }
        count1++;
      }
      else
      {
        lcd_1.setCursor(0, 0);
        lcd_1.print("O");
      }

      // Fim Sec 1B 
      
      // Sequencia 2
      
      t2--;
      t22 = t2 + 1;
      
      if(t22 >= 1 && t22 <= 20)
      {
        lcd_1.setCursor(t22, 1); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t2 >= 1 && t2 <= 20)
      {
        lcd_1.setCursor(t2, 1); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t2 == 0)
      {
        lcd_1.setCursor(0, 1); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b2))
        {
           tone(pinSpk,NOTE_G5,150*tempo);
        }
        count2++;
      }
      else
      {
        lcd_1.setCursor(0, 1);
        lcd_1.print("O");
      }
      
      // Fim da sequencia 2

      // Sec 2B

      t2b--;
      t22b = t2b + 1;
      
      if(t22b >= 1 && t22b <= 20)
      {
        lcd_1.setCursor(t22b, 1); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t2b >= 1 && t2b <= 20)
      {
        lcd_1.setCursor(t2b, 1); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t2b == 0)
      {
        lcd_1.setCursor(0, 1); // Muda para 0
        lcd_1.print("0");
        if(!digitalRead(b1))
        {
           tone(pinSpk,NOTE_AS5,25*tempo);
        }
        count2++;
      }
      else
      {
        lcd_1.setCursor(0, 1);
        lcd_1.print("O");
      }

      // Fim Sec 2B 
      
      // Seq 3
      
      t3--;
      t33 = t3 + 1;
      
      if(t33 >= 1 && t33 <= 20)
      {
        lcd_1.setCursor(t33, 2); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t3 >= 1 && t3 <= 20)
      {
        lcd_1.setCursor(t3, 2); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t3 == 0)
      {
        lcd_1.setCursor(0, 2); // Muda para 0
        lcd_1.print("0");
        if((!digitalRead(b3)) && (count3 == 0))
        {
           tone(pinSpk,NOTE_C5,100*tempo);
        }
          else if ((!digitalRead(b3)) && (count3 == 2)){
              tone(pinSpk,NOTE_A5,50*tempo);
          }
        if(count3 == 0){
          t3 = 15;
        }
        count3++;
      }
      else
      {
        lcd_1.setCursor(0, 2);
        lcd_1.print("O");
      }
      
      // Fim seq 3

      // Sec 3B
      t3b--;
      t33b = t3b + 1;
      
      if(t33b >= 1 && t33b <= 20)
      {
        lcd_1.setCursor(t33b, 2); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t3b >= 1 && t3b <= 20)
      {
        lcd_1.setCursor(t3b, 2); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t3b == 0)
      {
        lcd_1.setCursor(0, 2); // Muda para 0
        lcd_1.print("0");
        if((!digitalRead(b3)) && (count3 == 1))
        {
           tone(pinSpk,NOTE_A5,150*tempo);
        }
          else if ((!digitalRead(b3)) && (count3 == 3)){
              tone(pinSpk,NOTE_G5,150*tempo);
          }
        if(count3 == 1){
          t3b = 15;
        }
        
        count3++;

      }
      else
      {
        lcd_1.setCursor(0, 2);
        lcd_1.print("O");
      }
      // Fim Sec 3B
      
      // sec4
      
      t4--;
      t44 = t4 + 1;
      
      if(t44 >= 1 && t44 <= 20)
      {
        lcd_1.setCursor(t44, 3); // limpa o caractere anterior
        lcd_1.print(" ");
      }
      
      if(t4 >= 1 && t4 <= 20)
      {
        lcd_1.setCursor(t4, 3); // Notas na tela
        lcd_1.print("X");
      }
      
      if(t4 == 0)
      {
        lcd_1.setCursor(0, 3); // Muda para 0
        lcd_1.print("0");
        if((!digitalRead(b4)) && (count4 == 0))
        {
          tone(pinSpk,NOTE_G5,150*tempo);
        }
        else if ((!digitalRead(b4)) && (count4 == 1)){
            tone(pinSpk,NOTE_F5,150*tempo);
          }
        if(count4 == 0){
          t4 = 14;
        }
        count4++;
      }
      else
      {
        lcd_1.setCursor(0, 3);
        lcd_1.print("O");
      }
      ini++;
      
      break;
      
    default:
      lcd_1.setBacklight(HIGH); // Liga a Tela
      delay(500);
      lcd_1.setBacklight(LOW); // Desliga a tela
      delay(400);
      
      if(!digitalRead(b1))
      {
        escm = 1;
      }
      if(!digitalRead(b2))
      {
        escm = 2;
      }
      if(!digitalRead(b3))
      {
        escm = 3;
      }
      if(!digitalRead(b4))
      {
        escm = 4;
      }
  }
}
