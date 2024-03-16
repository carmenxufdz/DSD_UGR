/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "calculadora.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

double *
suma_1(double arg1, double arg2,  CLIENT *clnt)
{
	suma_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, SUMA, (xdrproc_t) xdr_suma_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
resta_1(double arg1, double arg2,  CLIENT *clnt)
{
	resta_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, RESTA, (xdrproc_t) xdr_resta_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
multiplica_1(double arg1, double arg2,  CLIENT *clnt)
{
	multiplica_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, MULTIPLICA, (xdrproc_t) xdr_multiplica_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
divide_1(double arg1, double arg2,  CLIENT *clnt)
{
	divide_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, DIVIDE, (xdrproc_t) xdr_divide_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
modulo_1(int arg1, int arg2,  CLIENT *clnt)
{
	modulo_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, MODULO, (xdrproc_t) xdr_modulo_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
potencia_1(int arg1, int arg2,  CLIENT *clnt)
{
	potencia_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, POTENCIA, (xdrproc_t) xdr_potencia_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
raiz_1(double arg1, double arg2,  CLIENT *clnt)
{
	raiz_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, RAIZ, (xdrproc_t) xdr_raiz_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
factorial_1(int arg1,  CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, FACTORIAL,
		(xdrproc_t) xdr_int, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
logaritmo_1(int arg1, int arg2,  CLIENT *clnt)
{
	logaritmo_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, LOGARITMO, (xdrproc_t) xdr_logaritmo_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
log_n_1(int arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, LOG_N,
		(xdrproc_t) xdr_int, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
log10_1(int arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, LOG10,
		(xdrproc_t) xdr_int, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
seno_1(double arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SENO,
		(xdrproc_t) xdr_double, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
coseno_1(double arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, COSENO,
		(xdrproc_t) xdr_double, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
tangente_1(double arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, TANGENTE,
		(xdrproc_t) xdr_double, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
secante_1(double arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SECANTE,
		(xdrproc_t) xdr_double, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
cosecante_1(double arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, COSECANTE,
		(xdrproc_t) xdr_double, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
cotangente_1(double arg1,  CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, COTANGENTE,
		(xdrproc_t) xdr_double, (caddr_t) &arg1,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

v *
sumavectorial_1(v arg1, v arg2,  CLIENT *clnt)
{
	sumavectorial_1_argument arg;
	static v clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, SUMAVECTORIAL, (xdrproc_t) xdr_sumavectorial_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_v, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

v *
restavectorial_1(v arg1, v arg2,  CLIENT *clnt)
{
	restavectorial_1_argument arg;
	static v clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, RESTAVECTORIAL, (xdrproc_t) xdr_restavectorial_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_v, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

v *
multiplicaporescalar_1(v arg1, double arg2,  CLIENT *clnt)
{
	multiplicaporescalar_1_argument arg;
	static v clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, MULTIPLICAPORESCALAR, (xdrproc_t) xdr_multiplicaporescalar_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_v, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
productoescalar_1(v arg1, v arg2,  CLIENT *clnt)
{
	productoescalar_1_argument arg;
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, PRODUCTOESCALAR, (xdrproc_t) xdr_productoescalar_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

v *
productovectorial_1(v arg1, v arg2,  CLIENT *clnt)
{
	productovectorial_1_argument arg;
	static v clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, PRODUCTOVECTORIAL, (xdrproc_t) xdr_productovectorial_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_v, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

matrix *
sumamatricial_1(matrix arg1, matrix arg2,  CLIENT *clnt)
{
	sumamatricial_1_argument arg;
	static matrix clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, SUMAMATRICIAL, (xdrproc_t) xdr_sumamatricial_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_matrix, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

matrix *
restamatricial_1(matrix arg1, matrix arg2,  CLIENT *clnt)
{
	restamatricial_1_argument arg;
	static matrix clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, RESTAMATRICIAL, (xdrproc_t) xdr_restamatricial_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_matrix, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

matrix *
multmatricial_1(matrix arg1, matrix arg2,  CLIENT *clnt)
{
	multmatricial_1_argument arg;
	static matrix clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, MULTMATRICIAL, (xdrproc_t) xdr_multmatricial_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_matrix, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
