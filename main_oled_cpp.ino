//MIAN SOURCE CODE FOR OLED DISPLAY 

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

