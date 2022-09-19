/*
* LED 8x8 DotMarix using Arduino
* Created by TheCircuit
*/

#include <LedControl.h>

int DIN = 8; 
int CS =  9;
int CLK = 10; 

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,1);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
    byte i[8] = {0x3C,0x3C,0x18,0x18,0x18,0x18,0x3C,0x3C};
    printByte(i);
    delay(1000);
    byte clear[8] = {};
    printByte(clear);
    delay(1000);
    delay(100);
    printByte(clear);

    byte h1[8] = {0x00,0x00,0x24,0x3C,0x3C,0x18,0x00,0x00};
    printByte(h1);
    delay(300);

    byte h2[8] = {0x00,0x66,0x7E,0x7E,0x7E,0x3C,0x18,0x00};
    printByte(h2);
    delay(300);
    
    byte heart[8] = {0x66,0xFF,0xFF,0xFF,0xFF,0x7E,0x3C,0x18};
    printByte(heart);
    delay(1000);

    printByte(h2);
    delay(300);

    printByte(h1);
    delay(300);

    printByte(h2);
    delay(300);

    printByte(heart);
    delay(1000);

    printByte(h2);
    delay(300);

    printByte(h1);
    delay(300);

    printByte(h2);
    delay(300);

    printByte(heart);
    delay(1000);
    
    printByte(clear);
    delay(1000);

    byte u[8] = {0x66,0x66,0x66,0x66,0x66,0x7E,0x7E,0x3C};
    printByte(u);
    delay(1000);

    printByte(clear);
    delay(1000);
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
