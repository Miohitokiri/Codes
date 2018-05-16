#include<iostream>
#include<vector>

using namespace std;

#define maxN 1000000005

#define pb push_back

bitset < maxN > lib;
vector < int > prime, ans;

int main(){
	long long n;
	cin >> n;
	cout << n << " =";

	lib[0] = lib[1] = true;

	for ( int i = 0 ; i <= maxN ; i++ ){
		if ( lib[i] )
			continue;
		for ( int j = i << 1 ; j <= maxN ; j += i )
			lib[j] = true;
		prime.pb ( i );
	}

	for ( int i = 0 ; n ; i++ ){
		while ( n % prime[i] == 0 ){
			ans.pb ( prime[i] );
			n /= prime[i];
		}
	}

	cout << ans[0];
	for ( int i = 1 ; i < ans.size() ; i++ )
		cout << " * " << ans[i];
	cout << '\n';
}