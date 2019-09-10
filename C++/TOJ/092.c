#include<stdio.h>

int main(){
	char str[100];
	char swp;
	int idx = 0;
	while ( 1 ){
		swp = getchar();
		if ( swp == '\n' )
			break;
		str[idx++] = swp;
	}
	printf ( "Hello, " );
	int i = 0, j = 0;
	for ( j = 0 ; i < idx ; i++ ){
		if ( str[i] == ' ' )
			break;
		putchar ( str[i] );
	}
	i++;
	printf ( ", " );
	for ( j = 0 ; j < idx ; i++ ){
		if ( str[i] == ' ' )
			break;
		putchar ( str[i] );
	}
	printf ( ", and " );
	i++;
	for ( j = 0 ; i < idx ; i++ ){
		if ( str[i] == '\n' )
			break;
		putchar ( str[i] );
	}
	puts ( "!" );
}