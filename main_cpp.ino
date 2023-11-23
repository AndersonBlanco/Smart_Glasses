/*

  Bitmap.pde
  
  Show simple bitmap

  >>> Before compiling: Please remove comment from the constructor of the 
  >>> connected graphics display (see below).

  Universal 8bit Graphics Library, https://github.com/olikraus/u8glib/
  
  Copyright (c) 2011, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/


#include "U8glib.h"

U8GLIB_SSD1309_128X64 u8g(13, 11, 10, 9);	// SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
// 13 = clk, 11 = din, 10 cs, 9 = dc 

const uint8_t rook_bitmap[] PROGMEM = {
  0x00,         // 00000000 
  0x55,         // 01010101
  0x7f,          // 01111111
  0x3e,         // 00111110
  0x100,         // 00111110 
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x7f           // 01111111
};

void drawRight_cir(void) {
  // graphic commands to redraw the complete screen should be placed here  
  //u8g.drawBitmapP( 0, 0, 1, 8, rook_bitmap);

  u8g.drawCircle( u8g.getWidth()/2 - 3.4,  u8g.getHeight()/2 - 25,  5);

}

void drawLeft_cir(void) {
  // graphic commands to redraw the complete screen should be placed here  
  //u8g.drawBitmapP( 0, 0, 1, 8, rook_bitmap);

  u8g.drawCircle( u8g.getWidth()/2 + 3.4,  u8g.getHeight()/2 - 25,  5);

}

int drawText(const char text[]){
  u8g.drawStr( 10,  u8g.getHeight()/2, text);
 
}

void setup(void) {
  //fonts list source: https://github.com/olikraus/u8glib/wiki/fontgroupfontstruct \
  u8g.setFont(u8g_font_baby);

  u8g.setFont(u8g_font_baby);
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    drawRight_cir();
    drawLeft_cir();
    drawText("Hello Sir");
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
}

