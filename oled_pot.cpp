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
uint16_t potentiometerPin = 34;
uint32_t tiempo_actual = 0;
const int sampleRate = 200;  // Tasa de muestreo en milisegundos
const int graphWidth = 105; // Ancho de la gráfica en píxeles
const int graphHeight = 43; // Altura de la gráfica en píxeles
const int Yinit = 16;
static int x = 10;
static int prevX , prevY = 0;
int y=0;
int sensorValue;

// Funciones
void setup()
{
  Serial.begin(9600);
  // Inicializar la pantalla OLED
  pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pantalla.clearDisplay();
  pantalla.setTextColor(SSD1306_WHITE);
  pantalla.setTextSize(1);
  pantalla.drawPixel(x, y, SSD1306_WHITE);
  pantalla.drawLine(5, 5, 100, 50, SSD1306_WHITE);
  pantalla.drawCircle(55,25,20,SSD1306_WHITE);
  pantalla.drawRoundRect(10,5,30,25,5,SSD1306_WHITE);
  pantalla.display();
}
void loop()
{

}
