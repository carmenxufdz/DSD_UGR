/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_m (XDR *xdrs, m *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->m_val, (u_int *) &objp->m_len, ~0,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_matrix (XDR *xdrs, matrix *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rows))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->cols))
		 return FALSE;
	 if (!xdr_m (xdrs, &objp->data))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_vector3D (XDR *xdrs, vector3D *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->x))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->y))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->z))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_suma_1_argument (XDR *xdrs, suma_1_argument *objp)
{
	 if (!xdr_double (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_resta_1_argument (XDR *xdrs, resta_1_argument *objp)
{
	 if (!xdr_double (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_multiplica_1_argument (XDR *xdrs, multiplica_1_argument *objp)
{
	 if (!xdr_double (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_divide_1_argument (XDR *xdrs, divide_1_argument *objp)
{
	 if (!xdr_double (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_modulo_1_argument (XDR *xdrs, modulo_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_potencia_1_argument (XDR *xdrs, potencia_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_raiz_1_argument (XDR *xdrs, raiz_1_argument *objp)
{
	 if (!xdr_double (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_logaritmo_1_argument (XDR *xdrs, logaritmo_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_sumavectorial_1_argument (XDR *xdrs, sumavectorial_1_argument *objp)
{
	 if (!xdr_vector3D (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_vector3D (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_restavectorial_1_argument (XDR *xdrs, restavectorial_1_argument *objp)
{
	 if (!xdr_vector3D (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_vector3D (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_multporescalar_1_argument (XDR *xdrs, multporescalar_1_argument *objp)
{
	 if (!xdr_vector3D (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_productoescalar_1_argument (XDR *xdrs, productoescalar_1_argument *objp)
{
	 if (!xdr_vector3D (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_vector3D (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_productovectorial_1_argument (XDR *xdrs, productovectorial_1_argument *objp)
{
	 if (!xdr_vector3D (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_vector3D (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_sumamatricial_1_argument (XDR *xdrs, sumamatricial_1_argument *objp)
{
	 if (!xdr_matrix (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_matrix (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_restamatricial_1_argument (XDR *xdrs, restamatricial_1_argument *objp)
{
	 if (!xdr_matrix (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_matrix (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_multmatricial_1_argument (XDR *xdrs, multmatricial_1_argument *objp)
{
	 if (!xdr_matrix (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_matrix (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}
