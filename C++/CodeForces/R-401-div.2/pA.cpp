#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, x;
	int yee[6][3] = { { 0, 1, 2 }, { 1, 0, 2 }, { 1, 2, 0 }, { 2, 1, 0 }, { 2, 0, 1 }, { 0, 2, 1 } };
	cin >> n >> x;
	n %= 6;
	cout << yee[n][x] << '\n';
}