#include<iostream>
#include<cmath>
#include<algorithm>
#define t true
#define f false
using namespace std;
int main(){
	long long n,q;
	cin >> n >> q;
	bool test;
	long long dn[n];
	for ( int i = 0 ; i < n ; i++ )
		cin >> dn[i];
	sort ( dn,dn + n );
	for ( int da = 0 ; da < q ; da++ ){
		long long k;
		test = f;
		cin >> k;
		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = i ; j < n ; j++ ){
				if ( dn[j] - dn[i] == k ){
					cout << "YES" << endl;
					test = t;
					break;
				}
			}
			if ( test == t )
				break;
		}
		if ( test == f )
			cout << "NO" << endl;
	}
	return 0;
}