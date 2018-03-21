#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int data[n];
	while ( scanf ( "%d", &n ) ){
		if ( n == 0 )
			break;
		data[0] = 1;
		data[1] = 2;
		for ( int i = 2 ; i < n ; i++ )
			data[i] = data[i - 1] + data[i - 2];
		n--;
		printf ( "%d\n", data[n] );
	}
}