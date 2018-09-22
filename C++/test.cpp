// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int j, l, r;
	string str, p = "";
	cin >> str;
	while ( p != str ){
		p = str;
		for ( int i = 0 ; i < SZ ( str ) ; i++ ){
			for ( j = i ; j < SZ ( str ) ; j++ ){
				if ( str[i] != str[j] )
					break;
			}
			j--;
			if ( i < j ){
				l = i, r = j;
				break;
			}
		}
		str.erase ( str.begin() + l, str.end() + r );
	}

	cout << ( str.empty() ? "Yes" : "No" ) << '\n';
}