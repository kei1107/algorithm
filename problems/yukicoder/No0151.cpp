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
 <url:https://yukicoder.me/problems/no/151>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 左向きと右向きの魚を別々に考え、
 境界をスライドさせるようにして考える。
 そうすれば、BITで境界の左右反転の境界の管理に注意すれば解ける
 ================================================================
 */

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int N):N(N) {
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        x++;
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    // [0,x)
    ll sum(int x){
        ll ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    
    // [l,r)
    ll sum(int l,int r){
        return sum(r) - sum(l);
    }
};


void solve(){
    int N,Q; cin >> N >> Q;
    BIT bitL(N+Q), bitR(N+Q);
    
    int Lboundary = 0,Rboundary = Q;
    while(Q--){
        char x; int y,z; cin >> x >> y >> z;
        
        Lboundary++; Rboundary--;
        bitL.add(Lboundary+N-1,bitR.sum(Rboundary+N,Rboundary+N+1));
        bitR.add(Rboundary,bitL.sum(Lboundary-1,Lboundary));
        if(x == 'L'){
            bitL.add(Lboundary+y,z);
        }else if(x == 'R'){
            bitR.add(Rboundary+y,z);
        }else{
            ll Sum = 0;
            Sum += bitL.sum(Lboundary+y,Lboundary+z);
            Sum += bitR.sum(Rboundary+y,Rboundary+z);
            cout << Sum << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
