#include<iostream>
using namespace std;
int main(){
	long long a, b, c;
	while ( cin >> a >> b >> c ){
		//cout << b << '\n';
		( a >= 10 && c >= 2 ) ? b += a / 10 : b;
		cout << a << " 個餅乾，" << b << " 盒巧克力，" << c << " 個蛋糕。\n";
	}
	return 0;
}