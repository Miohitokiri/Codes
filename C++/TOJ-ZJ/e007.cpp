#include<iostream>
using namespace std;
struct slime{
	int hp;
	int dp;
	int ap;
}:
int main(){
	slime little,big,king,data,ans;
	little.hp = 100;
	little.dp = 10;
	little.ap = 10;
	big.hp = 500;
	big.dp = 100;
	big.ap = 100;
	king.hp = 1000;
	king.dp = 300;
	king.ap = 300;
	string a,as;
	int ex;
	cin >> a >> data.hp >> data.dp >> data.ap;
	if ( a == "Little_Slime" ){
		ans.hp = little.hp;
		ans.ap = little.ap;
		ans.dp = little.dp;
		ex = 10;
	}
	else if ( a == "Big_Slime" ){
                ans.hp = big.hp;
                ans.ap = big.ap;
                ans.dp = big.dp;
		ex = 30;
	}
	else if ( a == "Slime_King" ){
		ans.hp = king.hp;
		ans.ap = king.ap;
		ans.dp = king.dp;
		ex = 50;
	}
	if ( data.ap - ans.dp > ans.hp ){
		as = 1;
	}
	else if ( ans.ap - data.dp > data.hp ){
		as = 0;
	}
	else{
		as = 2;
	}
	if ( as == 1 ){
		cout << "Exp+" << ex << endl;
	}
	else if 
