/* Copyright(c) 1986 Association of Universities for Research in Astronomy Inc.
 */

#define import_spp
#define import_knames
#include <iraf.h>

/* STRUPK -- Unpack a kernel (C style) string into an SPP string.  The unpacking
 * operation can be performed in place.  A kernel string consists of a sequence
 * of host characters stored one character per byte, delimited by EOS='\0'.
 * We assume here that the host character set is ASCII.  If this is not the
 * case code must be added to convert from the host character set to ASCII in
 * the unpacked string.
 *
 * N.B.: If sizeof(XCHAR)=1, XEOS=EOS, and the host character set is ASCII,
 * and the operation is being performed in place, then this procedure should
 * do nothing.
 */
int STRUPK ( PKCHAR *instr, XCHAR *outstr, XSIZE_T *maxch )
{
	char *ip = (char *)instr;
	XCHAR *op = outstr;
	XSIZE_T n;

	if ( *maxch < 0 ) goto quit;

	/* Is is necessary to determine the length of the string in order to
	 * be able to unpack the string in place, i.e., from right to left.
	 */
	for (n=0;  *ip++;  n++)
	    ;
	n = (n < *maxch) ? n : *maxch;
	op[n] = XEOS;

	for ( ip = (char *)instr ; 0 < n ; ) {
	    n--;
	    op[n] = ip[n];
	}
	op[*maxch] = XEOS;
 quit:
	return 0;
}
