include <gset.h>
include <fset.h>

# APGSCUR -- Read the x and y coordinates of an object from a file and move
# the cursor to those coordinates.

long procedure apgscur (sl, gd, xcur, ycur, prev_num, req_num, num)

int	sl		# coordinate file descriptor
pointer	gd		# pointer to graphics stream
real	xcur, ycur	# x cur and y cur
long	prev_num	# previous number
long	req_num		# requested number
long	num		# list number

size_t	sz_val
int	stdin
pointer	sp, fname
long	nskip, ncount, l_val
int	fscan(), nscan(), strncmp()
errchk	greactivate, gdeactivate, gscur

begin
	if (sl == NULL)
	    return (EOF)

	call smark (sp)
	sz_val = SZ_FNAME
	call salloc (fname, sz_val, TY_CHAR)

	# Find the number of objects to be skipped.
	call fstats (sl, F_FILENAME, Memc[fname], SZ_FNAME)
	if (strncmp ("STDIN", Memc[fname], 5) == 0) {
	    stdin = YES
	    nskip = 1
	} else {
	    stdin = NO
	    if (req_num <= prev_num) {
		l_val = BOF
		call seek (sl, l_val)
		nskip = req_num
	    } else
		nskip = req_num - prev_num
	}

	# Initialize.
	ncount = 0
	num = prev_num

	# Read the coordinates and write the cursor.
	repeat {

	    # Print the prompt if file is STDIN.
	    if (stdin == YES) {
		call printf ("Type object x and y coordinates: ")
		call flush (STDOUT)
	    }

	    # Fetch the coordinates.
	    if (fscan (sl) != EOF) {
		call gargr (xcur)
		call gargr (ycur)
		if (nscan () == 2) {
		    ncount = ncount + 1
		    num = num + 1
		}
	    } else 
		ncount = EOF

	    # Move the cursor.
	    if (gd != NULL && (ncount == nskip || ncount == EOF)) {
		iferr {
		    call greactivate (gd, 0)
	            call gscur (gd, xcur, ycur)
		    call gdeactivate (gd, 0)
		} then
		    ;
	    }

	} until (ncount == EOF || ncount == nskip)

	call sfree (sp)

	if (ncount == EOF) {
	    return (EOF)
	} else if (nskip == req_num) {
	    num = ncount
	    return (ncount)
	} else {
	    return (num)
	}
end
