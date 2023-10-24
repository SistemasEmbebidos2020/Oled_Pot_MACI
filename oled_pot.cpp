#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Definiciones4
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
// Variables globales
Adafruit_SSD1306 pantalla(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

// Funciones
void setup()
{
  Serial.begin(9600);
  // Inicializar la pantalla OLED
  pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pantalla.clearDisplay();
  pantalla.setTextColor(SSD1306_WHITE);
  pantalla.setTextSize(1);
  pantalla.drawPixel(22, 30, SSD1306_WHITE);
  pantalla.drawLine(5, 5, 100, 50, SSD1306_WHITE);
  pantalla.drawCircle(55,25,20,SSD1306_WHITE);
  pantalla.drawRoundRect(10,5,30,25,5,SSD1306_WHITE);
  pantalla.display();
}
void loop()
{

}
