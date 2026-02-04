Este es el repositorio del proyecto IoT de Alejandro Macias, Rafael Garcia, Carlos Duran, Curro Blanco y Jorge Morales

**Introducción y objetivos**

El proyecto consiste en el diseño e implementacion de un sistema inteligente para accionar de manera remota una puerta de garaje. Para ello se nos han impuesto los siguientes requisitos:
- Hacer uso de un microcontrolador ESP8266 para controlar un motor DC o un servomotor.
- Usar un MOSFET o BJT para controlar el suministro de corriente al motor.
- Implementar diodos para proteger contra corrientes inversas.

El objetivo general es poder controlar la dirección de giro del motor, cambiando su polaridad, esto de manera remota.

**Descripción del hardware**

En el circuito, que se adjunta en la carpeta "files" de este repositorio, se utiliza una configuración de **Puente en H** para permitir la inversión de la polaridad en el motor, lo que se traduce en un cambio del sentido de giro.
El este circuito se hace una separacion entre la alimentacion del motor y el control del mismo, debido a que el uC no es capaz de suministrar la suficienta corriente como para operar el motor.

Para alternar la polaridad del motor se usa una combinación de BJT's NPN (BC337) y PNP (BC327), donde dos de los NPN se usan a modo de inversores, para poder activar los transistores PNP junto al correspondiente NPN dentro del puente en H.

Se han incluido 4 diodos en paralelo con los transistores, para protegerlos de la corrientes que el motor pudiera inducir en el circuito.

Tambien se han añadido resistencias en el circuito, que por un lado protengen al microcontrolador, y por otro se aseguran de que los transistores trabajen en zonda de saturación, actuando asi como interruptores.

**Arquitectura de Control y Software**












En este proyecto debemos crear una puerta de garaje que que cumpla los requisitos de la siguiente lista.

**ideas para el codigo**
en vez de usar dos pines distintos para los limites y abrir y cerrar la puerta, podriamos hacerlo todo con un mismo pin y un contador [0, 3], de modo que cuando el contador este a 0 la puerta esta parada, a 1 la puerta se abre, a 2 la puerta esta parada y a 3 la puerta se cierra.
Si lo hacemos de este modo no podriamos parar la puerta con una interrupcion como tenia pensado pero puede que sea mas facil de implementar.

**Lista de requisitos**
- Debe poder abrirse con el movil
- Debe usar un motor DC
- Debe usar un ESP8266
    - Para el ESP8266 (nuestra version es el nodeMCU) necesitamos alimentarlo con 5v constantes (https://lastminuteengineers.com/esp8266-pinout-reference/)
        - Una opcion es usar una powerbank y alimentarlo por USB
        - Otra opcion es usar una pila de 9v para todo el circuito y meter un regulador de voltage para la placa.
- El motor se debe accionar mediante un BJT -> usaremos el BJT BC337
    - En la carpeta "files" he añadido una imágen con el circuito que diseñamos en el crai para el motor, incluyendo los diodos para proteger de corrientes inversas. Tambien he puesto un MOSFET que nos puede servir (Que yo ya tengo de esos).
- Se debe usar un diodo para proteger de corrientes inversas

**Extras**
- [ Descartado ] Intentaremos implementar sensores NFC para que la puerta se abra automaticamente cuando llegue un coche con la tarjeta correspondiente (https://arduinogetstarted.com/tutorials/arduino-rfid-nfc-door-lock-system)
- [ Pendiente de implementar ] Implementaremos leds que indiquen si la puerta se esta abriendo y si el garaje esta ocupado o libre
- [ Pendiente de implementar ] La puerta debera cerrarse automaticamente pasado un cierto tiempo
- [ Descartado ]Mediante un sensor infrarojo haremos que la puerta no se cierre si hay un obstaculo en medio
- Implementaremos interruptores de limite para detectar si la puerta esta completamente abierta o cerrada
    - He añadido una imágen en la carpeta de "files" con un posible circuito para la implementacion de los interruptores, con esta implementación solo hariamos uso de un pin de la placa, lo que nos deja más pines libres para otras utilidades. Un problema de este circuito es que con el no sabremos si la puerta esta abirta o cerrada, solo sabremos que esta en uno de los extremos. En ese caso habria que hacerlo guardando en alguna variable si el ultimo estado de la puerta era "abriendo" ó "cerrando", y a partir de eso deducir que deberia hacer despues.