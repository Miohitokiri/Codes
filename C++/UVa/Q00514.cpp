#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop, cnt;
	bool ans;
	while ( cin >> n ){
		if ( !n )
			break;
		while ( cin >> stop ){
			if ( !stop )
				break;
			stack < int, vector < int > > basic, stationStop;
			ans = true;
			cnt = 0;
			basic.push ( stop );

			for ( int i = 1 ; i < n ; i++ ){
				cin >> stop;
				basic.push ( stop );
			}

			while ( ( n || ( !basic.empty() || !stationStop.empty() ) ) && ans ){
				if ( !stationStop.empty() ){
					if ( stationStop.top() == n ){
						stationStop.pop();
						n--;
						continue;
					}
				}
				if ( !basic.empty() ){
					if ( basic.top() == n ){
						basic.pop();
						cnt++;
						n--;
						continue;
					}
				}
				else if ( stationStop.empty() ){
					stationStop.push ( basic.top() );
					basic.pop();
				}
				else{
					if ( stationStop.top() == n ){
						stationStop.pop();
						n--;
						continue;
					}
					else{
						stationStop.push ( basic.top() );
						basic.pop();
					}
				}

				if ( stationStop.empty() && basic.empty() )
					ans = true;
				else if ( basic.empty() && stationStop.top() != n && n )
					ans = false;

				if ( !basic.empty() )
					cout << "b" << basic.top() << ' ';
				if ( !stationStop.empty() )
					cout << "s" << stationStop.top() << ' ';
				cout << n << ' ' << cnt << '\n';
				cout << basic.size() << ' ' << stationStop.size() << '\n';
			}

			cout << '\n';

			cout << ( ans ? "YES" : "NO" ) << '\n';
		}
	}
}