#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, a, ans1, ans0, x;
	cin >> n >> a;
	x = ans1 = a;
	ans0 = -a;
	n--;
	while ( n-- ){
		cin >> a;
		ans1 = max ( ans1, ans0 + a );
		x = ans1 = max ( ans1, a );
		ans0 = max ( x - a, ans0 );
	}

	cout << max ( ans0, ans1 ) << '\n';
}