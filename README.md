# redondeo
Discute algoritmos de redondeo para implementar la norma chilena que elimina las monedas de baja denominación ($1 y $5)

## El problema

En octubre de 2017 el Banco Central Chileno informa que las monedas de 1 y 5 pesos dejarán de circular.
La razón de esto es que el costo de producirlas excede el valor de las mismas.
Ante esto se sugiere que las transacciones en dinero efectivo hagan un redondeo,
de modo que cuando un monto a pagar termine en 5, 4, 3, 2 ó 1 quede la cifra final en 0. 
En el caso contrario, es decir, cuando termine en 6, 7, 8 ó 9 la cifra quede en la decena siguiente.

Ejemplos:

  - Si la cifra es 10.522 queda en 10.520
  - Si la cifra es 10.525 queda en 10.520
  - Si la cifra es 10.527 queda en 10.530.
  
Por alguna razón, esta medida ha exacerbado a algunas personas de la industria TI nacional, 
porque consideran aberrante que se aproxime de esa manera.

Ellos esperarían que se aproximara de la "forma tradicional", de modo que lo que termine en 5 pase a la decena superior.

En la propuesta de ellos, esto es lo que debería pasar:

  - Si la cifra es 10.522 queda en 10.520
  - Si la cifra es 10.525 queda en 10.530
  - Si la cifra es 10.527 queda en 10.530.
  
Ahora bien, si lo vemos desde el punto de vista del consumidor, esta medida los beneficia en 5 de 9 ocasiones, en el otro caso, 
los beneficia en sólo 4 de 9 ocasiones.

Además se argumenta que, acá en Chile, inventamos nuestros propios estándares, que no se consulta a los expertos, etc.

La verdad, es que  estoy de acuerdo en que en muchas ocasiones el gobierno chileno ha establecido estándares extraños 
sin medir el impacto en la industria TI, por ejemplo, en el caso del manejo de los horarios, sobre lo que me he pronunciado 
previamente (http://www.lnds.net/blog/2011/03/la-hora-como-un-parametro.html).

Una de las críticas a esta medida viene de Alejandro Barros, con quien hemos reclamado ante las arbitrariedades de la autoridad
en estándares técnicos. Pueden leer la posición de Alejandro acá: http://www.alejandrobarros.com/estandares-chilensis-si-el-estandar-no-gusta-usamos-otro/

Esta vez no estoy de acuerdo con Alejandro, por los siguientes motivos:

1. No hay un estándar para redondear cifras.
2. La medida sólo tiene impacto en los pagos en efectivo.
3. La medida beneficia a los consumidores.
4. Es una medida técnica en el ámbito económico, donde se debe velar por disminuir efectos como la inflación, que son mayores
a los costos TI que tenga implementar este cambio.
5. No es primera vez que se hace.

## ¿Alguien recuerda los centavos?

Sí, en Chile había centavos, pero estos se eliminaro en 1984, en este link http://mickychile1976.blogspot.cl/2012/06/historia-monedas-y-billetes-chilenos.html
pueden encontrar la hstoria de nuestro billetes y monedas.

En 1984 se emitió una norma que eliminó esta denominación de circulación.

La página en Wikipedia sobre el peso chileno es bien ilustrativa https://es.wikipedia.org/wiki/Peso_(moneda_de_Chile)

Desde 1984 tenemos que aproximar todas las operaciones a la unidad. 

Así que ya hacemos aproximaciones hace mucho rato.
Esto es muy relevante pues se usan diversas unidades alternativas en nuestra economía, como la UF o la UTM, que 
introducen fracciones y en esos casos se debe redondear. 

## ¿Cómo redondear?

No hay una forma correcta de redondear. La razón es que en nuestro sistema decimal introduce una asimetría cuando hacemos
esta operación.

Por ejemplo, ¿qué hacemos con 10.5?

Podemos hacer el redondeo "tradicional", conocido como HALF-UP que lo aproxima a la unidad siguiente, quedando en 11.

Pero eso introduce un error acumulado en nuestras aproximaciones hacia arriba en 5 de 9 veces.

La opción contrara, aproximar 10.5, conocida como HALF-DOWN aproxima hacia la unidad anterior, quedando en 10, y en este caso
nuestro error acumulado va hacia abajo.

Hay otras formas de redondear que intentan compensar este error, por ejemplo, el algoritmo del banquero que aproxima
hacia arriba si la parte entera es par, o hacia abajo si la parte entera es impar.

Hay que notar que el algoritmo del banquero es la forma de redondear estándar definida por la IEEE en la especificación de punto flotante IEEE-754, así que es esta función la más usada 
en muchas bibliotecas de código en diversos lenguajes.

En este caso 10.5, quedara como 11, pero 9.5 quedaría como 9.0.

Otra posibilidad es hacer lo contrarior, si es impar aproximar para arriba y si es par hacia abajo.

Algunos proponen que sea al azar, es decir, cada vez que veamos un .5 en la parte decimal tomemos una moneda y
si sale cara aproximamos hacia abajo y si sale sello aproximamos hacia abajo.

## Algoritmos para redondear

Este repositorio contiene implementaciones para aplicar el redondeo requerido por esta norma del banco central, discuto diversos
algoritmos y mido su eficiencia. 

Además hago una simulación del impacto de cada algoritmo en la economía, esto es más bien un juego, pero que arroja alguna luz
sobre el impacto de aplicar un algoritmo u otro.

Mi intención es que si alguien tiene que aproximar cifras siga las recomendaciones descritas acá, 
porque es muy probable que lo hagan mal.

### Malas formas de aproximar a la decena

Un algoritmo malisimo para aproximar sería usando strings, pero es algo que he visto tantas veces que debo discutirlo,
si usted ve esto en su base de código pida que se corrija de inmediato.

El algortimo en este caso sería algo así:

    sea num el número a aproximar.
    sea snum el número expresado como string.
    sea last = snum[length(snum)-1] // asumo que los strings se enumeran desde cero.
    asignar snum[length(snum)-1] = '0'
    si last > '5' entonces
        sea p = snum[length(snum)-2]
        asignar snum[length(snum)-2] = char(int(i)+1)
    
Otra forma, menos mala, es la que se le ocurriría al 99% de los programadores:

    fun redondear_pesos(monto) {
      return round ( monto / 10.0 ) * 10.0
    }

Esto depende de cómo se implemente round. 

En Java existe la posibilidad de implementar HALF_DOWN, así que el redondeo iría más o menos del siguiente modo:

    public static double redondearPesos(double d) {
      return new BigDecimal(d/10.0).setScale(0, RoundingMode.HALF_DOWN) .doubleValue() * 10.0;
    }
  
Esto es horrible, por muchas razones, pero funciona. 
Sin embargo hay formas mejores de hacer esto.

## Mejores formas de redondear a la decena

Lo que queremos es redondear hacia abajo si termina en 5, 4, 3, 2 ó 1. 
Entonces es bastante simple si usamos números enteros (los pesos chilenos no aceptan decimales, así que podemos
asumir que los montos serán enteros con tranquilidad, esto no es cierto si trabajas con UF o UTM, así que debes
transformar antes tus valores).

El algoritmo sería:

    func redondear_peso(monto) {
      let resto = monto % 10;
      if resto < 6 {
        return monto - resto;
      } 
      else {
        return monto + 10 - resto;
      }
    }
 
Esta forma es eficiente, no requiere transformaciones ni multiplicaciones ni divisiones, que son operaciones costosas.
No pierde precisión, es fácil de entender y probar.


## Referencias

Sobre redondeo, este gran artículo en Wikipedia https://en.wikipedia.org/wiki/Rounding
