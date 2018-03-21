#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	int n;
	char c;
	cin >> n;
	c = getchar();
	if ( c == ' ' )
		c = getchar();
	for ( int i = 0 ; i < n ; i++ ){
		long long stop;
		cin >> stop;
		cout << stop;
		if ( i != n - 1 )
			cout << c;
	}
	cout << endl;
}