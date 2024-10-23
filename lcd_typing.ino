#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with the I2C address (usually 0x27 or 0x3F) and dimensions (20x4)
LiquidCrystal_I2C lcd(0x27, 20, 4); 
int button = 6;
void setup() {
  pinMode(button, INPUT_PULLUP);
}

void loop() {
int buttonState = digitalRead(button);
 if (buttonState == LOW){
  lcd.begin();
  lcd.backlight();
  typeSentence("Akaulizia mama,", 0, 0);
  typeSentence("Umepika mboka kani?", 1, 0);
  typeSentence("Mama akasema...", 2, 0);
  typeSentence("Leo nimeunda Misheveve", 3, 0);
 }

 else{lcd.clear();
 }


}

// Function to display a sentence with a typing effect
void typeSentence(const char* sentence, int row, int col) {
  lcd.setCursor(col, row);  // Set cursor to the given position
  int len = strlen(sentence);
  for (int i = 0; i < len; i++) {
    lcd.print(sentence[i]);  // Print one character at a time
    delay(100);              // Short delay between each character
  }
}
