/************************************/
/* Date		: 2019-09-07 15:39:21	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	char a[100] = { 0 }, c[100] = { 0 };
	char swp;
	int b, d, idx = 0, i, flag = 1;
	scanf ( "%s %d %s %d", a, &b, c, &d );
	for ( i = 0 ; i < 100 ; i++ ){
		if ( a[i] != c[i] ){
			flag = 0;
			break;
		}
	}

	if ( flag == 1 && b == d )
		puts ( "GOOD" );
	else if ( flag == 1 || b == d )
		puts ( "=~=" );
	else
		puts ( "OTZ" );
}