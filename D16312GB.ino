/****************************************************/
/* This is only one example of code structure       */
/* OFFCOURSE this code can be optimized, but        */
/* the idea is let it so simple to be easy catch    */
/* where can do changes and look to the results     */
/****************************************************/

#define VFD_in 7// 
#define VFD_clk 8 // 
#define VFD_stb 9 // Must be pulsed to LCD fetch data of bus

uint8_t numberGrids = 0x03; //Look in the table below of xx6312 to see number of grids will be used. On this panel is 7 grids
/*
Display mode settings: 
 000: 4 digits, 16 segments 
 001: 5 digits, 16 segments 
 010: 6 digits, 16 segments 
 011: 7 digits, 15 segments 
 100: 8 digits, 14 segments 
 101: 9 digits, 13 segments 
 110: 10 digits, 12 segments 
 111: 11 digits, 11 segments
*/
unsigned int segments[] ={
  //The 2 "g" belongs to the segment of meadle... note the more at right is the point center on this kind of display of 14 segments
  // This table is inverted
  //    This not respect the table for 7 segm like "abcdefgh"  //
  //    11111198   76543210
  //    143210..   ........
  //    ggfbjhia   ...dmkec  
      0b00110001,0b00010011,//0
      0b00011000,0b00000001,//1 
      0b11010001,0b00010010,//2 
      0b11010001,0b00010001,//3 
      0b11110000,0b00000001,//4
      0b11100001,0b00010001,//5 
      0b11100001,0b00010011,//6
      0b00010001,0b00000001,//7 
      0b11110001,0b00010011,//8
      0b11110001,0b00000001,//9 
      0b00000000,0b00000000//10 // empty display
 };
 const PROGMEM uint16_t alphanumericDSP[96] = {
    0x0000, // space
    0x4006, // ! 
    0x0202, // " 
    0x12CE, // # 
    0x12ED, // $ 
    0x3FE4, // % 
    0x2359, // & 
    0x0200, // ' 
    0x2400, // ( 
    0x0900, // ) 
    0x3FC0, // * 
    0x12C0, // + 
    0x0800, // , 
    0x00C0, // - 
    0x4000, // . 
    0x0C00, // slash
    0x0C3F, // 0 
    0x0406, // 1 
    0x00DB, // 2 
    0x008F, // 3 
    0x00E6, // 4 
    0x2069, // 5 
    0x00FD, // 6 
    0x0007, // 7 
    0x00FF, // 8 
    0x00EF, // 9 
    0x1200, // : 
    0x0A00, // ; 
    0x2440, // < 
    0x00C8, // = 
    0x0980, // > 
    0x5083, // ? 
    0x02BB, // @ 
    0x00F7, // A 
    0x128F, // B 
    0x0039, // C 
    0x120F, // D 
    0x0079, // E 
    0x0071, // F 
    0x00BD, // G 
    0x00F6, // H 
    0x1209, // I 
    0x001E, // J 
    0x2470, // K 
    0x0038, // L 
    0x0536, // M 
    0x2136, // N 
    0x003F, // O 
    0x00F3, // P 
    0x203F, // Q 
    0x20F3, // R 
    0x00ED, // S 
    0x1201, // T 
    0x003E, // U 
    0x0C30, // V 
    0x2836, // W 
    0x2D00, // X 
    0x00EE, // Y 
    0x0C09, // Z 
    0x0039, // [ 
    0x2100, // backslash
    0x000F, // ] 
    0x2800, // ^ 
    0x0008, // _ 
    0x0100, // ` 
    0x1058, // a 
    0x2078, // b 
    0x00D8, // c 
    0x088E, // d 
    0x0858, // e 
    0x14C0, // f 
    0x048E, // g 
    0x1070, // h 
    0x1000, // i 
    0x0A10, // j 
    0x3600, // k 
    0x0030, // l 
    0x10D4, // m 
    0x1050, // n 
    0x00DC, // o 
    0x0170, // p 
    0x0486, // q 
    0x0050, // r 
    0x2088, // s 
    0x0078, // t 
    0x001C, // u 
    0x0810, // v 
    0x2814, // w 
    0x2D00, // x 
    0x028E, // y 
    0x0848, // z 
    0x0949, // { 
    0x1200, // | 
    0x2489, // } 
    0x0CC0, // ~ 
    0x0000, // (del) 
};

 //    This not respect the table for 7 segm like "abcdefgh"  //   I only fill the chars I need to message "HI FOLKS" You need do the remaining.     
 //                               76543210     11111198
 //                                      143210..
 //                               ggfbjhia     ...dmkec 
      unsigned char letterA[]={(0b00000000),(0b00000000)}; // A
      unsigned char letterB[]={(0b00000000),(0b00000000)}; // B
      unsigned char letterC[]={(0b00000000),(0b00000000)}; // C
      unsigned char letterD[]={(0b00000000),(0b00000000)}; // D
      unsigned char letterE[]={(0b00000000),(0b00000000)}; // E
      unsigned char letterF[]={(0b11100001),(0b00000010)}; // F
      unsigned char letterG[]={(0b00000000),(0b00000000)}; // G
      unsigned char letterH[]={(0b11110000),(0b00000011)}; // H
      unsigned char letterI[]={(0b00000011),(0b00010000)}; // I
      unsigned char letterJ[]={(0b00000000),(0b00000000)}; // J
      unsigned char letterK[]={(0b10101000),(0b00001010)}; // k
      unsigned char letterL[]={(0b00100000),(0b00010010)}; // L
      unsigned char letterM[]={(0b00000000),(0b00000000)}; // M
      unsigned char letterN[]={(0b00000000),(0b00000000)}; // N
      unsigned char letterO[]={(0b00110001),(0b00010011)}; // O
      unsigned char letterP[]={(0b00000000),(0b00000000)}; // P
      unsigned char letterQ[]={(0b00000000),(0b00000000)}; // Q
      unsigned char letterR[]={(0b00000000),(0b00000000)}; // R
      unsigned char letterS[]={(0b11100001),(0b00010001)}; // S
      unsigned char letterT[]={(0b00000000),(0b00000000)}; // T
      unsigned char letterU[]={(0b00000000),(0b00000000)}; // U
      unsigned char letterV[]={(0b00000000),(0b00000000)}; // V
      unsigned char letterX[]={(0b00000000),(0b00000000)}; // X
      unsigned char letterY[]={(0b00000000),(0b00000000)}; // Y
      unsigned char letterZ[]={(0b00000000),(0b00000000)}; // Z
      unsigned char letterW[]={(0b00000000),(0b00000000)}; // W
      unsigned char letterSpace[]={(0b0000000),(0b00000000)}; // Space

 
