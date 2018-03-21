#include<iostream>
using namespace std;
int main(){
	long long f, s, ans = 0;
	cin >> f >> s;
	if ( f == s )
		ans += 50;
	if ( f % 2 == 1 )
		ans += 100;
	if ( s == 2 || s == 5 || s == 8 )
		ans += 200;
	cout << ans << endl;
}