#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, stop, l, r, mid, lSum, rSum;
	vector < long long > data;

	while ( cin >> n ){
		if ( !data.empty() )
			data.clear();

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			data.push_back ( stop );
		}

		l = 0, r = n - 1, mid = ( l + r ) >> 1, ls = 0, rs = 1;
		while ( l == r || lSum == rSum ){
			lSum = 0, rSum = 0;
			for ( int i = 0 ; i < mid ; i++ )
				lSum += data[i] * ( mid - i );

			for ( int mid + 1 ; i < n ; i++ )
				rSum += data[i] * ( i - mid );

			if ( lSum > rSum )
				r = mid;
			else
				l = mid;

			mid = ( l + r ) >> 1;
		}

		cout << mid << '\n';
	}
}