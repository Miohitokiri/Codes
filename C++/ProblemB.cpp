#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int par[8000010],_rank[8000010],node_id[3000010];
int prev_node[8000010];
vector<int> roots;
int find(int x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
inline void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(_rank[x]<_rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(_rank[x]==_rank[y]) _rank[x]++;
	}
}
inline bool same(int x,int y){
	return find(x)==find(y);
}
int n;
ll A;
inline int F(ll x){
	return (x^A)%n+1;
}
#undef int
int main(){
	#define int ll
	int m;
	scanf("%lld%lld%lld",&n,&m,&A);
	for(int i=1;i<=n;i++){
		par[i]=i;
		node_id[i]=i;
		unite(1,i);
	}
	memset(prev_node,-1,sizeof prev_node);
	int node_idx=n;
	int o,Q;
	ll x,y;
	while(m--){
		scanf("%lld",&o);
		if(o==1){
			scanf("%lld",&Q);
			while(Q--){
				scanf("%lld",&x);
				x=F(x);
				int root=find(node_id[x]);
				node_id[x]=++node_idx;
				par[node_id[x]]=node_id[x];
				if(prev_node[root]==-1){
					roots.push_back(root);
					prev_node[root]=x;
				}
				else{
					unite(node_id[prev_node[root]],node_id[x]);
					prev_node[root]=x;
				}
			}
			for(int i=0;i<(int)roots.size();i++)
				prev_node[roots[i]]=-1;
			roots.clear();
		}else{
			scanf("%lld%lld",&x,&y);
			if(same(node_id[F(x)],node_id[F(y)])){
				A=(22695477ll*A+1)%(1ll<<32);
			}else{
				A=(69069ll*A+1)%(1ll<<32);
			}
		}
	}
	printf("%lld\n",A);

	return 0;
}