#include<iostream>
using namespace std;
int main(){
	long long a,b;
	cin >> a >> b;
	if ( a < b ){
		b /= 2;
		if ( a % 2 == 0 ){
			a /= 2;
			cout << b - a + 1;
		}
		else{
			a -= 1;
			a /= 2;
			cout << b - a;
		}
	}
	else{
		a /= 2;
		if ( b % 2 == 0 ){
			b /= 2;
			cout << a - b + 1;
		}
		else{
			b -= 1;
			b /= 2;
			cout << a - b;
		}
	}
	cout << endl;
	return 0;
}
