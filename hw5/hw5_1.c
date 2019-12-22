/************************************/
/* Date		: 2019-11-14 22:03:36	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int f1 ( int n ){
	if ( !n )
		return 0;
	if ( n == 2 || n == 1 )
		return 1;
	return f1 ( n - 1 ) + f1 ( n - 2 );
}

int f2 ( int n ){
	int i, a = 0, b = 1, c;
	a = 0, b = 1;
	for ( i = 2 ; i <= n ; i++ )
		c = a + b, a = b, b = c;
	return b;
}

int dp[100005];
int f3 ( int n ){
	if ( n == 0 )
		return 0;
	if ( n == 1 || n == 2 )
		return 1;
	if ( dp[n] != 0 )
		return dp[n];
	return dp[n] = f3 ( n - 1 ) + f3 ( n - 2 );
}

int main(){
	// data define here
	int n = 30;

	printf ( "%d\n", f1 ( n ) );
	printf ( "%d\n", f2 ( n ) );
	printf ( "%d\n", f3 ( n ) );
}