#include<stdio.h>

int data[1005];

int main(){
	short n, a;
	int b;
	scanf ( "%hd", &n );
	while ( n-- ){
		scanf ( "%hd%d", &a, &b );
		data[a] = b * a;
	}
	scanf ( "%hd", &n );
	while ( n-- ){
		scanf ( "%hd%d", &a, &b );
		b -= data[a];
		if ( b )
			printf ( "%d\n", b );
		else
			puts ( "The shopkeeper is honest." );
	}
}