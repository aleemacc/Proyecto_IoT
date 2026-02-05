Este es el repositorio del proyecto IoT de Alejandro Macias, Rafael Garcia, Carlos Duran, Curro Blanco y Jorge Morales.

**Introducción y objetivos**

El proyecto consiste en el diseño e implementación de un sistema inteligente para accionar de manera remota una puerta de garaje. Para ello se nos han impuesto los siguientes requisitos:
- Hacer uso de un microcontrolador ESP8266 para controlar un motor DC o un servomotor.
- Usar un MOSFET o BJT para controlar el suministro de corriente al motor.
- Implementar diodos para proteger contra corrientes inversas.

El objetivo general es poder controlar la dirección de giro del motor, cambiando su polaridad, esto de manera remota.

**Descripción del hardware**

En el circuito, que se adjunta en la carpeta "files" de este repositorio, se utiliza una configuración de **Puente en H** para permitir la inversión de la polaridad en el motor, lo que se traduce en un cambio del sentido de giro.
En este circuito se hace una separación entre la alimentacion del motor y el control del mismo, debido a que el uC no es capaz de suministrar la suficiente corriente como para operar el motor.

Para alternar la polaridad del motor se usa una combinación de BJT's NPN (BC337) y PNP (BC327), donde dos de los NPN se usan a modo de inversores, para poder activar los transistores PNP junto al correspondiente NPN dentro del puente en H.

Se han incluido 4 diodos (1N4007) en paralelo con los transistores, para protegerlos de la corrientes que el motor pudiera inducir en el circuito.

Tambien se han añadido resistencias en el circuito, que por un lado protengen al microcontrolador, y por otro se aseguran de que los transistores trabajen en zonda de saturación, actuando así como interruptores.

En la parte del circuito dedicada al control del funcionamiento de la puerta, hemos añadido un boton que se encarga de abrir y cerrar la puerta, ademas de dos interruptores límite que nos indican cuando la puerta esta en alguno de sus extremos, ambos haciendo uso de la resistencia de pull_up integrada en el ESP8266.

**Arquitectura de Control y Software**

En este repositorio se incluyen dos versiones del codigo fuente, la primera de ellas (/src/main.cpp) esta pensada para ser usada solo con botones físicos, la segunda (/files/puerta_garaje_feb03b/puerta_garaje_feb03b.ino) es el codigo del proyecto realizado en Arduino Cloud y es una adaptacion del codigo original, modificado para poder manejar la puerta desde la aplicación de Arduino. Este último opera de la siguiente manera:
- Primero se inicializa el servicio de la nube de Arduino, luego los pines encargados del manejo del motor se ponen a LOW, para que el estado inicial del motor sea parado.
- Luego, dentro del loop, definimos el resto del comportamiento, de manera que al pulsarse alguno de los botones límite, si estos no estaban pulsados antes, el motor se para.
- Despues de esto, se comprueba si el boton de abrir y cerrar ha sido pulsado, si es el caso y el motor esta parado, este empezará a girar en sentido opuesto al que habia girado la ultima vez.
- Por último se define el comportamiento cuando se actuan los botones en la aplicación, que es igual al comportamiento de los botones físicos equivalentes.