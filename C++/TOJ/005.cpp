#include<stdio.h>

int main(){
	int cnt = 0;
	char c[25];
	printf ( "Hello ," );
	while ( c[cnt] = getchar() && c[cnt] != '\n' && cnt <= 20 ){
		cnt++;
	}
	// c[cnt++] = '!';
	// c[cnt] = '\0';
	// printf ( "%s!\n", c );
	for ( int i = 0 ; i < cnt ; i++ )
		putchar ( c[i] );
	puts ( "" );
}