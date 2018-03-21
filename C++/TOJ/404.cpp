#include<stdio.h>

int main(){
	int ma = -1, mi = 10000, n, stop;
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; i++ ){
		scanf ( "%d", &stop );
		if ( ma < stop )
			ma = stop;
		if ( mi > stop )
			mi = stop;
	}

	printf ( "%d %d %s\n", mi, ma, ( ma - mi + 1 == n ? "yes" : "no" ) );
}