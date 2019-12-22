/************************************/
/* Date		: 2019-11-15 14:10:55	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

// data define here
int data1[] = { 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
int data2[] = { 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

void reverse1 ( int l, int r ){
	if ( l == r )
		return;
	int i, tmp;
	double sz = ( r - l ) / 2.0;
	for ( i = 0 ; i <= sz ; i++ ){
		tmp = data1[i + l];
		data1[i + l] = data1[r - i];
		data1[r - i] = tmp;
	}
}

void modify ( int i, int idx ){
	if ( i >= data1[0] )
		return;
	reverse1 ( i, ( i + ( 1 << idx ) ) - 1 );
	modify ( i + ( 1 << idx ), idx + 1 );
}

void solveA ( void ){
	int n = data1[0], i;
	modify ( 1, 0 );
	for ( i = 1 ; i <= n ; i++ )
		printf ( "%d ", data1[i] );
	puts ( "" );
}

void reverse2 ( int l, int r ){
	if ( l == r )
		return;
	int i, tmp;
	double sz = ( r - l ) / 2.0;
	for ( i = 0 ; i <= sz ; i++ ){
		tmp = data2[i + l];
		data2[i + l] = data2[r - i];
		data2[r - i] = tmp;
	}
}

void solveB ( void ){
	int n = data2[0], i = 1, idx = 0;
	while ( i < data2[0] ){
		reverse2 ( i, ( i + ( 1 << idx ) ) - 1 );
		i += 1 << idx;
		idx++;
	}

	for ( i = 1 ; i <= n ; i++ )
		printf ( "%d ", data2[i] );
	puts ( "" );
}

int main(){
	solveA();
	solveB();
}