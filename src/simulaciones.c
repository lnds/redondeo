#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include "redondeo.h"


void simulacion_1() {
	
	MONEDA suma_0 = 0;
	MONEDA suma_1 = 0; // redondeo half down
	MONEDA suma_2 = 0; // redondeo clasico
	MONEDA suma_3 = 0; // redondeo banquero
	for (unsigned long i = 0; i <  UINT_MAX; i++) {
		suma_0 += i;
		suma_1 += redondeo_pesos(i);
		suma_2 += redondeo_clasico(i);
		suma_3 += redondeo_banquero(i);
	}
	printf("simulacion 1\n");
	printf("(0) suma sin redondeo         : %'19llu\n", suma_0);
	printf("(1) suma con redondeo chileno : %'19llu\n", suma_1);
	printf("(2) suma con redondeo clasico : %'19llu\n", suma_2);
	printf("(3) suma sin redondeo banquero: %'19llu\n", suma_3);

	printf("diferencia (1) - (0)          = %'19lld\n", -(suma_0 - suma_1));
	printf("diferencia (2) - (0)          = %'19lld\n", suma_2 - suma_0);
	printf("diferencia (3) - (0)          = %'19lld\n", -(suma_0 - suma_3));

}

void simulacion_2() {
	MONEDA suma_0 = 0;
	MONEDA suma_1 = 0; // redondeo half down
	MONEDA suma_2 = 0; // redondeo clasico
	MONEDA suma_3 = 0; // redondeo banquero
	printf("simulacion 2\n");
	unsigned long iters = 0;
	MONEDA tope = 1000*1000*1000;
	for (unsigned long i = 0; i < tope; i++) {
		MONEDA valor = rand();
		suma_0 += valor;
		suma_1 += redondeo_pesos(valor);
		suma_2 += redondeo_clasico(valor);
		suma_3 += redondeo_banquero(valor);
		iters++;
	}
	printf("iteraciones: %lu\n", iters);
	printf("(0) suma sin redondeo         : %'19llu\n", suma_0);
	printf("(1) suma con redondeo chileno : %'19llu\n", suma_1);
	printf("(2) suma con redondeo clasico : %'19llu\n", suma_2);
	printf("(3) suma sin redondeo banquero: %'19llu\n", suma_3);

	printf("diferencia (1) - (0)          = %'19lld\n", suma_0 > suma_1 ? -(suma_0 - suma_1) : (suma_1 - suma_0));
	printf("diferencia (2) - (0)          = %'19lld\n", suma_0 > suma_2 ? -(suma_0 - suma_2) : (suma_2 - suma_0));
	printf("diferencia (3) - (0)          = %'19lld\n", suma_0 > suma_3 ? -(suma_0 - suma_3) : (suma_3 - suma_1));
}

int main() {
	simulacion_1();
	simulacion_2();
}