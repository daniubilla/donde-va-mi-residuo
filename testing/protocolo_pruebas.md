# Protocolo de pruebas y validación del prototipo IoT

## Proyecto: ¿Dónde va mi residuo?

### 1. Objetivo

Evaluar el funcionamiento del sistema de selección de residuos mediante seis botones físicos conectados a un microcontrolador ESP32, verificando que cada interacción produzca la respuesta esperada en los indicadores LED.

La prueba busca comprobar la confiabilidad de la interfaz de selección, fundamental para orientar al usuario hacia el contenedor adecuado y disminuir los errores de clasificación de residuos.

### 2. Elementos evaluados

- Microcontrolador ESP32.
- Seis botones de selección de residuos.
- Indicadores LED asociados a los contenedores.
- Programa encargado de procesar las pulsaciones y activar los indicadores.

### 3. Condiciones de prueba

La evaluación se realizó con el prototipo encendido y el programa cargado en el ESP32.

Se efectuaron pruebas individuales de los seis botones y pulsaciones adicionales del botón que presentó una falla.

No se registraron mediciones de tiempo de respuesta ni pruebas prolongadas de funcionamiento.

### 4. Procedimiento experimental

1. Encender el prototipo y verificar la alimentación del ESP32.
2. Presionar individualmente cada uno de los seis botones.
3. Observar la respuesta del indicador LED correspondiente.
4. Registrar los botones que respondan correctamente y aquellos que presenten fallas.
5. Ante una falla, documentar la acción correctiva aplicada.
6. Repetir la prueba del componente afectado.
7. Comparar los resultados iniciales con los obtenidos después de la intervención.

### 5. Criterios de éxito

Se considera una pulsación exitosa cuando el botón genera la respuesta LED esperada.

El criterio de funcionamiento correcto de la interfaz es que los seis botones respondan adecuadamente durante la revisión inicial.

Para verificar la recuperación de un botón después de una falla, se realizan pulsaciones adicionales y se comprueba si todas generan la respuesta esperada.

### 6. Resultados experimentales

**Primera revisión**

| Botón | Resultado |
|---|---|
| 1. Vaso transparente / botella | Correcto |
| 2. Vaso caliente | Correcto |
| 3. Lata | Correcto |
| 4. Servilleta | Correcto |
| 5. Bombilla | Correcto |
| 6. Otro / no sé | Sin respuesta |

Se obtuvieron cinco respuestas correctas de seis pulsaciones, equivalentes a un **83,3 % de éxito inicial**.

**Intervención y repetición**

Ante la falta de respuesta del botón 6, se reinició el ESP32.

Posteriormente, se efectuó una nueva pulsación del botón afectado, seguida de cinco pulsaciones adicionales.

Las seis pulsaciones respondieron correctamente, alcanzando un **100 % de éxito en la verificación posterior**.

**Resultado acumulado:** 11 respuestas correctas en 12 pulsaciones registradas, correspondientes a un **91,7 % de éxito global**.

### 7. Análisis de la falla

La falta de respuesta se manifestó únicamente en el botón 6, mientras los otros cinco botones continuaron operando correctamente.

El reinicio del ESP32 permitió recuperar la respuesta del componente. Este comportamiento podría relacionarse con una anomalía temporal en la lectura de una entrada digital o en la ejecución del programa.

Sin embargo, no se realizaron mediciones eléctricas ni análisis de registros internos que permitan establecer una causa definitiva.

### 8. Relación con el problema original

El proyecto busca reducir los errores de clasificación de residuos mediante una interfaz que oriente al usuario hacia el contenedor adecuado.

Los resultados permiten evaluar parcialmente la confiabilidad de dicha interfaz, ya que comprueban la respuesta de los botones utilizados para seleccionar el tipo de residuo.

La falla detectada demuestra la importancia de verificar la estabilidad del sistema: una pulsación que no genera respuesta puede impedir que el usuario reciba la indicación correspondiente.

Esta prueba no mide directamente una reducción de los errores de reciclaje entre usuarios, por lo que esa validación requeriría ensayos adicionales.

### 9. Conclusión

El sistema respondió correctamente en cinco de las seis pulsaciones iniciales. La única falla observada ocurrió en el botón 6 y su funcionamiento se recuperó después de reiniciar el ESP32.

Las seis pulsaciones posteriores resultaron exitosas, lo que permitió verificar la recuperación operativa durante el período evaluado.

Como mejoras futuras, se recomienda investigar la causa de la falla, realizar pruebas de mayor duración y ampliar la validación a la transmisión de datos y al funcionamiento de los sensores.

### 10. Evidencia

Los resultados se encuentran documentados en `registro_fallas.md`, dentro de esta misma carpeta.

No se dispone en este registro de mediciones instrumentales, tiempos de respuesta ni registros automáticos de las pulsaciones.
