# Copyright(c) 1986 Association of Universities for Research in Astronomy Inc.

include <math/gsurfit.h>

include "dgsurfitdef.h"

# GSSOLVE -- Solve the matrix normal equations of the form ca = b for a,
# where c is a symmetric, positive semi-definite, banded matrix with
# GS_NXCOEFF(sf) * GS_NYCOEFF(sf) rows and a and b are GS_NXCOEFF(sf) *
# GS_NYCOEFF(sf)-vectors.
# Initially c is stored in the matrix MATRIX
# and b is stored in VECTOR.
# The Cholesky factorization of MATRIX is calculated and stored in CHOFAC.
# Finally the coefficients are calculated by forward and back substitution
# and stored in COEFF.

procedure dgssolve (sf, ier)

pointer	sf 		# curve descriptor
int	ier		# ier = OK, everything OK
			# ier = SINGULAR, matrix is singular, 1 or more
			# coefficients are 0.
			# ier = NO_DEG_FREEDOM, too few points to solve matrix

int	nfree

begin
	# test for number of degrees of freedom
	ier = OK
	nfree = GS_NPTS(sf) - GS_NCOEFF(sf)
	if (nfree < 0) {
	    ier = NO_DEG_FREEDOM
	    return
	}

	switch (GS_TYPE(sf)) {
	case GS_LEGENDRE, GS_CHEBYSHEV, GS_POLYNOMIAL:

	    # calculate the Cholesky factorization of the data matrix
	    call dgschofac (MATRIX(GS_MATRIX(sf)), GS_NCOEFF(sf),
	        GS_NCOEFF(sf), CHOFAC(GS_CHOFAC(sf)), ier)

	    # solve for the coefficients by forward and back substitution
	    call dgschoslv (CHOFAC(GS_CHOFAC(sf)), GS_NCOEFF(sf),
	        GS_NCOEFF(sf), VECTOR(GS_VECTOR(sf)), COEFF(GS_COEFF(sf)))
	default:
	    call error (0, "GSSOLVE: Illegal surface type.")
	}
end