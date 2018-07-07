#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1148&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 面倒だったのでデータ構造で殴った
 ================================================================
 */

/*
 1-index
 RangeAdd : [s,t] に xを加算
 RangeSum : [s,t] の総和を出力
 */
struct BIT {
    int N;
    vector<int> bit1;
    vector<int> bit2;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit1.resize(N + 1, 0);
        bit2.resize(N + 1, 0);
    }
    
    void add1(int x, ll val){
        while (x <= N) {
            bit1[x] += val;
            x += x & -x;
        }
    }
    void add2(int x, ll val){
        while (x <= N) {
            bit2[x] += val;
            x += x & -x;
        }
    }
    
    // [l,r]
    void RangeAdd(int l,int r,ll val){
        // Update BIT1
        add1(l,val);
        add1(r+1,-val);
        
        // Update BIT2
        add2(l,val*(l-1));
        add2(r+1,-val*r);
    }
    
    ll sum1(int x){
        ll ret = 0;
        while (x) {
            ret += bit1[x];
            x &= (x - 1);
        }
        return (ret);
    }
    
    ll sum2(int x){
        ll ret = 0;
        while (x) {
            ret += bit2[x];
            x &= (x - 1);
        }
        return (ret);
    }
    
    ll sum(int x){
        return sum1(x)*x - sum2(x);
    }
    // [l,r]
    ll RangeSum(int l,int r){
        return sum(r) - sum(l-1);
    }
};
int N,M;
void solve(){
    int r; cin >> r;
    vector<BIT> BITs(M,BIT(1260));
    vector<int> t(r),n(r),m(r),s(r);
    for(int i = 0; i < r;i++) cin >> t[i] >> n[i] >> m[i] >> s[i];
    for(int i = 0; i < r;i++){
        if(s[i] == 1){
            for(int j = i + 1; j < r;j++){
                if(s[j] == 0 && n[i] == n[j] && m[i] == m[j]){
                    BITs[m[i]-1].RangeAdd(t[i],t[j]-1,1);
                   // cout << m[i] << " " <<t[i] << " " <<t[j] << endl;
                    break;
                }
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int ts,te,m; cin >> ts >> te >> m;
        int ans = 0;
        for(int i = ts; i < te;i++){
            ans += (BITs[m-1].RangeSum(i,i)>=1);
        }
        cout << ans << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M,N){
        solve();
    }
    return 0;
}
