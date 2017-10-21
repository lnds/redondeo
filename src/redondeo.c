#include "redondeo.h"

/* redondeo_pesos:
   Esta función redondea de acuerdo a lo dispuesto por el Banco Central de Chile
   ante la retirada de circulación de las monedas de $1 y $5.

*/
MONEDA redondeo_pesos(MONEDA monto) {
	MONEDA resto = monto % 10;
	return resto < 6 ? monto - resto : monto + 10 - resto;
}

extern MONEDA redondeo_clasico(MONEDA monto) {
	MONEDA resto = monto % 10;
	return resto < 5 ? monto - resto : monto + 10 - resto;
}

extern MONEDA redondeo_banquero(MONEDA monto) {
	MONEDA base = monto / 10;
	MONEDA resto = monto % 10;
	if ((base & 0x1) == 1) {
		return resto < 5 ? monto - resto : monto + 10 - resto;
	} else {
		return resto < 6 ? monto - resto : monto + 10 - resto;
	}
}
