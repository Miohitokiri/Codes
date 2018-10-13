#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>

#define pb push_back

using namespace std;

#define maxN 1000000005

bitset < maxN > lib;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n;
	cin >> n;
	cout << n << " = ";
	for ( int i = 2 ; i <= sqrt ( n ) + 1 ; i++ ){
		if ( !lib[i] ){
			for ( int j = i * 2 ; j <= sqrt ( n ) + 1 ; j += i )
				lib[j] = true;
			while ( n % i == 0 ){
				cout << i << " * ";
				n /= i;
			}
		}
	}
	cout << n << '\n';
}