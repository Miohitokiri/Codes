#include<iostream>
using namespace std;
int main(){
	long long a, b, ans;
	char c;
	cin >> a >> c >> b;
	if ( c == '+' )
		ans = a + b;
	else if ( c == '-' )
		ans = a - b;
	else if ( c == '*' )
		ans = a * b;
	cout << ans << endl;
}