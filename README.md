# Control de humedad para baño

Control automático de extractor usando Nextion ONX2432G028 (ESP32-S3), dos sensores SHT31 y relé optoaislado.

## Arquitectura

- Sensor interior SHT31: 0x44.
- Sensor exterior SHT31: 0x45.
- I²C: SCL GPIO7 / SDA GPIO8.
- Relé: GPIO13.
- AUTO: encendido alrededor de 75 %RH y apagado alrededor de 60 %RH.
- Pausa temporal de 15 min y modo noche/quieto.

## Estructura

- `docs/`: decisiones y mejoras.
- `hardware/`: conexiones y montaje.
- `images/`: diagramas generados.
- `code/`: firmware y prototipos.
- `bom/`: lista de componentes.
