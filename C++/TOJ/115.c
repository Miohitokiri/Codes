/************************************/
/* Date		: 2019-09-07 16:44:03	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	int n, idx, i, j;
	char data[15][1000], str[1000];
	for ( i = 1 ; i <= 10 ; i++ ){
		data[i][0] = 'E';
		data[i][1] = 'M';
		data[i][2] = 'P';
		data[i][3] = 'T';
		data[i][4] = 'Y';
	}
	scanf ( "%d", &n );
	while ( n-- ){
		scanf ( "%s %d", str, &idx );
		for ( j = 0 ; j < 100 ; j++ )
			data[idx][j] = str[j];
	}
	for ( i = 1 ; i <= 10 ; i++ ){
		printf ( "%s\n", data[i] );
	}
}