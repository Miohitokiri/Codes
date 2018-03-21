#include<iostream>
using namespace std;
int main(){
	long long n,m;
	while ( cin >> n ){
		long long a[n];
		for ( int j = 0 ; j < n ; j++ ){
			cin >> a[j];
			if ( j != 0 ){
				a[j] += a[j - 1];
			}
		}
		for ( int j = 0 ; j < n ; j++ ){
			long long s,b;
			cin >> s >> b;
			if ( s > b ){
				cout << a[s] - a[b - 1];
			}
			else{
				cout << a[b] - a[s - 1];
			}
			cout << endl;
		}
	}
	return 0;
}
