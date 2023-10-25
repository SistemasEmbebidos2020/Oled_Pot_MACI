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
int y;
int sensorValue;
void drawejes()
{
  pantalla.drawLine(2, Yinit - 10, 2, Yinit + 35, SSD1306_WHITE);
  pantalla.drawLine(2, Yinit + 35, 102, Yinit + 35, SSD1306_WHITE);
  pantalla.setCursor(4, 5);
  pantalla.print("Analog Value");
  pantalla.setCursor(90, Yinit + 40);
  pantalla.print("Time");
  pantalla.display();
}

// Funciones
void setup()
{
  Serial.begin(9600);
  // Inicializar la pantalla OLED
  pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pantalla.clearDisplay();
  pantalla.setTextColor(SSD1306_WHITE);
  pantalla.setTextSize(1);

  // Inicializar el potenciómetro
  drawejes();
}
long xtime = millis();
void loop()
{

  sensorValue = analogRead(potentiometerPin);

  // Serial.println(sensorValue);
  y = map(sensorValue, 0, 4095, Yinit, graphHeight);
  // Serial.println(y);
  //  Dibuja la lectura en la pantalla OLED
  if (prevY==0) pantalla.drawPixel(x, y, SSD1306_WHITE);
  else pantalla.drawLine(prevX, prevY, x, y, SSD1306_WHITE);
  pantalla.display();
  pantalla.drawCircle(55,25,20);
  prevY = y;
  prevX = x;

  x++;
  if (x >= graphWidth)
  {
    x = 10;
    pantalla.clearDisplay();
    drawejes();
    prevY=0;
  }

  delay(sampleRate);
}
