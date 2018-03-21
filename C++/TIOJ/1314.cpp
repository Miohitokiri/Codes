#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf ( "%d", &n );
	int data[3];
	for ( int times = 0 ; times < n ; times++ ){
		for ( int i = 0 ; i < 3 ; i++ )
			scanf ( "%d", &data[i] );
		sort ( data, data + 3 );
		if ( data[0] * data[0] + data[1] * data[1] == data[2] * data[2] )
			printf ( "yes\n" );
		else
			printf ( "no\n" );
	}
}