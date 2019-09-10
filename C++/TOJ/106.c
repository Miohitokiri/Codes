/************************************/
/* Date		: 2019-09-07 16:40:03	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	int n = 1;
	while ( n % 71 != 0 ){
		n++;
		n <<= 1;
		n %= 71;
	}

	if ( n % 3 == 0 )
		puts ( "right" );
	else
		puts ( "left" );
}