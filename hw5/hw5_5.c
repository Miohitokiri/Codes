/************************************/
/* Date		: 2019-11-15 17:27:53	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int N;
int cnt = 0;
int data[20];

int boolfunc ( int *var, int m );
void recursivebool ( int *var, int n, int k );
int combinations ( int *a, int n, int k );
void test ( void ){
	printf ( "%d\n", data[0] );
}

int main(){
	// data define here
	int in[20] = { 1, 2, 3, 4 };
	printf ( "%d\n", combinations ( in, 4, 2 ) );
}

int boolfunc ( int *var, int m ){
	int result = var[0], i;
	for ( i = 1 ; i < m ; i++ )
		result += var[i];
	return result;
}

void recursivebool ( int *var, int n, int k ){
	int i, j, flag;
	int check[20], idx = 0;
	if ( n == 0 ){
		if ( boolfunc ( var, N ) == k ){
			for ( i = 0 ; i < N ; i++ ){
				if ( var[i] == 1 )
					check[idx++] = data[i];
			}
			flag = 1;
			for ( i = 1 ; flag && i < idx ; i++ ){
				if ( check[i] <= check[i - 1] )
					flag = 0;
			}

			if ( flag ){
				printf ( "(%d", check[0] );
				for ( i = 1 ; i < idx ; i++ )
					printf ( ", %d", check[i] );
				puts ( ")" );
				cnt++;
			}
		}
		return;
	}

	for ( j = 0 ; j <= 1 ; j++ ){
		var[n - 1] = j;
		recursivebool ( var, n - 1, k );
	}
}

int combinations ( int *A, int n, int k ){
	int i, j;
	int var[20] = { 0 };
	for ( i = 0 ; i < n ; i++ )
		data[i] = A[i];
	N = n;
	recursivebool ( var, n, k );
	return cnt;
}