#include<cstdio>
#include<map>
using std::map;
int main(){
	int b;
	short a, n;
	map < short, int > data;
	scanf ( "%hd", &n );
	while ( n-- ){
		scanf ( "%hd%d", &a, &b );
		data[a] = a * b;
	}
	scanf ( "%hd", &n );
	while ( n-- ){
		scanf ( "%hd%d", &a, &b );
		if ( data[a] == b )
			printf ("The shopkeeper is honest.\n" );
		else
			printf ( "%d\n", b - data[a] );
	}
}