void setup() {
    // put your setup code here, to run once:
    // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(VFD_in, OUTPUT);
  pinMode(VFD_clk, OUTPUT);
  pinMode(VFD_stb, OUTPUT);
  
  Serial.begin(115200);

  CS16312_init();
  delay(5);
}
void CS16312_init(void){
  //Note: The number of GRIDs on VFD on this example is 7, because
  delayMicroseconds(300); //power_up delay
  // Note: Allways the first byte in the input data after the STB go to LOW is interpret as command!!!
  // Configure VFD display (grids)
  cmd_with_stb(numberGrids);//  (0b01000000)    cmd1 7 grids 15 segm
  delayMicroseconds(10);
  // Write to memory display, increment address, normal operation
  cmd_with_stb(0b01000000);//(BIN(01000000));
  delayMicroseconds(10);
  // Address 00H - 15H ( total of 11*2Bytes=176 Bits)
  cmd_with_stb(0b11000000);//(BIN(01100110)); 
  delayMicroseconds(10);
  // set DIMM/PWM to value
  cmd_with_stb((0b10001000) | 7);//0 min - 7 max  )(0b01010000)
  delayMicroseconds(10);
}
void cmd_without_stb(unsigned char a){
  // send without stb
  unsigned char data = 170; //value to transmit, binary 10101010
  unsigned char mask = 1; //our bitmask
  
  data=a;
  //This don't send the strobe signal, to be used in burst data send
   for (mask = 00000001; mask>0; mask <<= 1) { //iterate through bit mask
     digitalWrite(VFD_clk, LOW);
     if (data & mask){ // if bitwise AND resolves to true
        digitalWrite(VFD_in, HIGH);
     }
     else{ //if bitwise and resolves to false
       digitalWrite(VFD_in, LOW);
     }
    delayMicroseconds(5);
    digitalWrite(VFD_clk, HIGH);
    delayMicroseconds(5);
   }
   //digitalWrite(VFD_clk, LOW);
}
void cmd_with_stb(unsigned char a){
  // send with stb
  unsigned char data = 170; //value to transmit, binary 10101010
  unsigned char mask = 1; //our bitmask
  
  data=a;
  
  //This send the strobe signal
  //Note: The first byte input at in after the STB go LOW is interpreted as a command!!!
  digitalWrite(VFD_stb, LOW);
  delayMicroseconds(1);
   for (mask = 00000001; mask>0; mask <<= 1) { //iterate through bit mask
     digitalWrite(VFD_clk, LOW);
     delayMicroseconds(1);
     if (data & mask){ // if bitwise AND resolves to true
        digitalWrite(VFD_in, HIGH);
     }
     else{ //if bitwise and resolves to false
       digitalWrite(VFD_in, LOW);
     }
    digitalWrite(VFD_clk, HIGH);
    delayMicroseconds(1);
   }
   digitalWrite(VFD_stb, HIGH);
   delayMicroseconds(1);
}
void testVFD(void){
  /* 
  Here do a test for all segments of 7 grids
  each grid is controlled by a group of 2 bytes
  by these reason I'm send a burst of 2 bytes of
  data. The cycle for do a increment of 3 bytes on 
  the variable "i" on each test cycle of FOR.
  */
  // to test 7 grids is 6*3=18, the 8 gird result in 8*3=24.
      digitalWrite(VFD_stb, LOW);
      delayMicroseconds(1);
      cmd_with_stb(numberGrids); // cmd 1 // 7 Grids & 16 Segments
      cmd_with_stb(0b01000000); // cmd 2 //Normal operation; Set pulse as 1/16
      
        digitalWrite(VFD_stb, LOW);
        delayMicroseconds(1);
        cmd_without_stb((0b11000000)); //cmd 3 wich define the start address (00H to 15H)
        
         for (int i = 0; i < 7 ; i++){ // test base to 15 segm and 7 grids
         cmd_without_stb(0b11111111); // Data to fill table 7*15 
         cmd_without_stb(0b11111111); // Data to fill table 7*15 
         }
    
      cmd_with_stb((0b10001000) | 7); //cmd 4
      digitalWrite(VFD_stb, HIGH);
      delay(50);
}
void clearVFD(void){
  /*
  Here I clean all registers 
  Could be done only on the number of grid
  to be more fast. The 12 * 3 bytes = 36 registers
  */
      for (int n=0; n < 14; n++){  // 7 grids by 2 bytes each, means I need send 14 bytes filled with zeros.
        cmd_with_stb(numberGrids); //       cmd 1 // 7 Grids & 15 Segments
        cmd_with_stb(0b01000000); //       cmd 2 //Normal operation; Set pulse as 1/16
        digitalWrite(VFD_stb, LOW);
        delayMicroseconds(1);
            cmd_without_stb((0b11000000) | n); // cmd 3 //wich define the start address (00H to 15H)
            cmd_without_stb(0b00000000); // Data to fill table of 7 grids * 15 segm 
            //
            cmd_with_stb((0b10001000) | 7); //cmd 4
            digitalWrite(VFD_stb, HIGH);
            delayMicroseconds(5);
     }
}
void readButtons(){
  //Take special attention to the initialize digital pin LED_BUILTIN as an output.
  //
  //int ledPin = 13;   // LED connected to digital pin 13
  int val = 0;       // variable to store the read value
  int dataIn=0;
  byte array[8] = {0,0,0,0,0,0,0,0};
  byte together = 0;
  unsigned char receive = 7; //define our transmit pin
  unsigned char data = 0; //value to transmit, binary 10101010
  unsigned char mask = 1; //our bitmask
  array[0] = 1;
  unsigned char btn1 = 0x41;
        digitalWrite(VFD_stb, LOW);
          delayMicroseconds(2);
        cmd_without_stb(0b01000010); // cmd 2 //Read Keys;Normal operation; Set pulse as 1/16
        // cmd_without_stb((0b11000000)); //cmd 3 wich define the start address (00H to 15H)
      // send without stb
    
    pinMode(VFD_in, INPUT);  // Important this point! Here I'm changing the direction of the pin to INPUT data.
    delayMicroseconds(2);
  //PORTD != B01010100; // this will set only the pins you want and leave the rest alone at
  //their current value (0 or 1), be careful setting an input pin though as you may turn 
  //on or off the pull up resistor  
  //This don't send the strobe signal, to be used in burst data send
         for (int z = 0; z < 3; z++){
             //for (mask=00000001; mask > 0; mask <<= 1) { //iterate through bit mask
                   for (int h =8; h > 0; h--) {
                      digitalWrite(VFD_clk, HIGH);  // Remember wich the read data happen when the clk go from LOW to HIGH! Reverse from write data to out.
                      delayMicroseconds(2);
                     val = digitalRead(VFD_in);
                      //digitalWrite(ledPin, val);    // sets the LED to the button's value
                           if (val & mask){ // if bitwise AND resolves to true
                             //Serial.print(val);
                            //data =data | (1 << mask);
                            array[h] = 1;
                           }
                           else{ //if bitwise and resolves to false
                            //Serial.print(val);
                           // data = data | (1 << mask);
                           array[h] = 0;
                           }
                    digitalWrite(VFD_clk, LOW);
                    delayMicroseconds(2);
                    
                   } 
             
              Serial.print(z);  // All the lines of print is only used to debug, comment it, please!
              Serial.print(" - " );
                        
                                  for (int bits = 7 ; bits > -1; bits--) {
                                      Serial.print(array[bits]);
                                   }
                        
                        if (z==1){
                          if(array[6] == 1){
                           
                          }
                        }
                          if (z==0){
                          if(array[2] == 1){
                           
                          }
                          }
                          if (z==0){
                          if(array[6] == 1){
                           
                          }
                        }
                        if (z==0){
                          if(array[7] == 1){
                           
                          }
                        }
                        if (z==0){
                          if(array[3] == 1){
                           
                          }
                        }
                          if (z==1){
                            if(array[7] == 1){
                             
                            }
                          }
                         
                  Serial.println();
          }  // End of "for" of "z"
      Serial.println();  // This line is only used to debug, please comment it!
 digitalWrite(VFD_stb, HIGH);
 delayMicroseconds(2);
 cmd_with_stb((0b10001000) | 7); //cmd 4
 delayMicroseconds(2);
 pinMode(VFD_in, OUTPUT);  // Important this point!  // Important this point! Here I'm changing the direction of the pin to OUTPUT data.
 delay(1); 
}
void msgHi(void){
  /* 
  Here do a test for all segments of 7 grids
  each grid is controlled by a group of 2 bytes
  by these reason I'm send a burst of 2 bytes of
  data. The cycle for do a increment of 3 bytes on 
  the variable "i" on each test cycle of FOR.
  */
  // to test 7 grids is 7*3=21, the 8 gird result in 8*3=24.
      digitalWrite(VFD_stb, LOW);
      delayMicroseconds(1);
      cmd_with_stb(numberGrids); // cmd 1 // 7 Grids & 15 Segments
      cmd_with_stb(0b01000000); // cmd 2 //Normal operation; Set pulse as 1/16
      
        digitalWrite(VFD_stb, LOW);
        delayMicroseconds(1);
        cmd_without_stb((0b11001010)); //cmd 3 wich define the start address (00H to 15H) 
        //Posição of memory corresponding to: 11, 12, 13 and 14
        cmd_without_stb(letterI[0]); cmd_without_stb(letterI[1]); //I
        cmd_without_stb(letterH[0]); cmd_without_stb(letterH[1]); //H
      digitalWrite(VFD_stb, HIGH);
      cmd_with_stb((0b10001000) | 7); //cmd 4
      delay(1);
}
void msgFolks(void){
  /* 
  Here do a test for all segments of 7 grids
  each grid is controlled by a group of 2 bytes
  by these reason I'm send a burst of 2 bytes of
  data.
  */
  // to test 7 grids is 7*2=14.
      digitalWrite(VFD_stb, LOW);
      delayMicroseconds(1);
      cmd_with_stb(numberGrids); // cmd 1 // 7 Grids & 15 Segments
      cmd_with_stb(0b01000000); // cmd 2 //Normal operation; Set pulse as 1/16
      
        digitalWrite(VFD_stb, LOW);
        delayMicroseconds(1);
        cmd_without_stb((0b11000100)); //cmd 3 wich define the start address (00H to 15H)
        // I start filling at memory address 0x04 to go to until grid 7 (write from left to wrigth)
        cmd_without_stb(letterS[0]); cmd_without_stb(letterS[1]);  //S  //Grid 3
        cmd_without_stb(letterK[0]); cmd_without_stb(letterK[1]);  //K  //Grid 4
        cmd_without_stb(letterL[0]); cmd_without_stb(letterL[1]);  //L  //Grid 5
        cmd_without_stb(letterO[0]); cmd_without_stb(letterO[1]);  //O  //Grid 6
        cmd_without_stb(letterF[0]); cmd_without_stb(letterF[1]);  //F  //Grid 7
      digitalWrite(VFD_stb, HIGH);
      cmd_with_stb((0b10001000) | 7); //cmd 4  
      delay(1);
}
void numbers(){
     for(byte n=0; n<14; n=n+2){   //Here is a loop to go through the 7 grid's (each group have 2 bytes) 2*7 = 14, start at 0 means 14-1;
          for(byte s=0; s<22; s=s+2){ //Here you go through the number of digits from "0" to "9" and also the "blank"
            digitalWrite(VFD_stb, LOW);
              delayMicroseconds(1);
              cmd_with_stb(numberGrids); // cmd 1 // 7 Grids & 15 Segments
              cmd_with_stb(0b01000000); // cmd 2 //Normal operation; Write to display, write to LED's, read keys.
              //
                digitalWrite(VFD_stb, LOW);
                delayMicroseconds(1);
                cmd_without_stb((0b11000000 | n)); //cmd 3 wich define the start address (00H to 15H)
                //Serial.print((0b11000000 | n), HEX);Serial.print("; S= ");Serial.println(s, HEX);
                cmd_without_stb(segments[s]); cmd_without_stb(segments[s+1]); // 1-8     9-16
              //
              digitalWrite(VFD_stb, HIGH);
              delay(250);
           }
     }
}
void alphanumeric(){
     for(byte n=0; n<14; n=n+2){   //Here is a loop to go through the 7 grid's (each group have 2 bytes) 2*7 = 14, start at 0 means 14-1;
          for(byte s=0; s<96; s=s+2){ //Here you go through the number of digits from "0" to "9" and also the "blank"
            digitalWrite(VFD_stb, LOW);
              delayMicroseconds(1);
              cmd_with_stb(numberGrids); // cmd 1 // 7 Grids & 15 Segments
              cmd_with_stb(0b01000000);  // cmd 2 //Normal operation; Write to display, write to LED's, read keys.
              //
                digitalWrite(VFD_stb, LOW);
                delayMicroseconds(1);
                cmd_without_stb((0b11000000 | n)); //cmd 3 wich define the start address (00H to 15H)
                //Serial.print((0b11000000 | n), HEX);Serial.print("; S= ");Serial.println(s, HEX);
                cmd_without_stb(alphanumericDSP[s]); cmd_without_stb(alphanumericDSP[s+1]); // 1-8     9-16
              //
              digitalWrite(VFD_stb, HIGH);
              delay(1000);
           }
     }
}
void writeLED(){
  for(int led=0; led<4; led++){
              digitalWrite(VFD_stb, LOW);
              delayMicroseconds(1);
              cmd_with_stb(numberGrids); // cmd 1 // 7 Grids & 15 Segments
              //
                digitalWrite(VFD_stb, LOW);
                delayMicroseconds(1);
                cmd_without_stb(0b01000001);
               switch (led){
                  case 0: cmd_without_stb(0b00001110); break; //LED 0 //Note the LED's 0,1,2,3 is reverse mode 0=On 1=Off
                  case 1: cmd_without_stb(0b00001101); break; //LED 1
                  case 2: cmd_without_stb(0b00001011); break; //LED 2
                  case 3: cmd_without_stb(0b00000111); break; //LED 3
                }
              //
              digitalWrite(VFD_stb, HIGH);
              delay(500);
  }
}
void loop() {
//You can comment to avoid the test running
  clearVFD();
  testVFD();
  delay(1000);
  numbers();
// //alphanumeric();  //This table need be adapted to the connections of driver to display of 14 seg present on this panel.
// // 
  msgHi();
  delay(1200);
  clearVFD();
  msgFolks();
  delay(1500);
  clearVFD();
//  writeLED();
//  delay(200);
//  readButtons();
}
