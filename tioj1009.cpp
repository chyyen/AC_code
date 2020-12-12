#include<bits/stdc++.h>

#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
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
int lcm(int aaa,int bbb){
	return (aaa/__gcd(aaa,bbb))*bbb;
}
int C(int x){
	return x*(x-1)/2;
}
// --------------------------------------**

int h1,m1,s1,h2,m2,s2;
char t;

void solve(){
	cin >> h1 >> t >> m1 >> t >> s1;
	cin >> h2 >> t >> m2 >> t >> s2;
	s2 -= s1;
	if(s2<0){
		s2 += 60;
		m2--;
	}
	m2 -= m1;
	if(m2<0){
		m2 += 60;
		h2--;
	}
	h2 -= h1;
	if(h2<0)
		h2 += 24;
	cout << (h2<10 ? "0":"") << h2 << (m2<10 ? ":0":":") << m2 << (s2<10 ? ":0":":") << s2 << '\n';
}

signed main(){
    Rushia_mywife
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

