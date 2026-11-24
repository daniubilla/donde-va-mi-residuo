# Fuentes y declaración de uso de inteligencia artificial

## 1. Proyecto

**Nombre:** ¿Dónde va mi residuo?

**Descripción:** Sistema inteligente IoT para la clasificación y gestión de residuos en cafeterías, desarrollado en el Taller de Diseño en Ingeniería de la Universidad Adolfo Ibáñez.

## 2. Herramientas utilizadas

- Arduino IDE: entorno de programación del ESP32.
- Autodesk Fusion 360: diseño y modelado tridimensional.
- Ubidots: plataforma utilizada para el desarrollo del sistema de monitoreo IoT.
- GitHub: almacenamiento y documentación del proyecto.

## 3. Uso de inteligencia artificial

Durante el desarrollo del proyecto se utilizó **ChatGPT (OpenAI)** como herramienta de apoyo para comprender conceptos técnicos, orientar la programación del ESP32 y resolver dudas relacionadas con la integración de componentes electrónicos.

El equipo también adquirió conocimientos de programación y utilización de **Arduino IDE durante las clases del Taller de Diseño en Ingeniería**, los cuales fueron aplicados al desarrollo del prototipo.

La inteligencia artificial se utilizó como herramienta de consulta y apoyo al aprendizaje, no como sustituto del trabajo de diseño y desarrollo del equipo.]

## 4. Librerías y código externo
### Librerías utilizadas en el firmware

- **WiFi.h:** librería del entorno Arduino para ESP32, utilizada para conectar el microcontrolador a la red WiFi.
- **WiFiClientSecure.h:** permite realizar conexiones HTTPS.
- **HTTPClient.h:** permite enviar solicitudes HTTP a la plataforma ThingSpeak.
- **HX711.h:** librería utilizada para obtener lecturas de la celda de carga mediante el módulo HX711.
- **math.h:** biblioteca estándar utilizada para operaciones matemáticas.

Las librerías WiFi.h, WiFiClientSecure.h y HTTPClient.h forman parte del entorno Arduino para ESP32. La librería HX711 requiere instalación adicional.

**Plataforma IoT:** ThingSpeak, utilizada para almacenar y visualizar los registros enviados por el ESP32.

**Referencias técnicas:**
- Arduino ESP32: https://docs.espressif.com/projects/arduino-esp32/en/latest/
- ThingSpeak: https://thingspeak.mathworks.com/
- HX711: https://github.com/bogde/HX711

El código fue desarrollado y adaptado para el funcionamiento del prototipo, con apoyo de herramientas de inteligencia artificial declarado en este documento.

## 5. Otras fuentes

### Objetivos de Desarrollo Sostenible

- **Naciones Unidas.** Objetivo 12: Garantizar modalidades de consumo y producción sostenibles. https://www.un.org/sustainabledevelopment/es/sustainable-consumption-production/
- **Naciones Unidas.** Objetivo 11: Lograr que las ciudades sean más inclusivas, seguras, resilientes y sostenibles. https://www.un.org/sustainabledevelopment/es/cities/

### Investigación del problema

- Investigación realizada por el equipo sobre las dificultades de clasificación de residuos en cafeterías.
- Encuesta a usuarios sobre sus hábitos de separación de residuos y necesidad de orientación.

### Fuentes técnicas adicionales

Pendiente de incorporar las referencias de componentes, librerías y documentación técnica utilizadas en la implementación final.
