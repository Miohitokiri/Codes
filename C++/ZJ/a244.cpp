#include<iostream>
using namespace std;
int main(){
	int a;
	long long n,b,c;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> a >> b >> c;
		if ( a == 1 ){
			cout << b + c;
		}
		else if ( a == 2 ){
			cout << b - c;
		}
		else if ( a == 3 ){
			cout << b *c;
		}
		else if ( a == 4 ){
			cout << b / c;
		}
		cout << endl;
	}
	return 0;
}
