// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

string str;
vector < int > lib;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int opt, len, x, a, b, ans;
	bool flag;
	while ( getline ( cin, str ) ){
		len = str.size(), x = 0, ans = 0;
		flag = false;
		lib.clear();
		for ( int i = 0 ; i < len ; i++ ){
			if ( str[i] == '+' )
				opt = 0;
			else if ( str[i] == '-' )
				opt = 1;
			else if ( str[i] == '*' )
				opt = 2;
			else if ( str[i] == '/' )
				opt = 3;
			else{
				if ( '0' <= str[i] && str[i] <= '9' ){
					x = x * 10 + int ( str[i] - '0' );
					flag = true;
				}
				else{
					if ( flag )
						lib.pb ( x );
					x = 0, flag = false;
				}
			}
		}
		if ( flag )
			lib.pb ( x );
		a = lib[0], b = lib[1];
		if ( !opt )
			ans = ( b - a ) * 10.0;
		else if ( opt == 1 )
			ans = ( b + a ) * 10.0;
		else if ( opt == 2 )
			ans = ( int ) ( ( double ) b / a * 10.0 );
		else{
			if ( str[0] == 'x' )
				ans = ( int ) ( ( double ) b * a * 10.0 );
			else
				ans = ( int ) ( ( double ) a / b * 10.0 );
		}
		cout << ans / 10 << '.' << ans % 10 << '\n';
	}
}