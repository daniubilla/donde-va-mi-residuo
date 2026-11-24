
/*
  SISTEMA INTELIGENTE DE CLASIFICACION DE RESIDUOS
  Taller de Diseno en Ingenieria

  ESP32 Dev Module

  Funciones:
  - Detectar seis botones de productos.
  - Registrar una interaccion por pulsacion.
  - Controlar cuatro LEDs de contenedores.
  - Preparar la estructura para sensores e IoT.
*/

// ==========================================
// 1. PINES DE LOS BOTONES
// ==========================================

const int botonVasoFrio = 13;
const int botonVasoCaliente = 14;
const int botonLata = 18;
const int botonServilleta = 19;
const int botonBombilla = 21;
const int botonOtro = 22;


// ==========================================
// 2. PINES DE LOS LEDS
// ==========================================

const int ledCarton = 23;
const int ledPapel = 25;
const int ledPlastico = 26;
const int ledBasura = 27;


// ==========================================
// 3. PRODUCTOS Y CONTENEDORES
// ==========================================

enum Producto {
  VASO_FRIO,
  VASO_CALIENTE,
  LATA,
  SERVILLETA,
  BOMBILLA,
  OTRO,
  TOTAL_PRODUCTOS
};

enum Contenedor {
  CARTON,
  PAPEL,
  PLASTICO,
  BASURA,
  SIN_DEFINIR
};

const char* nombresProductos[TOTAL_PRODUCTOS] = {
  "Vaso transparente / botella",
  "Vaso para liquido caliente",
  "Lata",
  "Servilleta",
  "Bombilla",
  "Otro / No se"
};

const int pinesBotones[TOTAL_PRODUCTOS] = {
  botonVasoFrio,
  botonVasoCaliente,
  botonLata,
  botonServilleta,
  botonBombilla,
  botonOtro
};

// CLASIFICACION PROVISIONAL:
// No se asignaran contenedores hasta validar
// los residuos y su gestion en la cafeteria.

Contenedor destino[TOTAL_PRODUCTOS] = {
  SIN_DEFINIR,
  SIN_DEFINIR,
  SIN_DEFINIR,
  SIN_DEFINIR,
  SIN_DEFINIR,
  SIN_DEFINIR
};


// ==========================================
// 4. REGISTRO DE INTERACCIONES
// ==========================================

unsigned long conteoProductos[TOTAL_PRODUCTOS] = {
  0, 0, 0, 0, 0, 0
};

unsigned long totalInteracciones = 0;

// Estado de los botones para antirrebote
bool estadoEstable[TOTAL_PRODUCTOS];
bool ultimaLectura[TOTAL_PRODUCTOS];

unsigned long ultimoCambio[TOTAL_PRODUCTOS] = {
  0, 0, 0, 0, 0, 0
};

const unsigned long tiempoAntirrebote = 50;


// ==========================================
// 5. CONFIGURACION INICIAL
// ==========================================

void setup() {

  Serial.begin(115200);

  // Configurar los seis botones
  for (int i = 0; i < TOTAL_PRODUCTOS; i++) {

    pinMode(pinesBotones[i], INPUT_PULLUP);

    estadoEstable[i] = HIGH;
    ultimaLectura[i] = HIGH;
  }

  // Configurar los LEDs
  pinMode(ledCarton, OUTPUT);
  pinMode(ledPapel, OUTPUT);
  pinMode(ledPlastico, OUTPUT);
  pinMode(ledBasura, OUTPUT);

  apagarLEDs();

  Serial.println();
  Serial.println("=================================");
  Serial.println(" SISTEMA DE RESIDUOS INICIADO");
  Serial.println("=================================");

}


// ==========================================
// 6. FUNCIONAMIENTO CONTINUO
// ==========================================

void loop() {

  revisarBotones();

  // Aqui agregaremos posteriormente:
  // leerSensores();
  // enviarDatosIoT();

}


// ==========================================
// 7. DETECCION DE BOTONES
// ==========================================

void revisarBotones() {

  for (int i = 0; i < TOTAL_PRODUCTOS; i++) {

    bool lectura = digitalRead(pinesBotones[i]);

    // Detectar cambios de lectura
    if (lectura != ultimaLectura[i]) {
      ultimoCambio[i] = millis();
    }

    // Comprobar que el cambio sea estable
    if (millis() - ultimoCambio[i] >= tiempoAntirrebote) {

      if (lectura != estadoEstable[i]) {

        estadoEstable[i] = lectura;

        // Registrar solo cuando se presiona
        if (estadoEstable[i] == LOW) {

          registrarSeleccion((Producto)i);

        }
      }
    }

    ultimaLectura[i] = lectura;
  }
}


// ==========================================
// 8. REGISTRAR UNA SELECCION
// ==========================================

void registrarSeleccion(Producto producto) {

  conteoProductos[producto]++;
  totalInteracciones++;

  Serial.println();
  Serial.println("------------------------------");

  Serial.print("Producto seleccionado: ");
  Serial.println(nombresProductos[producto]);

  Serial.print("Interacciones de este producto: ");
  Serial.println(conteoProductos[producto]);

  Serial.print("Interacciones totales: ");
  Serial.println(totalInteracciones);

  indicarContenedor(destino[producto]);

}


// ==========================================
// 9. CONTROL DE LEDS
// ==========================================

void apagarLEDs() {

  digitalWrite(ledCarton, LOW);
  digitalWrite(ledPapel, LOW);
  digitalWrite(ledPlastico, LOW);
  digitalWrite(ledBasura, LOW);

}


void indicarContenedor(Contenedor contenedor) {

  apagarLEDs();

  switch (contenedor) {

    case CARTON:
      digitalWrite(ledCarton, HIGH);
      Serial.println("Contenedor: Carton");
      break;

    case PAPEL:
      digitalWrite(ledPapel, HIGH);
      Serial.println("Contenedor: Papel");
      break;

    case PLASTICO:
      digitalWrite(ledPlastico, HIGH);
      Serial.println("Contenedor: Plastico");
      break;

    case BASURA:
      digitalWrite(ledBasura, HIGH);
      Serial.println("Contenedor: Basura");
      break;

    case SIN_DEFINIR:
      Serial.println("Contenedor pendiente de validar");
      break;
  }

}
