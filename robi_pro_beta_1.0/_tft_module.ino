#ifdef TFT_MODULE

//=======INIT=====================================================================
#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9
#define TFT_SCLK 13
#define TFT_MOSI 11

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

//=======FUNCTIONS================================================================

void TFT_INIT(){

    tft.initR(INITR_BLACKTAB);  
}

void TFT_DRAW_LOGO(){

    tft.setRotation(2);
    tft.fillScreen(ST7735_BLACK);
    tft.setTextSize(5);
    tft.setTextColor(ST7735_YELLOW);
    tft.setCursor(8, 0);
    tft.print("ROBI");
    tft.setTextSize(1);
    tft.setTextColor(ST7735_WHITE);
    tft.setCursor(0, 42);
    tft.print("ARDUINO ROBOT ROBIPRO");
    tft.drawLine(0, 52, tft.width()-1, 52, ST7735_WHITE);
    tft.drawLine(0, 150, tft.width()-1, 150, ST7735_WHITE);
    tft.setCursor(20, 152);
    tft.print("www.oomipood.ee");
}

void TFT_DRAW_LINE(){
  //tft.drawFastHLine(0,75,20,ST7735_WHITE);
  //tft.drawRect(32,75,20,20,ST7735_WHITE);
  tft.fillRect(0,75,128,21,ST7735_BLACK);
  /*
  tft.drawLine(0, 75, tft.width()-1, 75, ST7735_BLACK);
  tft.drawLine(0, 76, tft.width()-1, 76, ST7735_BLACK);
  tft.drawLine(0, 77, tft.width()-1, 77, ST7735_BLACK);
  tft.drawLine(0, 78, tft.width()-1, 78, ST7735_BLACK);
  tft.drawLine(0, 79, tft.width()-1, 79, ST7735_BLACK);
  tft.drawLine(0, 80, tft.width()-1, 80, ST7735_BLACK);
  tft.drawLine(0, 81, tft.width()-1, 81, ST7735_BLACK);
  */
}

void TFT_PRINT_DIRECTION(String toPrint, byte text_size){

        tft.fillRect(0,55,128,32,ST7735_GREEN); //clear center

        tft.setTextSize(text_size);
        tft.setTextColor(ST7735_WHITE);
        tft.setCursor(2, 60);
        tft.print(toPrint);

}

void TFT_PRINT_ERROR(String toPrint){

        tft.fillRect(0,90,128,12,ST7735_RED);
        tft.setTextSize(1);
        tft.setTextColor(ST7735_WHITE);
        tft.setCursor(2, 93);
        tft.print(toPrint);
}

void TFT_CLEAR_ERROR_AREA(){
        tft.fillRect(0,90,128,12,ST7735_BLACK);
}


void TFT_PRINT_ENCODERS_STATUS(int left_enc, int right_enc){

      tft.setTextSize(1);
      tft.setTextColor(ST7735_WHITE);
      tft.drawLine(0, 106, tft.width()-1, 106, ST7735_WHITE);

      tft.setCursor(0, 109);
      tft.print("ENC L: ");
      tft.setCursor(35, 109);
      tft.fillRect(35,109,30,7,ST7735_BLACK);
      tft.print(left_enc);

      tft.setCursor(74, 109);
      tft.print("R:");
      tft.setCursor(84, 109);
      tft.fillRect(84,109,30,7,ST7735_BLACK);
      tft.print(right_enc);
}

void TFT_PRINT_SPEED(byte left_speed, byte right_speed){

      tft.setTextSize(1);
      tft.setTextColor(ST7735_WHITE);

      tft.setCursor(0, 119);
      tft.print("SPD L: ");
      tft.setCursor(35, 119);
      tft.fillRect(35,119,30,7,ST7735_BLACK);
      tft.print(left_speed);

      tft.setCursor(74, 119);
      tft.print("R:");
      tft.setCursor(84, 119);
      tft.fillRect(84,119,30,7,ST7735_BLACK);
      tft.print(right_speed);

  }

void TFT_PRINT_DISTANCE(long distance){

      tft.setTextSize(1);
      tft.setTextColor(ST7735_WHITE);
      tft.setCursor(0, 129);
      tft.print("DISTANCE: ");
      tft.setCursor(55, 129);
      tft.fillRect(55,129,30,7,ST7735_BLACK);
      tft.setCursor(55, 129);
      tft.print(distance);
}

void TFT_PRINT_KEY_PRESSED(byte key){

      tft.setTextSize(1);
      tft.setTextColor(ST7735_WHITE);
      tft.setCursor(85, 129);
      tft.print("KEY:");
      tft.setCursor(90, 129);
      tft.fillRect(110,129,30,7,ST7735_BLACK);
      tft.setCursor(110, 129);
      tft.print(key);
}

void TFT_PRINT_TEXT(String toPrint, byte text_size, uint16_t text_color, byte text_x, byte text_y){

      tft.setTextSize(text_size);
      tft.setTextColor(text_color);
      tft.setCursor(text_x, text_y);
      tft.print(toPrint);


}

void TFT_CLEAR_WORK_AREA(){
      tft.setCursor(53, 0);
      tft.fillRect(0,53,128,97,ST7735_BLACK);

}

void TFT_FUNC_AREA(){

      tft.drawLine(0, 138, tft.width()-1, 138, ST7735_WHITE);
      tft.setCursor(22, 141);
      tft.setTextSize(1);
      tft.setTextColor(ST7735_GREEN);
      tft.print("FUNCTIONS AREA");

}

#endif /*TFT_MODULE*/
