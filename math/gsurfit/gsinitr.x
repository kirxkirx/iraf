# Copyright(c) 1986 Association of Universities for Research in Astronomy Inc.

include <math/gsurfit.h>
include "gsurfitdef.h"

# GSINIT --  Procedure to initialize the surface descriptor.

procedure gsinit (sf, surface_type, xorder, yorder, xterms, xmin, xmax,
    ymin, ymax)

pointer	sf		# surface descriptor
int	surface_type	# type of surface to be fitted
int	xorder		# x order of surface to be fit
int	yorder		# y order of surface to be fit
int	xterms		# presence of cross terms
real   xmin		# minimum value of x
real	xmax		# maximum value of x
real	ymin		# minimum value of y
real	ymax		# maximum value of y

errchk	malloc, calloc

begin
	# allocate space for the gsurve descriptor
	call malloc (sf, LEN_GSSTRUCT, TY_STRUCT)

	if (xorder < 1 || yorder < 1)
	    call error (0, "GSINIT: Illegal order.")

	if (xmax <= xmin)
	    call error (0, "GSINIT: xmax <= xmin.")
	if (ymax <= ymin)
	    call error (0, "GSINIT: ymax <= ymin.")

	# specify the surface-type dependent parameters
	switch (surface_type) {
	case GS_CHEBYSHEV, GS_LEGENDRE:
	    GS_XORDER(sf) = xorder
	    GS_YORDER(sf) = yorder
	    GS_NXCOEFF(sf) = xorder
	    GS_NYCOEFF(sf) = yorder
	    GS_XTERMS(sf) = xterms
	    if (GS_XTERMS(sf) == YES)
		GS_NCOEFF(sf) = GS_NXCOEFF(sf) * GS_NYCOEFF(sf)
	    else
		GS_NCOEFF(sf) = GS_NXCOEFF(sf) + GS_NYCOEFF(sf) - 1
	    GS_XRANGE(sf) = 2. / (xmax - xmin)
	    GS_XMAXMIN(sf) = - (xmax + xmin) / 2.
	    GS_YRANGE(sf) = 2. / (ymax - ymin)
	    GS_YMAXMIN(sf) = - (ymax + ymin) / 2.
	case GS_POLYNOMIAL:
	    GS_XORDER(sf) = xorder
	    GS_YORDER(sf) = yorder
	    GS_NXCOEFF(sf) = xorder
	    GS_NYCOEFF(sf) = yorder
	    GS_XTERMS(sf) = xterms
	    if (GS_XTERMS(sf) == YES)
		GS_NCOEFF(sf) = GS_NXCOEFF(sf) * GS_NYCOEFF(sf)
	    else
		GS_NCOEFF(sf) = GS_NXCOEFF(sf) + GS_NYCOEFF(sf) - 1
	    GS_XRANGE(sf) = 1.0 
	    GS_XMAXMIN(sf) = 0.0
	    GS_YRANGE(sf) = 1.0
	    GS_YMAXMIN(sf) = 0.0
	default:
	    call error (0, "GSINIT: Unknown surface type.")
	}

	# set remaining parameters
	GS_TYPE(sf) = surface_type
	GS_XMIN(sf) = xmin
	GS_XMAX(sf) = xmax
	GS_YMAX(sf) = ymax
	GS_YMIN(sf) = ymin

	# allocate space for the matrix and vectors
	switch (surface_type ) {
	case GS_LEGENDRE, GS_CHEBYSHEV, GS_POLYNOMIAL:
	    call calloc (GS_MATRIX(sf), GS_NCOEFF(sf) ** 2, TY_REAL)
	    call calloc (GS_CHOFAC(sf), GS_NCOEFF(sf) ** 2, TY_REAL)
	    call calloc (GS_VECTOR(sf), GS_NCOEFF(sf), TY_REAL)
	    call calloc (GS_COEFF(sf), GS_NCOEFF(sf), TY_REAL)
	default:
	    call error (0, "GSINIT: Unknown surface type.")
	}

	# initialize pointer to basis functions to null
	GS_XBASIS(sf) = NULL
	GS_YBASIS(sf) = NULL
	GS_WZ(sf) = NULL

	# set data points counter
	GS_NPTS(sf) = 0
end