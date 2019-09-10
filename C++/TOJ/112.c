/************************************/
/* Date		: 2019-09-07 16:02:28	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	int n, i;
	scanf ( "%d", &n );
	int data[n];
	for ( i = 0 ; i < n ; i++ )
		scanf ( "%d", data + i );
	for ( i = n - 1 ; i >= 0 ; i-- )
		printf ( "%d\n", data[i] );
}