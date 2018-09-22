#include<bits/stdc++.h>
#define endl '\n'
#define Maxn 1000000
#define x first
#define y second
using namespace std;
typedef pair<int,int> Dot;
vector< vector<int> > dot_dep,table;
long long BIT[Maxn+5];
long long sum(int id){
	long long ans=0;
	while(id>0){
		ans+=BIT[id];
		id-=id&-id;
	}
	return ans;
}
void add(int id,long long num){
	while(id<=Maxn){
		BIT[id]+=num;
		id+=id&-id;
	}
}
void op1(int si,int sj){
	long long ii,ij,k;
	cin>>ii>>ij>>k;
	if(si==ii && sj==ij)return ;
	if(table[ii][ij]==-1 || dot_dep[ii][ij]==0)return ;
	long long change = k-table[ii][ij];
	table[ii][ij] = k;
	add(dot_dep[ii][ij],change);
}
void op2(int maxdep){
	long long w;
	cin>>w;
	int l=1,r=maxdep+1,ans=0;
	while(r-l>=1){
		int mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<" "<<sum(mid)<<endl;
		if(sum(mid)<=w){
			ans = max(ans,mid);
			l = mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans<<endl;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q,inv,si,sj;
	cin>>n>>m>>q>>si>>sj;
	table.push_back(vector<int>());
	dot_dep.push_back(vector<int>());
	for(int i=1;i<=n;i++){
		table.push_back(vector<int>());
		dot_dep.push_back(vector<int>());
		dot_dep[i].push_back(0);
		table[i].push_back(0);
		for(int j=1;j<=m;j++){
			cin>>inv;
			table[i].push_back(inv);
			dot_dep[i].push_back(0);
		}
	}
	queue< pair<Dot,int> > qu;
	qu.push(make_pair(Dot(si,sj),0));
	int maxdep=0;
	while(!qu.empty()){
		pair<Dot,int> tmp;
		tmp = qu.front();
		qu.pop();
		int ti=tmp.x.x,tj=tmp.x.y;
		//cout<<ti<<" "<<tj<<endl;
		if(dot_dep[ti][tj]!=0 || table[ti][tj]==-1)continue;
		dot_dep[ti][tj] = tmp.y;
		if(ti==si && tj==sj)dot_dep[si][sj] = 1e9;
		maxdep = max(maxdep,tmp.y);
		if(ti!=si || tj!=sj)add(tmp.y,table[ti][tj]);
		if(ti-1>0)qu.push(make_pair(Dot(ti-1,tj),tmp.y+1));
		if(ti+1<=n)qu.push(make_pair(Dot(ti+1,tj),tmp.y+1));
		if(tj-1>0)qu.push(make_pair(Dot(ti,tj-1),tmp.y+1));
		if(tj+1<=m)qu.push(make_pair(Dot(ti,tj+1),tmp.y+1));
	}
	//return 0;
	//cout<<"md:"<<maxdep<<endl;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			op1(si,sj);
		}
		else{
			op2(maxdep);
		}
	}
	return 0;
}

