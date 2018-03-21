#include<iostream>

using namespace std;

#define int long long

int cnt = 0;

inline int f ( int n ){
	cnt++;
	if ( n == 0 )
		return 0;
	if ( n == 1 )
		return 1;

	return f ( n - 2 ) + f ( n - 1 );
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n;
	cin >> n;
	cout << f ( n ) << ' ';
	cout << cnt << '\n';
}