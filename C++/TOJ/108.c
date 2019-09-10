/************************************/
/* Date		: 2019-09-07 15:58:08	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	int a, b, c, u, v;
	scanf ( "%d %d %d", &a, &b, &c );
	while ( b-- ){
		scanf ( "%d %d", &u, &v );
		a += u * v;
	}
	a -= c;
	a /= 4;
	printf ( "%d\n", a );
}