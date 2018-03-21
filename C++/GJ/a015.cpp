#include<iostream>
using namespace std;
int main(){
	long long a, b;
	cin >> a >> b;
	cout << a;
	if ( a > b )
		cout << ">";
	else if ( a < b )
		cout << "<";
	else
		cout << "=";
	cout << b << endl;
}