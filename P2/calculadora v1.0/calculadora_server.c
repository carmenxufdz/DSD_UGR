/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"

double *suma_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;
	result = arg1 + arg2;
	return &result;
}

double *resta_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;
	result = arg1 - arg2;
	return &result;
}

double *multiplica_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;
	result = arg1 * arg2;
	return &result;
}

double *divide_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;
	result = arg1 / arg2;
	return &result;
}
