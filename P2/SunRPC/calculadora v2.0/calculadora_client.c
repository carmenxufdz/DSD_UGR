/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void reservarMatrix(matrix **m, int fil, int col){
	assert((*m)==NULL);

	*m=calloc(1, sizeof(matrix));

	(*m)->fil=fil;
	(*m)->col=col;

	(*m)->m.m_val=calloc(fil*col, sizeof(double));
	(*m)->m.m_len=fil*col;
}

void liberarMatrix(matrix **m){
	assert((*m)!=NULL);

	free((*m)->m.m_val);
	free(*m);

	*m=NULL;
}

void imprimirMatriz(matrix *m){
		for (int i = 0; i < m->fil; i++)
		{
			for (int j = 0; j < m->col; j++)
			{
				printf("%lf ", m->m.m_val[i*m->col+j]);
			}

			printf("\n");
			
		}
}


void rellenarMatriz(matrix *m1){
	for(int i=0; i<m1->fil; i++){
		printf("Fila %d valores: ", i);
		for (int j = 0; j < m1->col; j++)
		{
			scanf("%lf", &(m1->m.m_val[i*m1->col+j]));
		}
	}	
}

void reservarVector(v **vector, int tam){
	assert((*vector)==NULL);

	*vector=calloc(1, sizeof(v));
	(*vector)->v_val=calloc(tam, sizeof(int));
	(*vector)->v_len=tam;
}

void liberarVector(v **vector){
	assert((*vector)!=NULL);

	free((*vector)->v_val);
	free(*vector);

	*vector=NULL;
}

void imprimirVector(v *vector, int tam){
		printf("(");
		for (int i = 0; i < tam; i++)
		{
			printf("%lf", vector->v_val[i]);
			if(i != (tam-1))
				printf(", ");
		}
		printf(")");
}

void rellenarVector(v *vector, int tam){
	for(int i=0; i<tam; i++){
		scanf("%lf", &(vector->v_val[i]));
	}	
}

