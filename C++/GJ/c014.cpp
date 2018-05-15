#include<iostream>

using namespace std;

int main(){
	int a, b, ans = 0, len;
	cin >> a >> b;
	if ( a > b )
		swap ( a, b );
	len = b - a;
	len -= 20;
	if ( len > 0 ){
		ans += min ( 180, len ) * 4;
		len -= 180;
	}
	if ( len > 0 )
		ans += min ( 200, len ) * 3;
	cout << ans << '\n';
}