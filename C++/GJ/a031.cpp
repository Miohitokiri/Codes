#include<iostream>
using namespace std;
int main(){
	long long a, b, ans = 0;
	cin >> a >> b;
	ans += a;
	ans += b;
	( a > b ) ? cout << "A " : cout << "B ";
	cout << ans << endl;
}