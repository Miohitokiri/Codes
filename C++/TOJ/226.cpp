#include<bits/stdc++.h>

using namespace std;

#define int long long

inline bool check ( string a ){
	int sum = 0;
	for ( auto i: a )
		sum += i - '0';

	return sum % 3 == 0;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	bool zero, ans;
	string a;
	int n, data;
	cin >> n;
	while ( n-- ){
		cin >> a;
		ans = zero = false;
		for ( int i = 0 ; i < a.size() && !zero ; i++ )
			if ( a[i] == '0' )
				zero = true;

		if ( !zero )
			cout << -1;
		else{
			ans = check ( a ) && zero;
			if ( !ans )
				cout << -1;
			else{
				sort ( a.begin(), a.end() );
				reverse ( a.begin(), a.end() );

				cout << a;
			}
		}

		cout << '\n';
	}
}