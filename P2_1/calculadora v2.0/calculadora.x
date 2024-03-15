/*
CALCULADORA VERSION 2.0 COMPLETA
OPERACIONES:
	BÁSICAS:
    Suma
    Resta
    Multiplicacion
    Division
	Módulo
	Potencia
	Raíz
	Factorial

	LOGARITMOS:
	Logaritmo base X
	Logaritmo neperiano
	Logaritmo base 10

	TRIGONOMETRÍA:
	Seno 
	Coseno
	Tangente

	VECTORES 3D:
	Suma
	Resta
	Multiplicacion por Entero
	Producto Escalar
	Producto Vectorial

	MATRICES:
	Suma
	Resta
	Multiplicacion

*/

typedef double m<>;

struct matrix{
    int rows;
    int cols;
    m data;
};

struct vector3D{
	int x;
	int y;
	int z;
};

program CALCULADORA {
	version COMPLETA {
		double SUMA(double,double) = 1;
		double RESTA(double,double) = 2;
		double MULTIPLICA(double,double) = 3;
		double DIVIDE(double,double) = 4;
		int MODULO (int, int) = 5;
		int POTENCIA (int, int) =6;
		double RAIZ (double, double) = 7;
		int FACTORIAL (int) = 8;
		
		double LOGARITMO(int, int) = 9;
		double LOG_N (int) = 10;
		double LOG10 (int) = 11;
		
		double SENO (double) = 12;
		double COSENO (double) = 13;
		double TANGENTE (double) = 14;

		vector3D SUMAVECTORIAL(vector3D, vector3D) = 15;
		vector3D RESTAVECTORIAL(vector3D, vector3D) = 16;
		vector3D MULTPORESCALAR(vector3D, int) = 17;
		int PRODUCTOESCALAR(vector3D, vector3D) = 18;
		vector3D PRODUCTOVECTORIAL(vector3D, vector3D) = 19;

		matrix SUMAMATRICIAL(matrix, matrix) = 20;
        matrix RESTAMATRICIAL(matrix, matrix) = 21;
        matrix MULTMATRICIAL(matrix, matrix) = 22;
	}=1;
} = 0x20000155;