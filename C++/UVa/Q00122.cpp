#include<bits/stdc++.h>
using namespace std;

struct node{
	node *left, *right;
	int velue;
	node ( int v ) left = nullptr, right = nullptr, velue = v {}
};

inline node *insert ( node *o, int k, string str );
inline int find ( node *o, int k );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
}
