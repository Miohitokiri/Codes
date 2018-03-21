#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
int main(){
	int n, l = 0;
	char stop;
	string data;
	stack < char > data1;
	queue < char > data2;
	scanf ( "%d", &n );
	cout << n << endl;// del
	for ( int i = 0 ; i < n ; i++ ){
		stop = getchar();
		cout << stop << endl;// del
		data1.push ( stop );
		data2.push ( stop );
	}
	for ( int i = 0 ; i< n ; i++ ){
		l++;
		if ( data1.top() > data2.front() ){
			stop = data1.top();
			data1.pop();
		}
		else if ( data1.top() > data2.front() ){
			stop = data2.front();
			data2.pop();
		}
		ans += stop;
		// printf ( "%c", &stop );
		if ( l == 80 ){
			l = 0;
			printf ( "\n" );
		}
	}
	printf ( "\n" );
}