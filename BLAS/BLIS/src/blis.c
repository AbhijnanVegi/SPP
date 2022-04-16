#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <blis/blis.h>

#include "utils.h"

// #define DEFAULT_VECTOR_LENGTH 100000000 // million
#define DEFAULT_VECTOR_LENGTH 4 // million
#define DEFAULT_ALPHA 1.0

int main( int argc, char** argv )
{
    srand(time(0));
    
    struct timeval t;
    double calctime;

	obj_t alpha, beta;
    obj_t a, b, c, d;
	num_t dt, dt2;
	dim_t m, n;
	inc_t rs, cs;

	dt = BLIS_FLOAT;
    dt2 = BLIS_DOUBLE;

    // dimensions
	m = 1; n = DEFAULT_VECTOR_LENGTH;

    // i have no idea honestly 
    rs = 0; cs = 0;

    // creating 1D vector objects
	bli_obj_create( dt, m, n, rs, cs, &a );
    bli_obj_create( dt, m, n, rs, cs, &c );

    bli_obj_create( dt2, m, n, rs, cs, &b );
    bli_obj_create( dt2, m, n, rs, cs, &d );

	// initialize alpha
	bli_obj_create_1x1( dt, &alpha );
    bli_obj_create_1x1( dt2, &beta );

	bli_setsc( DEFAULT_ALPHA, 0.0, &alpha );
    bli_setsc( DEFAULT_ALPHA, 0.0, &beta );

	// bli_printm( "alpha:", &alpha, "%4.1f", "" );

	// Set a to random values.
	bli_randv( &a );
    bli_randv( &b );
    bli_randv( &c );
    bli_randv( &d );

    // print vector before scaling

    printf("sSCAL\n");

    bli_printm( "a before scaling", &a, "%4f", "" );

    // Scale a vector (destructive).
    tick(&t);

	bli_scalv( &alpha, &a );

    calctime = tock(&t);

    printf("blis sscal time: %f\n", calctime);

	bli_printm( "a := alpha * a", &a, "%4f", "" );

    printf("dSCAL\n");

    bli_printm( "b before scaling", &b, "%4f", "" );
    // same thing for double

    tick(&t);

    bli_scalv( &beta, &b );

    calctime = tock(&t);

    printf("blis dscal time: %f\n", calctime);

    bli_printm( "b := beta * b", &b, "%4f", "" );

    printf("sAXPY\n");

    bli_printm( "c before scaling", &c, "%4f", "" );

    tick(&t);

    bli_axpyv( &alpha, &a, &c );

    calctime = tock(&t);

    printf("blis saxpy time: %f\n", calctime);

    bli_printm( "c := alpha * a + c", &c, "%4f", "" );

    printf("dAXPY\n");

    bli_printm( "d before scaling", &d, "%4f", "" );

    tick(&t);

    bli_axpyv( &beta, &d, &b );

    calctime = tock(&t);

    printf("blis daxpy time: %f\n", calctime);

    bli_printm( "b := beta * d + b", &b, "%4f", "" );


	// Free the objects.
	bli_obj_free( &alpha );
    bli_obj_free( &beta );
	bli_obj_free( &a );
    bli_obj_free( &b );
    bli_obj_free( &c );
    bli_obj_free( &d );

	return 0;
}
