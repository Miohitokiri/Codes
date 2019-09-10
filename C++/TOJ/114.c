/************************************/
/* Date		: 2019-09-07 16:34:28	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

/* by. MiohitoKiri5474 */
#include<stdio.h>

int main(){
	int data[10][10] = { 0 };
	int i, j, flag = 0;
	for ( i = 0 ; i < 5 ; i++ )
		for ( j = 0 ; j < 6 ; j++ )
			scanf ( "%d", &data[i][j] );

	for ( i = 0 ; i < 5 ; i++ )
		for ( j = 0 ; j < 6 ; j++ )
			if ( data[i][j] == data[i][j + 1] && data[i][j + 1] == data[i][j + 2] )
				flag = 1;


	for ( j = 0 ; j < 6 ; j++ )
		for ( i = 0 ; i < 5 ; i++ )
			if ( data[i][j] == data[i + 1][j] && data[i + 1][j] == data[i + 2][j] )
				flag = 1;

	if ( flag == 1 )
		puts ( "Yes" );
	else
		puts ( "No" );
}