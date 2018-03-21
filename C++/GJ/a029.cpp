#include<iostream>
using namespace std;
int main(){
	long long a, b, ans = 0;
	cin >> a >> b;
	ans += a;
	cout << a;
	a++;
	for ( int i = a ; i <= b ; i++ ){
		ans += i;
		cout << "+" << i;
	}
	cout << "=" << ans << endl;
}