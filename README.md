# ¿Dónde va mi residuo?

### Sistema inteligente IoT para la clasificación y gestión de residuos en cafeterías

**Universidad Adolfo Ibáñez — Taller de Diseño en Ingeniería**

**Integrantes:** Amanda Berstel, Fernanda Lillo y Daniela Ubilla.

**Profesor:** Luis Andueza.

## 1. Descripción del proyecto

Este proyecto aborda la dificultad que experimentan los usuarios al identificar el contenedor adecuado para depositar sus residuos en cafeterías.

La solución propuesta consiste en un sistema interactivo basado en ESP32 que orienta al usuario mediante botones e indicadores LED, además de incorporar una arquitectura IoT para el registro y monitoreo de información.

## 2. Objetivos

- Facilitar la clasificación de residuos mediante indicaciones visuales.
- Reducir la incertidumbre del usuario al momento de desechar.
- Registrar interacciones para analizar patrones de utilización.
- Incorporar mediciones de peso para apoyar la gestión de contenedores.
- Promover prácticas de consumo y gestión de residuos más responsables.

## 3. Funcionamiento del sistema

1. El usuario selecciona el residuo mediante uno de los seis botones.
2. El ESP32 identifica la entrada y ejecuta la lógica programada.
3. Se activa el LED asociado al contenedor correspondiente.
4. El usuario deposita manualmente el residuo.
5. El sistema contempla registrar las interacciones y mediciones disponibles para su posterior visualización.

## 4. Componentes y tecnologías

- ESP32 DevKit.
- Seis botones de selección.
- Cuatro LEDs indicadores.
- Celdas de carga de 5 kg.
- Módulos de lectura HX711.
- Arduino IDE y programación en C/C++.
- Comunicación WiFi.
- Plataforma Ubidots.
- Autodesk Fusion 360.

La integración y funcionalidad de cada módulo se documentan en las carpetas correspondientes.

## 5. Organización del repositorio

- `firmware/`: código fuente del ESP32.
- `hardware/`: documentación electrónica y lista de materiales.
- `diseno-3d/`: modelos y planos desarrollados en Fusion 360.
- `testing/`: protocolos, resultados y validaciones.
- `docs/`: presentaciones y documentación complementaria.
- `FUENTES.md`: referencias y declaración de uso de inteligencia artificial.

## 6. Relación con los Objetivos de Desarrollo Sostenible

**ODS 12 — Producción y consumo responsables:** orientación para una mejor separación de residuos desde su origen.

**ODS 11 — Ciudades y comunidades sostenibles:** propuesta de gestión de residuos aplicable a espacios colectivos.

## 7. Equipo

Amanda Berstel, Fernanda Lillo y Daniela Ubilla.

Universidad Adolfo Ibáñez, 2026.

## 8. Instalación y uso del sistema

### Requisitos

- Placa ESP32 DevKit.
- Arduino IDE instalado en el computador.
- Botones de selección e indicadores LED.
- Componentes electrónicos y conexiones del prototipo.
- Conexión WiFi para las funciones de comunicación IoT.
- Acceso a la plataforma Ubidots.

### Preparación del sistema

1. Abrir el proyecto de Arduino disponible en la carpeta `firmware/`.
2. Configurar Arduino IDE para utilizar la placa ESP32 correspondiente.
3. Revisar las conexiones del circuito según el esquemático disponible en `hardware/`.
4. Configurar la conexión WiFi y las credenciales de Ubidots de forma segura, cuando corresponda.
5. Compilar y cargar el programa al ESP32.
6. Verificar que los botones y LEDs respondan según la lógica programada.
7. Comprobar la recepción de datos en Ubidots, si la conexión está implementada.

### Uso del prototipo

El usuario selecciona el tipo de residuo mediante uno de los seis botones de la interfaz. El ESP32 procesa la selección y activa el indicador LED del contenedor correspondiente.

El sistema contempla registrar datos para su posterior consulta y análisis mediante una plataforma IoT.

**Nota:** Las instrucciones se actualizarán según la configuración definitiva del hardware y firmware.
