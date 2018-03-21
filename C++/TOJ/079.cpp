#include<bits/stdc++.h>
#define maxN 1000005

using namespace std;

vector < string > data;
bool used[maxN];

inline int dfs ( int Index ){
	if ( used[Index] )
		return 0;
	used[Index] = true;
	int l = 0 , r = data.size(), mid = ( l + r ) >> 1;
	char check = *( data[Index].end() - 1 );
	while ( data[mid][0] != check ){
		if ( data[mid][0] < check )
			r = mid;
		else
			l = mid;

		mid = ( l + r ) >> 1;
		if ( l == r && data[mid][0] != check )
			return -1;
	}
	int re = dfs ( mid );
	return re == -1 ? -1 : re + data[Index].size();
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, ma = 0;
	string stop;
	cin >> n;
	while ( n-- ){
		cin >> stop;
		data.push_back ( stop );
	}

	sort ( data.begin(), data.end() );

	for ( int i = 0 ; i < n ; i++ ){
		memset ( used, 0, sizeof used );

		ma = max ( ma, dfs ( i ) );
	}

	cout << ma << '\n';
}