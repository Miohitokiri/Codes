#include<bits/stdc++.h>
#define maxN 7500

using namespace std;

int data[7500];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	data[0] = 1;
	int coin[5] = { 1, 5, 10, 25, 50 };
	for ( auto i: coin ){
		for ( int j = i ; j < maxN ; j++ ){
			data[j] += data[j - i];
		}
	}

	int n;
	while ( cin >> n )
		cout << data[n] << '\n';
}