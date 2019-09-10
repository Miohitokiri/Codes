/************************************/
/* Date		: 2019-09-07 15:35:14	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	double a, b;
	char c;
	scanf ( "%lf %c %lf", &a, &c, &b );
	if ( c == '+' )
		printf ( "%.4lf + %.4lf = %.4lf\n", a, b, a + b );
	else if ( c == '-' )
		printf ( "%.4lf - %.4lf = %.4lf\n", a, b, a - b );
	else if ( c == '*' )
		printf ( "%.4lf * %.4lf = %.4lf\n", a, b, a * b );
	else{
		if ( b == 0 )
			puts ( "ERROR" );
		else
			printf ( "%.4lf / %.4lf = %.4lf\n", a, b, a / b );
	}
}