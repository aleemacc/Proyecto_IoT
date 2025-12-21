**Lista de requisitos**
- Debe poder abrirse con el movil
- Debe usar un motor DC
- Debe usar un ESP8266
    - Para el ESP8266 (nuestra version es el nodeMCU) necesitamos alimentarlo con 5v constantes (https://lastminuteengineers.com/esp8266-pinout-reference/)
        - Una opcion es usar una powerbank y alimentarlo por USB
        - Otra opcion es usar una pila de 9v para todo el circuito y meter un regulador de voltage para la placa.
- El motor se debe accionar mediante un MOSFET 
    - En la carpeta "files" he añadido una imágen con el circuito que diseñamos en el crai para el motor, incluyendo los diodos para proteger de corrientes inversas. Tambien he puesto un MOSFET que nos puede servir (Que yo ya tengo de esos).
- Se debe usar un diodo para proteger de corrientes inversas
- Intentaremos implementar sensores NFC para que la puerta se abra automaticamente cuando llegue un coche con la tarjeta correspondiente (https://arduinogetstarted.com/tutorials/arduino-rfid-nfc-door-lock-system)
- Implementaremos leds que indiquen si la puerta se esta abriendo y si el garaje esta ocupado o libre
- La puerta debera cerrarse automaticamente pasado un cierto tiempo
- Mediante un sensor infrarojo haremos que la puerta no se cierre si hay un obstaculo en medio
- Implementaremos interruptores de limite para detectar si la puerta esta completamente abierta o cerrada
    - He añadido una imágen en la carpeta de "files" con un posible circuito para la implementacion de los interruptores, con esta implementación solo hariamos uso de un pin de la placa, lo que nos deja más pines libres para otras utilidades. Un problema de este circuito es que con el no sabremos si la puerta esta abirta o cerrada, solo sabremos que esta en uno de los extremos. En ese caso habria que hacerlo guardando en alguna variable si el ultimo estado de la puerta era "abriendo" ó "cerrando", y a partir de eso deducir que deberia hacer despues.


**Lista de la compra**
- Regulador de voltage para alimentar todo con una (o más) pilas de 9v y que a la placa le lleguen solo 5v. (https://es.aliexpress.com/item/1005006461126809.html?spm=a2g0o.productlist.main.10.53adU5B6U5B6g7&algo_pvid=41fbad50-a05f-4620-a6d5-d181dfd77aec&algo_exp_id=41fbad50-a05f-4620-a6d5-d181dfd77aec-9&pdp_ext_f=%7B%22order%22%3A%22735%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%213.51%210.94%21%21%2128.29%217.60%21%402103985c17663203303918095e7fc3%2112000037280820594%21sea%21ES%211862890057%21X%211%210%21n_tag%3A-29919%3Bd%3A5f5714f9%3Bm03_new_user%3A-29895%3BpisId%3A5000000196540751&curPageLogUid=KsE6zFIZxnIx&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006461126809%7C_p_origin_prod%3A)
- Motor, el modelo N30 nos deveria valer para usar con una pila de 9v, a parte tendria que buscar algún diseño en 3D para el engranage (https://es.aliexpress.com/item/1005009160450921.html?spm=a2g0o.productlist.main.6.366b11aa2uCJS7&algo_pvid=4667b8d3-28c0-4cad-8d5b-d63cb8b8aa51&algo_exp_id=4667b8d3-28c0-4cad-8d5b-d63cb8b8aa51-5&pdp_ext_f=%7B%22order%22%3A%22111%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.95%211.75%21%21%2115.74%2114.13%21%40211b80c217663210509281247eaa6d%2112000048142885904%21sea%21ES%211862890057%21X%211%210%21n_tag%3A-29919%3Bd%3A5f5714f9%3Bm03_new_user%3A-29895%3BpisId%3A5000000196540751&curPageLogUid=ET8oMZ8yc8LH&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005009160450921%7C_p_origin_prod%3A#nav-specification)