/**

IVAN  -----> OK*
* Tener la opci¢n de cancelar un consumo despu‚s de haber elegido un men£ para comer pero
antes de pagar TODO EN EL MOMENTO.
Que la funcion tipo_consumo pueda avisar al resto si el cliente desea cancelar toda la operaci¢n

EVE   -----> OK*
NOTA: se valido TODOS los ingresos de fechas, en todo el sistema.
* Quise ver menues filtrados por fecha, puse por error a¤o 1015 y el programa no lo noto (lo mismo con el dia y el mes)
VALIDAR TODO

EVE -----> OK*
* Al cargar men£ de toda la semana si pulso cero sigue con la siguiente fecha en vez de volver al men£ principal.
Esta opci¢n usarla por si el cliente quiere cargar menues saltando d¡as, pero agregar algo para que el
cliente pueda cancelar todo el proceso y volver al men£ principal

EVE -----> OK*
NOTA: se agrego entrada valida TEXTO_SIN_NUMEROS y se aplico en la carga de nombres en TODO el sistema
* Al cargar un men£ nuevo puedo darle como nombre NUMEROS, esta mal

EVE  -----> OK*
* Al darle valor a un plato, si le agrego un precio negativo termina la carga

EVE -----> OK*
* Al darle tipo de men£ (est ndar, caliaco, veg) si le doy letras termina la carga sin ninguna
validaci¢n, posiblemente pase lo mismo con valores negativos o fuera del rango (solamente funciona si son letras)

IVAN  -----> OK*
* Agregar opci¢n de listar menues de toda la semana

EVE ----> OK*
* Revisar en todas las entradas validas que este el IF de si pulso 0 volver atr s

IVAN ----> OK*
* Arreglar el listado de platos mas vendidos BUG (BUG EN LA LINEA 200 DE menuadmin.cpp)

EVE ----> OK*
* Ver todos los system pause y cls que se repiten mucho

EVE ----> OK*
* Las facturas manuales deber¡an cargar el importe autom ticamente basado en los menues existentes

EVE ----> OK*
* Cargar factura manual con algunos bugs

EVE ----> OK*
* Al cargar una factura manual se debe tener en cuenta el medio de pago

IVAN ----> OK*
* Clase cuenta corriente chequear y emprolijar dado que no se entiende, tambi‚n crear un tostring
que sirva para visualizar movimientos

EVE -----> OK*
* Funcion para que un admin pueda ver listado todos los usuarios (nombres y rol solamente)

EVE -----> OK*
*Que figure el medio de pago en el listado de facturas y emprolijar

IVAN -----> OK*
*En consumos, agregar el nombre de la persona y el importe

EVE -----> OK*
*Factura manual que descuente el 10% en efectivo

IVAN -----> OK*
*Al realizar un pago debe traer el saldo de la cuenta corriente, y que NO genere factura

EVE -----> OK*
*Listar PAGOS emprolijar, ver si llegamos a filtrar por id

IVAN -----> OK*
*si una cuenta corriente esta en 0 pesos figura en DEUDA, arreglar (ver cc del comensal 1)

EVE -----> OK*
*Que quede bien claro el guardar y salir en las modificaciones

IVAN/EVE AL FINAL
* VER SI SALE, una funci¢n que muestre los platos mas consumidos pero de todos los tiempos (usar memoria din mica)

EVE -----> OK*
*BUG ENCONTRADO, deja crear usuarios que ya existen, sobreescribiendolos
linea 17 en LOGIN

EVE
* Ir cargando las bases de datos nuevas a medida que se revisan los menues en busca de bugs

IVAN -----> OK
* Ver el filtrado por fecha de los menues, si yo lo ejecuto un domingo tambien me trae el lunes de la semana siguiente

IVAN -----> OK
* Arreglar la funcion de seteo de fecha en valoraciones (linea 1177)

IVAN -----> OK
* Arreglar valoraciones por fecha BUG

IVAN -----> OK
* Valorar por plato de hoy emprolijar y arreglar BUG

IVAN -----> OK
* Probar top 3 de valoraciones y todo lo referido a las valoraciones

IVAN -----> OK
* Un cliente puede valorar platos de cualquier establecimiento, arreglar

IVAN -----> OK
* Al valorar un plato no puedo ver los establecimientos en la lista

IVAN -----> OK
* En platos mas vendidos que figure el establecimiento del menu correspondiente

IVAN -----> OK
* Al crear un nuevo usuario salta magicamente a la funcion de eliminar usuario

IVAN
* Actualizar el informe!!!!


IR PONIENDO LOS MENUS REVISADOS!!!

----------------
MENU PLATOS
----------------
LISTADO DE MENUS > VER MENUS DE HOY ---> OK
LISTADO DE MENUS > VER MENUS POR FECHA ---> OK
LISTADO DE MENUS > VER MENUS POR SEMANA ---> OK

VALORAR UN PLATO > VALORAR PLATO DEL DIA ---> BUG: TRAE UN PROMEDIO ERRONEO
VALORAR UN PLATO > VALORAR PLATO POR FECHA ---> BUG: SI NO ENCUENTRA ESTABLECIMIENTO SIGUE TRAYENDO A PELUQUERIA SUSANITA, ADEMAS FALTA AGREGAR EL PROMEDIO

LISTAR VALORACIONES ---> OK

CARGAR NUEVO PLATO > CARGAR MENU DEL DIA ---> OK
CARGAR NUEVO PLATO > CARGAR MENU DE TODA LA SEMANA ---> OK

ELIMINAR UN PLATO -> ELIMINAR PLATO DE HOY  ---> OK
ELIMINAR UN PLATO -> ELIMINAR PLATO POR DIA ESPECIFICO ---> OK

MODIFICAR UN PLATO ---> OK

----------------
MENU FACTURACION
----------------

LISTAR FACTURAS  ---> OK
NUEVA FACTURA  ---> OK

----------------
MENU CC
----------------

VER ESTADO DE CUENTA CORRIENTE  ---> OK
REALIZAR UN PAGO ---> OK
LISTAR PAGOS REALIZADOS  ---> OK


----------------
MENU CONSUMOS
----------------

LISTAR CONSUMOS ---> VER: ESTARIA BUENO SI FIGURA EN QUE ESTABLECIMIENTO SE VENDIO
VER CONSUMOS POR FECHA ---> BUG: MUESTRA PLATO MAS VENDIDO, PERO NO SE ENTIENDE SI DE ESE DIA O DE LA SEMANA, ESTARIA BUENO CAMBIARLE EL NOMBRE A LA OPCION
PLATOS MAS VENDIDOS ---> OK


----------------
MENU COMENSALES
----------------

CARGAR ---> OK
MODIFICAR ---> OK
ELIMINAR ---> OK
LISTAR ---> OK

----------------
MENU ESTABLECIMIENTOS
----------------

CARGAR ---> OK
MODIFICAR ---> OK
ELIMINAR ---> OK
LISTAR ---> OK

----------------
MENU USUARIOS
----------------

CARGAR ---> OK
MODIFICAR ---> OK
ELIMINAR ---> OK
LISTAR ---> OK

----------------
MENU CONFIGURACION
----------------








 



*/
