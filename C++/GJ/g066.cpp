#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		string data1, data2;
		cin >> data1;
		for ( int i = data1.size() - 1 ; i >= 0 ; i-- )
			data2 += data1[i];
		( data1 == data2 ) ? cout << "yes\n" : cout << "no\n";
	}
}