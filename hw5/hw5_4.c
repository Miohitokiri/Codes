/************************************/
/* Date		: 2019--15 03:07:35	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void solve1 ( char data[] ){
	int i, j, n = strlen ( data ), idx, num = 0;
	int ans[8];
	char str[5];
	for ( i = 0 ; i < n ; i++ ){
		if ( data[i] == '.' ){
			str[idx] = '\0';
			num = atoi ( str );
			for ( j = 0 ; j < 4 ; j++ )
				str[i] = 0;
			idx = 7;
			for ( j = 0 ; j < 9 ; j++ )
				ans[j] = '0';
			while ( num ){
				ans[idx--] = '0' + ( num & 1 );
				num >>= 1;
			}
			idx = 0;

			for ( j = 0 ; j < 8 ; j++ )
				printf ( "%c", ans[j] );
		}
		else
			str[idx++] = data[i];
	}
	str[idx] = '\0';
	num = atoi ( str );
	for ( j = 0 ; j < 4 ; j++ )
		str[i] = 0;
	for ( j = 0 ; j < 9 ; j++ )
		ans[j] = '0';
	idx = 7;
	while ( num ){
		ans[idx--] = '0' + ( num & 1 );
		num >>= 1;
	}
	idx = 0;

	for ( j = 0 ; j < 8 ; j++ )
		printf ( "%c", ans[j] );

	puts ( "" );
}

void solve2 ( char data[] ){
	int i, num = 0, n = strlen ( data );
	for ( i = 0 ; i < 8 ; i++ ){
		num <<= 1;
		num += ( data[i] - '0' );
	}
	printf ( "%d", num );
	num = 0;
	for ( i = 8 ; i < n ; i++ ){
		num <<= 1;
		num += ( data[i] - '0' );
		if ( i % 8 == 7 ){
			printf ( ".%d", num );
			num = 0;
		}
	}
	puts ( "" );
}

int main(){
	// data define here
	char input1[] = "129.160.96.1", input2[] = "10000001101000000110000000000001";
	solve1 ( input1 );
	solve2 ( input2 );
}