void
calculadora_1(char *host)
{
	CLIENT *clnt;
	char opcion = '\0';
	char operacion = '\0';

	int tam=0, fil=0, col=0;

	double *result_d=NULL;
	double arg1_d=0, arg2_d=0;
	int *result_i=NULL;
	int arg1_i=0, arg2_i=0;
	v *result_v=NULL;
	v *v1=NULL, *v2=NULL;
	matrix *result_m = NULL;
	matrix *m1=NULL, *m2=NULL;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, COMPLETA, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	do{
		// MENU PRINCIPAL
		printf("ELIJA UNA OPCION DE LA CALCULADORA:\n");
		printf("\t1. Operaciones Basicas\n");
		printf("\t2. Operaciones Avanzadas\n");
		printf("\t3. Operaciones Trigonometricas\n");
		printf("\t4. Operaciones Vectoriales\n");
		printf("\t5. Operaciones Matriciales\n");
		printf("\t6. Salir del Programa\n");
		scanf(" %c", &opcion);
		getchar();
		printf("\n");

		switch(opcion)
		{
			case '1': // OPERACIONES BASICAS
				do{
					printf("ELIJA UNA OPERACION:\n");
					printf("\t1. Suma\n");
					printf("\t2. Resta\n");
					printf("\t3. Multiplicacion\n");
					printf("\t4. Division\n");
					printf("\t5. Volver al menu principal\n");
					scanf(" %c", &operacion);
					getchar();
					printf("\n");

					switch(operacion)
					{
						case '1':	// Suma
							printf("Introduzca el primer numero: ");
							scanf("%lf", &arg1_d);
							printf("Introduzca el segundo numero: ");
							scanf("%lf", &arg2_d);
							printf("\n");

							result_d = suma_1(arg1_d, arg2_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: %f + %f = %f\n\n",arg1_d,arg2_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '2':	// Resta
							printf("Introduzca el primer numero: ");
							scanf("%lf", &arg1_d);
							printf("Introduzca el segundo numero: ");
							scanf("%lf", &arg2_d);
							printf("\n");

							result_d = resta_1(arg1_d, arg2_d, clnt);

							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: %f - %f = %f\n\n",arg1_d,arg2_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '3':	// Multiplicacion
							printf("Introduzca el primer numero: ");
							scanf("%lf", &arg1_d);
							printf("Introduzca el segundo numero: ");
							scanf("%lf", &arg2_d);
							printf("\n");

							result_d = multiplica_1(arg1_d, arg2_d, clnt);

							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: %f * %f = %f\n\n",arg1_d,arg2_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '4':	// Division
							printf("Introduzca el dividendo: ");
							scanf("%lf", &arg1_d);
							printf("Introduzca el divisor: ");
							scanf("%lf", &arg2_d);
							printf("\n");

							if(arg2_d == 0)
							{
								printf("No se puede dividir entre 0\n");
							}
							else
							{
								result_d = divide_1(arg1_d, arg2_d, clnt);
								if (result_d == (double *) NULL) {
									clnt_perror (clnt, "call failed");
								}
								else{
									printf("Resultado: %f / %f = %f\n\n",arg1_d, arg2_d,*result_d);
									xdr_free((xdrproc_t) xdr_double, result_d);
								}
							}
						break;
						
						case '5':
							printf("Volviendo al menu principal...\n\n");
						break;

						default: 
							printf("Opcion no valida\n\n"); 
						break;
					}
				} while (operacion!='5');
			break;

			case '2': // OPERACIONES AVANZADAS
				do{
					printf("ELIJA UNA OPERACION:\n");
					printf("\t1. Logaritmo base X\n");
					printf("\t2. Logaritmo neperiano\n");
					printf("\t3. Logaritmo base 10\n");
					printf("\t4. Modulo\n");
					printf("\t5. Potencia\n");
					printf("\t6. Raiz\n");
					printf("\t7. Factorial\n");
					printf("\t8. Volver al menu principal\n");
					scanf(" %c", &operacion);
					getchar();
					printf("\n");

					switch(operacion)
					{
						case '1':	// Logaritmo base X
							printf("Introduzca un numero (positivo): ");
							scanf("%d", &arg1_i);
							printf("Introduzca la base: ");
							scanf("%d", &arg2_i);
							printf("\n");
							if(arg2_i <= 0)
							{
								printf("No se puede hacer logaritmo con base menor o igual a 0\n\n");
							}
							else if(arg1_i < 0)
							{
								printf("No existe el logaritmo de un numero negativo\n\n");
							}
							else
							{
								result_d = logaritmo_1(arg1_i, arg2_i, clnt);
								if (result_d == (double *) NULL) {
									clnt_perror (clnt, "call failed");
								}
								else{
									printf("Resultado: log %d base %d = %f\n\n",arg1_i,arg2_i,*result_d);
									xdr_free((xdrproc_t) xdr_double, result_d);
								}
							}
						break;

						case '2':	// Logaritmo neperiano
							printf("Introduzca un numero: ");
							scanf("%d", &arg1_i);
							printf("\n");

							if(arg1_i < 0)
							{
								printf("No existe el logaritmo de un numero negativo\n\n");
							}
							else
							{
								result_d = log_n_1(arg1_i, clnt);
								if (result_d == (double *) NULL) {
									clnt_perror (clnt, "call failed");
								}
								else{
									printf("Resultado: logn %d = %f\n\n",arg1_i,*result_d);
									xdr_free((xdrproc_t) xdr_double, result_d);
								}
							}
						break;

						case '3':	// Logaritmo base 10
							printf("Introduzca un numero: ");
							scanf("%d", &arg1_i);
							printf("\n");
							if(arg1_i < 0)
							{
								printf("No existe el logaritmo de un numero negativo\n\n");
							}
							else
							{
								result_d = log10_1(arg1_i, clnt);
								if (result_d == (double *) NULL) {
									clnt_perror (clnt, "call failed");
								}
								else{
									printf("Resultado: log10 %d = %f\n\n",arg1_i,*result_d);
									xdr_free((xdrproc_t) xdr_double, result_d);
								}
							}
						break;
						
						case '4':	// Modulo
							printf("Introduzca un numero: ");
							scanf("%d", &arg1_i);
							printf("Introduzca el modulo: ");
							scanf("%d", &arg2_i);
							printf("\n");

							if(arg2_i == 0)
							{
								printf("No se puede hacer modulo 0\n\n");
							}
							else
							{
								result_i = modulo_1(arg1_i, arg2_i, clnt);
								if (result_i == (int *) NULL) {
									clnt_perror (clnt, "call failed");
								}
								else{
									printf("Resultado: %d mod %d = %d\n\n",arg1_i,arg2_i,*result_i);
									xdr_free((xdrproc_t) xdr_int, result_i);
								}
							}

						break;

						case '5':	// Potencia
							printf("Introduzca un numero: ");
							scanf("%d", &arg1_i);
							printf("Introduzca a cuanto quiere elevarlo: ");
							scanf("%d", &arg2_i);
							printf("\n");

							result_i = potencia_1(arg1_i, arg2_i, clnt);
						
							if (result_i == (int *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: %d ^ %d = %d\n\n",arg1_i,arg2_i,*result_i);
								xdr_free((xdrproc_t) xdr_int, result_i);
							}
						break;

						case '6':	// Raiz
							printf("Introduzca un numero: ");
							scanf("%lf", &arg1_d);
							printf("Introduzca la raiz (un numero entero positivo): ");
							scanf("%lf", &arg2_d);
							printf("\n");

							if(arg2_d <= 0)
							{
								printf("La raiz debe ser un numero positivo diferente de 0\n\n");
							}
							else if((((int)arg2_d) % 2 == 0) && arg1_d < 0)
							{
								printf("No se puede hacer la raiz %f de un numero negativo\n\n", arg2_d);
							}
							else
							{
								result_d = raiz_1(arg1_d, arg2_d, clnt);
								if (result_d == (double *) NULL) {
									clnt_perror (clnt, "call failed");
								}
								else{
									printf("Resultado: %f ^ 1/%f = %f\n\n",arg1_d,arg2_d,*result_d);
									xdr_free((xdrproc_t) xdr_double, result_d);
									
								}
							}
						break;

						case '7':	// Factorial
							printf("Introduzca un numero: ");
							scanf("%d", &arg1_i);
							printf("\n");
							
							result_i = factorial_1(arg1_i, clnt);

							if (result_i == (int *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: %d! = %d\n\n",arg1_i,*result_i);
								xdr_free((xdrproc_t) xdr_int, result_i);
							}
						break;

						case '8':
							printf("Volviendo al menu principal...\n\n");
						break;

						default: 
							printf("Opcion no valida\n\n"); 
						break;
					}
				} while (operacion!='8');
			break;

			case '3': // OPERACIONES TRIGONOMETRICAS
				do{
					printf("ELIJA UNA OPERACION:\n");
					printf("\t1. Seno\n");
					printf("\t2. Coseno\n");
					printf("\t3. Tangente\n");
					printf("\t4. Cosecante\n");
					printf("\t5. Secante\n");
					printf("\t6. Cotangente\n");
					printf("\t7. Volver al menu principal\n");
					scanf(" %c", &operacion);
					getchar();
					printf("\n");

					switch(operacion)
					{
						case '1':
							printf("Introduzca los grados: ");
							scanf("%lf", &arg1_d);
							printf("\n");

							result_d = seno_1(arg1_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: sin(%f) = %f\n\n",arg1_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;
						
						case '2':
							printf("Introduzca los grados: ");
							scanf("%lf", &arg1_d);
							printf("\n");

							result_d = coseno_1(arg1_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: cos(%f) = %f\n\n",arg1_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '3':
							printf("Introduzca los grados: ");
							scanf("%lf", &arg1_d);
							printf("\n");

							result_d = tangente_1(arg1_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: tan(%f) = %f\n\n",arg1_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '4':
							printf("Introduzca los grados: ");
							scanf("%lf", &arg1_d);
							printf("\n");

							result_d = cosecante_1(arg1_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: cosec(%f) = %f\n\n",arg1_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '5':
							printf("Introduzca los grados: ");
							scanf("%lf", &arg1_d);
							printf("\n");

							result_d = secante_1(arg1_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: sec(%f) = %f\n\n",arg1_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;

						case '6':
							printf("Introduzca los grados: ");
							scanf("%lf", &arg1_d);
							printf("\n");

							result_d = cotangente_1(arg1_d, clnt);
							
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: cotan(%f) = %f\n\n",arg1_d,*result_d);
								xdr_free((xdrproc_t) xdr_double, result_d);
							}
						break;
						
						case '7':
							printf("Volviendo al menu principal...\n\n");
						break;

						default: 
							printf("Opcion no valida\n\n");
						break;
					}
				} while (operacion!='7');
			break;

			case '4': // OPERACIONES VECTORIALES
				do{
					printf("ELIJA UNA OPERACION:\n");
					printf("\t1. Suma Vectorial\n");
					printf("\t2. Resta Vectorial\n");
					printf("\t3. Multiplicacion por Escalar\n");
					printf("\t4. Producto Escalar\n");
					printf("\t5. Producto Vectorial\n");
					printf("\t6. Volver al menu principal\n");
					scanf(" %c", &operacion);
					getchar();
					printf("\n");

					switch(operacion)
					{
						case '1':
							printf("Tamaño del vector: ");
							scanf("%d", &tam);

							reservarVector(&v1, tam);
							reservarVector(&v2, tam);

							printf("Primer vector: \n");
							rellenarVector(v1, tam);

							printf("Segundo vector: \n");
							rellenarVector(v2, tam);
							printf("\n");

							result_v = sumavectorial_1(*v1, *v2, clnt);
							if (result_v == (v *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: ");	
								imprimirVector(v1, tam);
								printf(" + ");	
								imprimirVector(v2, tam);
								printf(" = ");	
								imprimirVector(result_v, tam);

								printf("\n\n");
								xdr_free((xdrproc_t) xdr_double, result_v->v_val);
							}

							liberarVector(&v1);
							liberarVector(&v2);
						break;

						case '2':	// Resta Vectorial
							printf("Tamaño del vector: ");
							scanf("%d", &tam);

							reservarVector(&v1, tam);
							reservarVector(&v2, tam);

							printf("Primer vector: \n");
							rellenarVector(v1, tam);

							printf("Segundo vector: \n");
							rellenarVector(v2, tam);
							printf("\n");

							result_v = restavectorial_1(*v1, *v2, clnt);
							if (result_v == (v *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: ");	
								imprimirVector(v1, tam);
								printf(" - ");	
								imprimirVector(v2, tam);
								printf(" = ");	
								imprimirVector(result_v, tam);

								printf("\n\n");
								xdr_free((xdrproc_t) xdr_double, result_v->v_val);
							}

							liberarVector(&v1);
							liberarVector(&v2);
						break;

						case '3': // Multiplicacion por escalar
							printf("Tamaño del vector: ");
							scanf("%d", &tam);

							reservarVector(&v1, tam);

							printf("Primer vector: \n");
							rellenarVector(v1, tam);

							printf("Número por el cual multiplicar: \n");
							scanf("%lf", &arg2_d);

							result_v = multiplicaporescalar_1(*v1, arg2_d, clnt);
							if (result_v == (v *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: ");	
								imprimirVector(v1, tam);
								printf(" * %f = ", arg2_d);	
								imprimirVector(result_v, tam);

								printf("\n\n");
								xdr_free((xdrproc_t) xdr_double, result_v->v_val);
							}

							liberarVector(&v1);
						break;

						case '4': // Producto escalar
							printf("Tamaño del vector: ");
							scanf("%d", &tam);

							reservarVector(&v1, tam);
							reservarVector(&v2, tam);

							printf("Primer vector: \n");
							rellenarVector(v1, tam);

							printf("Segundo vector: \n");
							rellenarVector(v2, tam);
							printf("\n");

							result_d = productoescalar_1(*v1, *v2, clnt);
							if (result_d == (double *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: ");	
								imprimirVector(v1, tam);
								printf(" · ");	
								imprimirVector(v2, tam);
								printf(" = %f", *result_d);	

								printf("\n\n");
								xdr_free((xdrproc_t) xdr_double, result_d);
							}

							liberarVector(&v1);
							liberarVector(&v2);
						break;

						case '5': // Producto vectorial
							tam = 3;

							reservarVector(&v1, tam);
							reservarVector(&v2, tam);

							printf("Primer vector: \n");
							rellenarVector(v1, tam);

							printf("Segundo vector: \n");
							rellenarVector(v2, tam);
							printf("\n");

							result_v = productovectorial_1(*v1, *v2, clnt);
							if (result_v == (v *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("Resultado: ");	
								imprimirVector(v1, tam);
								printf(" x ");	
								imprimirVector(v2, tam);
								printf(" = ");	
								imprimirVector(result_v, tam);

								printf("\n\n");
								xdr_free((xdrproc_t) xdr_double, result_v->v_val);
							}

							liberarVector(&v1);
							liberarVector(&v2);
						break;
						
						case '6':
							printf("Volviendo al menu principal...\n\n");
						break;

						default: 
							printf("Opcion no valida\n\n");
						break;
					}
				} while (operacion!='6');
			break;

			case '5': // OPERACIONES MATRICIALES
				do{
					printf("ELIJA UNA OPERACION:\n");
					printf("\t1. Suma Matricial\n");
					printf("\t2. Resta Matricial\n");
					printf("\t3. Multiplicacion Matricial\n");
					printf("\t4. Volver al menu principal\n");
					scanf(" %c", &operacion);
					getchar();
					printf("\n");

					switch(operacion)
					{
						case '1':
							printf("Matriz num filas: ");
							scanf("%d", &fil);

							printf("Matriz columnas: ");
							scanf("%d", &col);

							reservarMatrix(&m1, fil, col);
							reservarMatrix(&m2, fil, col);

							printf("Primera matriz: \n");
							rellenarMatriz(m1);

							printf("Segunda matriz: \n");
							rellenarMatriz(m2);

							printf("Primera matriz: \n");
							imprimirMatriz(m1);
							printf("\n");

							printf("\nSegunda matriz: \n");
							imprimirMatriz(m2);

							printf("\n");

							result_m = sumamatricial_1(*m1, *m2, clnt);
							if (result_m == (matrix *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("La suma matricial es: \n");		

								imprimirMatriz(result_m);

								printf("\n");
								xdr_free((xdrproc_t) xdr_double, result_m->m.m_val);
								xdr_free((xdrproc_t) xdr_matrix, result_m);
							}

							liberarMatrix(&m1);
							liberarMatrix(&m2);


						break;
						case '2':	// Resta Matricial
							printf("Matriz num filas: ");
							scanf("%d", &fil);

							printf("Matriz columnas: ");
							scanf("%d", &col);

							reservarMatrix(&m1, fil, col);
							reservarMatrix(&m2, fil, col);

							printf("Primera matriz: \n");
							rellenarMatriz(m1);

							printf("Segunda matriz: \n");
							rellenarMatriz(m2);

							printf("Primera matriz: \n");
							imprimirMatriz(m1);
							printf("\n");

							printf("\nSegunda matriz: \n");
							imprimirMatriz(m2);

							printf("\n");

							result_m = restamatricial_1(*m1, *m2, clnt);
							if (result_m == (matrix *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("La suma matricial es: \n");		

								imprimirMatriz(result_m);

								printf("\n");
								xdr_free((xdrproc_t) xdr_double, result_m->m.m_val);
								xdr_free((xdrproc_t) xdr_matrix, result_m);
							}

							liberarMatrix(&m1);
							liberarMatrix(&m2);
						break;
						case '3':
							printf("Filas Matriz 1: ");
							scanf("%d", &fil);

							printf("Columnas Matriz 1: ");
							scanf("%d", &col);

							reservarMatrix(&m1, fil, col);
							reservarMatrix(&m2, col, fil);

							printf("Primera matriz: \n");
							rellenarMatriz(m1);

							printf("Segunda matriz: \n");
							rellenarMatriz(m2);

							printf("Primera matriz: \n");
							imprimirMatriz(m1);
							printf("\n");

							printf("\nSegunda matriz: \n");
							imprimirMatriz(m2);
							printf("\n");
							
							result_m = multmatricial_1(*m1, *m2, clnt);
							if (result_m == (matrix *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else{
								printf("La multiplicacion matricial es: \n");		
								imprimirMatriz(result_m);		
								printf("\n");

								xdr_free((xdrproc_t) xdr_double, result_m->m.m_val);
								xdr_free((xdrproc_t) xdr_matrix, result_m);

							}
							liberarMatrix(&m1);
							liberarMatrix(&m2);

						break;
						
						case '4':
							printf("Volviendo al menu principal...\n\n");
						break;

						default: 
							printf("Opcion no valida\n\n");
							printf("\n"); 
						break;
					}
				} while (operacion!='4');
			break;

			case '6':	// SALIR
				printf("Saliendo del programa...\n");
			break;

			default: 
				printf("Opcion no valida\n\n");
			break;
		}
	} while (opcion != '6');

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	calculadora_1 (host);
exit (0);
}
