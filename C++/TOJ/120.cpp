#include<iostream>
using namespace std;
long long a,b,d,n,q;
long long s[200000];
int main(){
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> d;
		if ( i == 0 )
			s[i] = d;
		else if ( i != 0 ){
			s[i] = s[i - 1];
			s[i] += d;
		}
	}
	cin >> q;
	for ( int j = 0 ; j < q ; j++ ){
		cin >> a >> b;
		cout << ( ( a >= b ) ? s[b - 1] - s[a - 2] : s[a - 1] - s[b - 2] ) << '\n';
	}
}