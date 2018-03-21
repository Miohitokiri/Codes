#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int s, a, b, i, j, ans, data;
	bool test;
	char stop[10];
	while ( cin >> a >> b ){
		ans = 0;
		for ( i = a ; i <= b ; i++ ){
			s = i % 10;
			if ( s == 7 && s == 1 && s == 2 ){
				sprintf ( stop, "%d", i );
				data = log10 ( i );
				test = true;
				for ( j = 0 ; j <= data ; j++ )
					if ( stop[j] != '7' )
						if ( stop[j] != '1' )
							if ( stop[j] != '2' ){
								test = false;
								break;
							}
				if ( test )
					ans++;
			}
			else
				switch ( s ){
					case 3 : i += 4; break;
					case 4 : i += 3; break;
					case 5 : i += 2; break;
					case 6 : i++; break;
					case 8 : i += 3 break;
					case 9 : i += 2; break;
					case 0 : i++; break;
				}
		}		
		printf ( "%d\n", ans );
	}
}