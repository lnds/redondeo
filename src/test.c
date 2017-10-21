#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "redondeo.h"

int main() {
	
	assert(redondeo_pesos(11) == 10);
	assert(redondeo_pesos(12) == 10);
	assert(redondeo_pesos(13) == 10);
	assert(redondeo_pesos(14) == 10);
	assert(redondeo_pesos(15) == 10);
	assert(redondeo_pesos(16) == 20);
	assert(redondeo_pesos(17) == 20);
	assert(redondeo_pesos(18) == 20);
	assert(redondeo_pesos(19) == 20);

	assert(redondeo_clasico(11) == 10);
	assert(redondeo_clasico(12) == 10);
	assert(redondeo_clasico(13) == 10);
	assert(redondeo_clasico(14) == 10);
	assert(redondeo_clasico(15) == 20);
	assert(redondeo_clasico(16) == 20);
	assert(redondeo_clasico(17) == 20);
	assert(redondeo_clasico(18) == 20);
	assert(redondeo_clasico(19) == 20);


	assert(redondeo_banquero(11) == 10);
	assert(redondeo_banquero(12) == 10);
	assert(redondeo_banquero(13) == 10);
	assert(redondeo_banquero(14) == 10);
	assert(redondeo_banquero(15) == 20);
	assert(redondeo_banquero(16) == 20);
	assert(redondeo_banquero(17) == 20);
	assert(redondeo_banquero(18) == 20);
	assert(redondeo_banquero(19) == 20);

	assert(redondeo_banquero(21) == 20);
	assert(redondeo_banquero(22) == 20);
	assert(redondeo_banquero(23) == 20);
	assert(redondeo_banquero(24) == 20);
	assert(redondeo_banquero(25) == 20);
	assert(redondeo_banquero(26) == 30);
	assert(redondeo_banquero(27) == 30);
	assert(redondeo_banquero(28) == 30);
	assert(redondeo_banquero(29) == 30);

}