/************************************/
/* Date		: 2019-09-07 16:21:06	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	int n, idx = 0, i;
	char c;
	scanf ( "%d", &n );
	getchar();
	for ( i = 0 ; i < n ; i++ ){
		c = getchar();
		if ( c == 'P' )
			idx = i;
	}
	c = getchar();
	scanf ( "%c", &c );
	if ( c == 'L' )
		idx--;
	else
		idx++;
	for ( i = 0 ; i < n ; i++ ){
		if ( i == idx )
			putchar ( 'P' );
		else
			putchar ( '.' );
	}
	puts ( "" );
}