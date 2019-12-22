#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Nmax 30
int map[Nmax + 5][Nmax + 5], used[Nmax + 5][Nmax + 5], X, Y, i, j, res;
void dfs ( int x, int y ){
	int i, j;
	if ( *( *( used + x ) + y ) || *( *( map + x ) + y ) == -2 ) return;
	*( *( used + x ) + y ) = 1;
	if ( !*( *( map + x ) + y ) ) for ( i = -1 ; i < 2 ; i++ ) for ( j = -1 ; j < 2 ; j++ ) if ( i || j ) dfs ( x + i, y + j );
}
int check ( int n ){
	for ( i = 1 ; i < n ; i++ ) for ( j = 1 ; j < n ; j++ ) if ( !*( *( used + i ) + j ) && 0 <= *( *( map + i ) + j ) ) return 1;
	return 0;
}
int calc ( int x, int y ){
	for ( i = -1, res = 0 ; i < 2 ; i++ ) for ( j = -1 ; j < 2 ; j++ ) !~*( *( map + x + i ) + y + j ) && ( i || j ) ? res++ : res;
	return res;
}
void input ( void ){scanf ( "%d %d", &X, &Y );}
void output ( int n ){for ( i = 1 ; i < n ; i++, putchar ( '\n' ) ) for ( j = 1 ; j < n ; j++ ) printf ( "%c ", ( *( *( used + i ) + j ) ) ? ( !*( *( map + i ) + j ) ) ? '_' : '0' + *( *( map + i ) + j ) : '?' );}
int main ( int argc, char *argv[] ){
	srand ( clock() + time ( NULL ) );
	int n = atoi ( argv[1] ), m = atoi ( argv[2] ), i, j, N = n++, x = rand() % N + 1, y = rand() % N + 1;
	for ( i = 0 ; i <= n ; i++ ) for ( j = 0 ; j <= n ; j++ ) *( *( map + i ) + j ) = -2, *( *( used + i ) + j ) = 1;
	for ( i = 1 ; i < n ; i++ ) for ( j = 1 ; j < n ; j++ ) *( *( map + i ) + j ) = *( *( used + i ) + j ) = 0;
	while ( m-- && ( *( *( map + x ) + y ) = -1 ) ) while ( *( *( map + x ) + y ) == -1 ) x = rand() % N + 1, y = rand() % N + 1;
	for ( i = 1 ; i < n ; i++ ) for ( j = 1 ; j < n ; j++ ) *( *( map + i ) + j ) = ( *( *( map + i ) + j ) < 0 ? -1 : calc ( i, j ) );
	while ( check ( n ) ){
		system ( "clear" ), output ( n ), input();
		if ( !~*( *( map + X + 1 ) + Y + 1 ) ) return puts ( "you are dead" ), 0;
		if ( !*( *( map + X + 1 ) + Y + 1 ) ) dfs ( X + 1, Y + 1 );
		else if ( *( *( map + X + 1 ) + Y + 1 ) > 0 ) *( *( used + X + 1 ) + Y + 1 ) = 1;
	}
	system ( "clear" ), output ( n ), puts ( "you win" );
}