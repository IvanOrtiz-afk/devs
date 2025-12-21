/**

IVAN  -----> OK
* Tener la opci¢n de cancelar un consumo despu‚s de haber elegido un men£ para comer pero
antes de pagar TODO EN EL MOMENTO.
Que la funcion tipo_consumo pueda avisar al resto si el cliente desea cancelar toda la operaci¢n

EVE   -----> OK
NOTA: se valido TODOS los ingresos de fechas, en todo el sistema.
* Quise ver menues filtrados por fecha, puse por error a¤o 1015 y el programa no lo noto (lo mismo con el dis y el mes)
VALIDAR TODO

EVE -----> OK
* Al cargar men£ de toda la semana si pulso cero sigue con la siguiente fecha en vez de volver al men£ principal.
Esta opci¢n usarla por si el cliente quiere cargar menues saltando d¡as, pero agregar algo para que el
cliente pueda cancelar todo el proceso y volver al men£ principal

EVE -----> OK
NOTA: se agrego entrada valida TEXTO_SIN_NUMEROS y se aplico en la carga de nombres en TODO el sistema
* Al cargar un men£ nuevo puedo darle como nombre NUMEROS, esta mal

EVE  -----> OK
* Al darle valor a un plato, si le agrego un precio negativo termina la carga

EVE -----> OK
* Al darle tipo de men£ (est ndar, caliaco, veg) si le doy letras termina la carga sin ninguna
validaci¢n, posiblemente pase lo mismo con valores negativos o fuera del rango (solamente funciona si son letras)

IVAN  -----> OK
* Agregar opci¢n de listar menues de toda la semana

IVAN  -----> OK
* Valorar platos POR FECHA y no solo los del dia de hoy

IVAN  -----> OK
* Al seleccionar un ID para valorar un plato, no se distingue bien los ID, emprolijar eso

IVAN  -----> OK
* Al agregar una valoraci¢n ya VALIDA, no me muestra ning£n texto de confirmaci¢n

IVAN  -----> OK
* Listar valoraci¢n tiene que preguntar el establecimiento primero

IVAN  -----> OK
* El top 3 de valoraci¢n tiene tambi‚n que preguntar establecimiento antes y mostrar el nombre de
cada men£ del top con SOLAMENTE los menus del establecimiento preguntado

EVE ----> OK
* Revisar en todas las entradas validas que este el IF de si pulso 0 volver atr s

IVAN ----> OK
* Arreglar el listado de platos mas vendidos BUG (BUG EN LA LINEA 200 DE menuadmin.cpp)

EVE ----> OK
* Ver todos los system pause y cls que se repiten mucho

EVE ----> OK
* Las facturas manuales deber¡an cargar el importe autom ticamente basado en los menues existentes

EVE ----> OK
* Cargar factura manual con algunos bugs

EVE ----> OK
* Al cargar una factura manual se debe tener en cuenta el medio de pago

IVAN ----> OK
* Clase cuenta corriente chequear y emprolijar dado que no se entiende, tambi‚n crear un tostring
que sirva para visualizar movimientos

EVE -----> OK
* Funcion para que un admin pueda ver listado todos los usuarios (nombres y rol solamente)

EVE -----> OK
*Que figure el medio de pago en el listado de facturas y emprolijar

IVAN -----> OK
*En consumos, agregar el nombre de la persona y el importe

EVE -----> OK
*Factura manual que descuente el 10% en efectivo

IVAN -----> OK
*Al realizar un pago debe traer el saldo de la cuenta corriente, y que NO genere factura

EVE -----> OK
*Listar PAGOS emprolijar, ver si llegamos a filtrar por id

IVAN -----> OK
*si una cuenta corriente esta en 0 pesos figura en DEUDA, arreglar (ver cc del comensal 1)

IVAN -----> OK
*valoracion por fecha

EVE -----> OK
*Que quede bien claro el guardar y salir en las modificaciones

IVAN/EVE AL FINAL
* VER SI SALE, una funci¢n que muestre los platos mas consumidos pero de todos los tiempos (usar memoria din mica)

EVE -----> OK
*BUG ENCONTRADO, deja crear usuarios que ya existen, sobreescribiendolos
linea 17 en LOGIN

IVAN
* Actualizar el informe!!!!


IR PONIENDO LOS MENUS REVISADOS!!!!



*/
