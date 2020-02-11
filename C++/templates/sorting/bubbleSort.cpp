// bubble sort
#include<bits/stdc++.h>

using namespace std;

int data[10];

void bubbleSort ( int len ){
	for ( int i = 0 ; i < len ; i++ )
		for ( int j = 1 ; j < len ; j++ )
			if ( data[j - 1] > data[j] )
				swap ( data[j - 1], data[j] );
}

int main(){
	int n = 8;
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i];
	bubbleSort ( n );
	for ( int i = 0 ; i < n ; i++ )
		cout << data[i] << ' ';
	cout << '\n';
}