#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair < int, int > pii;

vector < pii > data;
vector < int > dp;

bool cmp ( pii a, pii b ){
	return a.y > b.y;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, k, ans, in;
	int *l, *r;
	while ( cin >> n >> k ){
		data.clear();
		ans = 0;
		dp.clear();
		for ( int i = k + 1 ; i <= n + k ; i++ )
			dp.push_back ( i );

		for ( int i = 1 ; i <= n ; i++ ){
			cin >> in;
			data.push_back ( make_pair ( i, in ) );
		}

		sort ( data.begin(), data.end(), cmp );

		for ( int j = 0 ; j < n ; j++ ){
			l = lower_bound ( dp.begin(), dp.end(), data[j].x, cmp );
			u = upper_bound ( dp.begin(), dp.end(), data[j].x, cmp );

			if ( *l == *u ){
				dp.erase ( l );
				ans += data[j].y * ( *l );
				data[j].y = data[j].x;
			}
			else if ( *u - data[j].x > data[j].y - *l ){
				dp.erase ( l );
				ans += *l * data[j].y;
				data[j].y = data[j].x - *l;
			}
			else{
				dp.erase ( u );
				ans == *u * data[j].y;
				data[j].y = data[j].x + *u;
			}
		}

		sort ( data.begin(), data.end() );

		cout << ans << '\n' << data[0].y;
		for ( int i = 1 ; i < n ; i++ )
			cout << ' ' << data[i].y;
		cout << '\n';
	}
}