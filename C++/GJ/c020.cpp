#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	if ( n < 20 )
		cout << 60;
	else if ( n < 50 )
		cout << 80;
	else if ( n < 100 )
		cout << 90;
	else
		cout << 100;
	cout << endl;
}