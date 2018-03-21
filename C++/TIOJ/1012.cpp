#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, stop, Index;
	while ( m-- ){
		stack < int > basic, stationStop;
		Index = n;

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			basic.push_back ( stop );
		}

		while ( true ){
			if ( !basic.empty() ){
				if ( basic.top() == Index ){
					Index--;
					basic.pop();
				}
			}

			if ( !stationStop.empty() ){
				if ( stationStop.top() == Index ){
					Index--;
					stationStop.pop();
				}
			}
		}
	}
}