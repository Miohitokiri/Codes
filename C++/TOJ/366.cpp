#include<bits/stdc++.h>
#define maxN 1000005

using namespace std;

vector < int > prime;
bool data[maxN] = { true, true, false };

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	for ( int i = 2 ; i < maxN ; i++ ){
		if ( data[i] )
			continue;
		for ( int j = 2 * i ; j < maxN ; j += i )
			data[j] = true;
		prime.push_back ( i );
	}

	int a, b;
	while ( cin >> a >> b ){
		if ( a > b )
			swap ( a, b );
	}
}