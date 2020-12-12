#include<bits/stdc++.h>

#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using ld = long double;

const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
int qpow(int x,int powcnt,int tomod){
	int res = 1;
	for(;powcnt;powcnt>>=1,x=(x*x)%tomod)
		if(1&powcnt)res = (res*x)%tomod;
	return (res%tomod);
}
// --------------------------------------**
const int N = 1e5+10;

int n,q;
int val[N];

struct segment_tree{
	int seg[N<<2],tag[N<<2],sum[N<<2];
	void build(int l,int r,int idx){
		if(l==r){
			sum[idx] = val[l];
			return;
		}
		int mid = (l+r)>>1;
		build(l,mid,idx<<1);
		build(mid+1,r,idx<<1|1);
		sum[idx] = sum[idx<<1]+sum[idx<<1|1];
	}
	inline void down(int idx){
		if(!tag[idx])
			return;
		seg[idx<<1] += sum[idx<<1]*tag[idx];
		seg[idx<<1|1] += sum[idx<<1|1]*tag[idx];
		tag[idx<<1] += tag[idx];
		tag[idx<<1|1] += tag[idx];
		tag[idx] = 0;
	}
	void modify(int l,int r,int ql,int qr,int idx){
		if(ql==l&&qr==r){
			tag[idx]++;
			seg[idx] += sum[idx];
			return;
		}
		int mid = (l+r)>>1;
		down(idx);
		if(qr<=mid)
			modify(l,mid,ql,qr,idx<<1);
		else if(ql>mid)
			modify(mid+1,r,ql,qr,idx<<1|1);
		else{
			modify(l,mid,ql,mid,idx<<1);
			modify(mid+1,r,mid+1,qr,idx<<1|1);
		}
		seg[idx] = seg[idx<<1]+seg[idx<<1|1];
	}
	int query(int l,int r,int ql,int qr,int idx){
		if(ql==l&&qr==r)
			return seg[idx];
		int mid = (l+r)>>1;
		down(idx);
		if(qr<=mid)
			return query(l,mid,ql,qr,idx<<1);
		else if(ql>mid)
			return query(mid+1,r,ql,qr,idx<<1|1);
		return query(l,mid,ql,mid,idx<<1)+query(mid+1,r,mid+1,qr,idx<<1|1);
	}
	inline void upd(int l,int r){
		modify(1,n,l,r,1);
	}
	inline int qu(int l,int r){
		return query(1,n,l,r,1);
	}
}st;
struct HDL{
	vector<pii>adj[N];
	inline void addE(int u,int v,int w){
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	int id[N],pa[N],mxc[N],rt[N],dep[N],sz[N],ww[N];
	int num,tmp,sum;
	void dfs(int x,int px){
		pa[x] = px;
		sz[x] = 1;
		for(auto i:adj[x]){
			if(i.F==px)
				continue;
			dep[i.F] = dep[x]+i.S;
			dfs(i.F,x);
			sz[x] += sz[i.F];
			ww[i.F] = i.S;
			if(sz[mxc[x]]==0||sz[mxc[x]]<sz[i.F])
				mxc[x] = i.F;
		}
	}
	void build(int x,int px,int root){
		rt[x] = root;
		id[x] = ++tmp;
		val[id[x]] = ww[x];
		if(mxc[x])
			build(mxc[x],x,root);
		for(auto i:adj[x]){
			if(i.F==px||i.F==mxc[x])
				continue;
			build(i.F,x,i.F);
		}
	}	
	void init(){
		dfs(1,0);
		build(1,0,1);
		st.build(1,n,1);
	}
	inline void upd(int x){
		sum += dep[x];
		num++;
		while(x){
			int y = rt[x];
			st.upd(id[y],id[x]);
			x = pa[y];
		}
	}
	inline int qu(int x){
		int res = sum+num*dep[x];
		while(x){
			int y = rt[x];
			res -= 2*st.qu(id[y],id[x]);
			x = pa[y];
		}
		return res;
	}
}G;

bool vis[N];

void solve(){
	cin >> n >> q;
	for(int i=1,u,v,w;i<n;i++){
		cin >> u >> v >> w;
		G.addE(u+1,v+1,w);
	}
	G.init();
	while(q--){
		int type,x; cin >> type >> x;
		if(type==1){
			if(!vis[x+1]){
				vis[x+1] = 1;
				G.upd(x+1);
			}
		}
		else
			cout << G.qu(x+1) << '\n';
	}
 }

signed main(){
    Rushia_mywife
    solve();
}

