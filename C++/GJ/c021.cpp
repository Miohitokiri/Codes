#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, c, ma = 0x3f, sum;
	char ans;

	cin >> a >> b >> c;

	sum = a * 1 + b * 3 + c * 5;
	if ( ma > sum )
		ma = sum, ans = 'A';
	sum = a * 3 + b * 2 + c * 4;
	if ( ma > sum )
		ma = sum, ans = 'B';
	sum = ( a + b + c ) * 3;
	if ( ma > sum )
		ma = sum, ans = 'C';

	cout << ans << ' ' << ma << '\n';
}