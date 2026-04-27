#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Professional Fonts
#include <Fonts/FreeSans9pt7b.h>       
#include <Fonts/FreeSerifBoldItalic12pt7b.h> // Slightly smaller "Long" font to fit screen
#include <Fonts/FreeSerifBoldItalic18pt7b.h> 
#include <Fonts/FreeSansBold12pt7b.h>   

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  playOpening();
}

void loop() {
  typewriterText("all i dream of\nis your", &FreeSans9pt7b, 1000);
  
  // EYES fits in 18pt
  insideOutEffect("EYES", &FreeSerifBoldItalic18pt7b, 1500);
  
  typewriterText("all i long for\nis your", &FreeSans9pt7b, 1000);
  
  // TOUCH fits in 18pt
  insideOutEffect("TOUCH", &FreeSerifBoldItalic18pt7b, 1500);

  typewriterText("and darling", &FreeSans9pt7b, 800);
  typewriterText("something\ntells me", &FreeSans9pt7b, 1500);

  typewriterText("THAT'S", &FreeSansBold12pt7b, 500);
  
  // FIX: ENOUGH is too long for 18pt, using 12pt so it stays in frame
  insideOutEffect("ENOUGH", &FreeSerifBoldItalic12pt7b, 2500);
  
  delay(2000);
}

// --- INSIDE OUT ANIMATION (STAYS IN FRAME) ---
void insideOutEffect(String text, const GFXfont *f, int duration) {
  for (int i = 0; i <= SCREEN_WIDTH / 2; i += 10) {
    display.clearDisplay();
    display.fillRect(SCREEN_WIDTH/2 - i, 0, i * 2, SCREEN_HEIGHT, SSD1306_WHITE);
    
    display.setFont(f);
    display.setTextColor(SSD1306_BLACK);
    
    int16_t x1, y1; uint16_t w, h;
    display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
    
    // Dead Center Math
    int xPos = (SCREEN_WIDTH - w) / 2;
    int yPos = (SCREEN_HEIGHT + h) / 2; 
    
    display.setCursor(xPos, yPos);
    display.print(text);
    
    display.display();
    delay(5); 
  }
  delay(duration);
}

// --- TYPEWRITER WITH PERFECT CENTERING ---
void typewriterText(String text, const GFXfont *f, int duration) {
  display.setFont(f);
  display.setTextColor(SSD1306_WHITE);

  // Split lines for multi-line centering
  String line1 = "";
  String line2 = "";
  int splitIndex = text.indexOf('\n');
  
  if (splitIndex != -1) {
    line1 = text.substring(0, splitIndex);
    line2 = text.substring(splitIndex + 1);
  } else {
    line1 = text;
  }

  // Animating Line 1
  String currentLine = "";
  for (int i = 0; i < line1.length(); i++) {
    currentLine += line1[i];
    drawDualLines(currentLine, "", f);
    delay(70);
  }

  // Animating Line 2 (if exists)
  if (line2 != "") {
    currentLine = "";
    for (int i = 0; i < line2.length(); i++) {
      currentLine += line2[i];
      drawDualLines(line1, currentLine, f);
      delay(70);
    }
  }
  delay(duration);
}

// Helper to draw two lines perfectly centered vertically
void drawDualLines(String l1, String l2, const GFXfont *f) {
  display.clearDisplay();
  int16_t x1, y1; uint16_t w, h;
  
  // Get height for spacing
  display.getTextBounds("Ay", 0, 0, &x1, &y1, &w, &h);
  int lineHeight = h + 8;
  
  // Draw Line 1
  if (l1 != "") {
    display.getTextBounds(l1, 0, 0, &x1, &y1, &w, &h);
    int y = (l2 == "") ? (SCREEN_HEIGHT + h) / 2 : (SCREEN_HEIGHT / 2) - 2;
    display.setCursor((SCREEN_WIDTH - w) / 2, y);
    display.print(l1);
  }
  
  // Draw Line 2
  if (l2 != "") {
    display.getTextBounds(l2, 0, 0, &x1, &y1, &w, &h);
    display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT / 2) + lineHeight - 2);
    display.print(l2);
  }
  display.display();
}

// --- OPENING EFFECT ---
void playOpening() {
  display.clearDisplay();
  for (int i = 0; i <= SCREEN_WIDTH / 2; i += 4) {
    display.fillRect(SCREEN_WIDTH/2 - i, 0, 2, SCREEN_HEIGHT, SSD1306_WHITE);
    display.fillRect(SCREEN_WIDTH/2 + i, 0, 2, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(20);
  }
  display.drawLine(0, 0, 40, 32, SSD1306_WHITE);
  display.drawLine(128, 0, 88, 32, SSD1306_WHITE);
  display.drawLine(0, 64, 40, 32, SSD1306_WHITE);
  display.drawLine(128, 64, 88, 32, SSD1306_WHITE);
  display.display();
  delay(1000);
}