// Esqueleto lógico del control de humedad.
// Integrar con LVGL/GUI específica del ONX2432G028.
#include <Wire.h>
#include <Adafruit_SHT31.h>

Adafruit_SHT31 interior = Adafruit_SHT31();
Adafruit_SHT31 exterior = Adafruit_SHT31();

constexpr int PIN_RELE = 13;
constexpr float RH_ON  = 75.0;
constexpr float RH_OFF = 60.0;
bool extractor = false;

void setup() {
  Wire.begin(8, 7); // SDA=GPIO8, SCL=GPIO7
  interior.begin(0x44);
  exterior.begin(0x45);
  pinMode(PIN_RELE, OUTPUT);
}

void loop() {
  float rh = interior.readHumidity();

  if (!extractor && rh >= RH_ON) extractor = true;
  if ( extractor && rh <= RH_OFF) extractor = false;

  digitalWrite(PIN_RELE, extractor ? HIGH : LOW); // invertir si relé activo LOW
  delay(1000);
}
