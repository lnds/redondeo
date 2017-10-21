#ifndef __REDONDEO_H
#define __REDONDEO_H

/*
** Define tipos y prototipos para las funciones de redondeo
*/

typedef unsigned long long MONEDA;

/* La funcion redondeo_pesos cumple con la norma indicada por el Banco Central
** Las otras funciones estan para efectos demostrativos
** El autor no ofrece garantias sobre este código.
** Ver LICENSE para detalles.
*/
extern MONEDA redondeo_pesos(MONEDA);
extern MONEDA redondeo_clasico(MONEDA);
extern MONEDA redondeo_banquero(MONEDA);

#endif