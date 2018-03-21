#include<iostream>
#include<string>
using namespace std;
int main(){
	string data1, data2;
	cin >> data1;
	for ( int i = data1.size() - 1 ; i >= 0 ; i-- )
		data2 += data1[i];
	( data1 == data2 ) ? cout << "YES\n" : cout << "NO\n";
}