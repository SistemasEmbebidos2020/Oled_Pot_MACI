#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definiciones4
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

// se llama a la instancia de la oled para definir ancho alto 
Adafruit_SSD1306 pantalla(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);
// se define en que pin se conectará la señal analógica
uint16_t potentiometerPin = 34;

const int sampleRate = 200;  // Tasa de muestreo en milisegundos
const int graphWidth = 105; // Ancho de la gráfica en píxeles
const int graphHeight = 43; // Altura de la gráfica en píxeles
const int Yinit = 16;  //se define el valor inicial en Y para la gráfica
static int xinit = 4;  //se define el valor inicial en X para la gráfica
static int prevX , prevY = 0;  //se define valor en cero paraa utilizarse mas adelante

//variable que almacenará el valor a graficar
int y;

//variable de almacena el valor leído
int sensorValue;

void drawejes()
{
  //se grafica una linea vertical desde xinit,Yinit-10  hasta  xinit,Yinit+35 y se establece un color de línea blanca
  pantalla.drawLine(xinit, Yinit - 10, xinit, Yinit + 35, SSD1306_WHITE);
  //se grafica una linea horizontal desde xinit,Yinit+35  hasta  xinit+105,Yinit+35 y se establece un color de línea blanca
  pantalla.drawLine(xinit, Yinit + 35, xinit+104, Yinit + 35, SSD1306_WHITE);
  //se fija el cursor en la pantalla en 4,5 conociendo que el máximo es 128,64 por la resolucion de la pantalla oled
  pantalla.setCursor(4, 5);
  //se establece el tamaño del texto a escribri
  pantalla.setTextSize(1);
  //se escribe el texto en la posicion 4,5
  pantalla.print("Analog Value: ");
  //se fija el cursor en la pantalla en 95,Yinit+40 conociendo que el máximo es 128,64 por la resolucion de la pantalla oled
  pantalla.setCursor(95, Yinit + 40);
  //se escribe el texto en la posicion 95, Yinit + 40
  pantalla.print("(t)");
  //se fija el cursor en la pantalla en 95,Yinit+40 conociendo que el máximo es 128,64 por la resolucion de la pantalla oled
  pantalla.setCursor(0,Yinit + 40 );
  //se escribe el texto en la posicion 95, Yinit + 40
  pantalla.print("0");
  //se refresca la pantalla con lo valores establecidos previamente para todos los pixeles
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
  y = map(sensorValue, 0, 4095, graphHeight+5, Yinit);
  pantalla.fillRoundRect(83, 4,30,11,1,SSD1306_BLACK);
  pantalla.setCursor(85, 6);
  pantalla.print(sensorValue);
  // Serial.println(y);
  //  Dibuja la lectura en la pantalla OLED
  if (prevY==0) pantalla.drawPixel(xinit, Yinit, SSD1306_WHITE);
  else pantalla.drawLine(prevX, prevY, xinit, y, SSD1306_WHITE);
  pantalla.display();
  prevY = y;
  prevX = xinit;

  xinit++;
  if (xinit >= graphWidth)
  {
    xinit = 4;
    pantalla.clearDisplay();
    drawejes();
    prevY=0;
  }

  delay(sampleRate);
}
