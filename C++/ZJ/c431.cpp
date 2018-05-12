#include<stdio.h>

using namespace std;

int data[105];

int main(){
	int n, in;
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; i++ ){
		scanf ( "%d", &in );
		data[in]++;
	}

	for ( int i = 1 ; i <= 100 ; i++ )
		for ( int j = 0 ; j < data[i] ; j++ )
			printf ( "%d ", i );
	puts ( "" );
}