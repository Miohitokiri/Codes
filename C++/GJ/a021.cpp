#include<iostream>
using namespace std;
int main(){
	long long a;
	cin >> a;
	while ( a % 2 == 0 )
		a /= 2;
	cout << a << endl;
}