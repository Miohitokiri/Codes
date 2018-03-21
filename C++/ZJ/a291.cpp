#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long dataOfA, dataOfB, n;
	int computer[4], user[4];
	for ( int i = 0 ; i < 4 ; i++ )
		cin >> computer[i];
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		dataOfA = 0;
		dataOfB = 0;
		for ( int i = 0 ; i < 4 ; i++ )
			cin >> user[i];
		for ( int i = 0 ; i < 4 ; i++ )//first deal with A
			( user[i] == computer[i] ) ? dataOfA++ : dataOfA;
		for ( int i = 0 ; i < 4 ; i++ )//next deal with B
			for ( int j = 0 ; j < 4 ; j++ )
				( user[i] == computer[j] ) ? dataOfB++ : dataOfB;
		dataOfB -= dataOfA;
		cout << dataOfA << "A" << dataOfB << "B\n";
	}
	return 0;
}