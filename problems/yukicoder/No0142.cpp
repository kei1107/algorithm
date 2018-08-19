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
 <url:https://yukicoder.me/problems/no/142>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 難しいなぁ、、、、
 結局のところ、最終的な配列の偶奇がわかればいいので 見るべき値は 0 or 1である。
 よってbitで表現できるので、複数の要素をまとめてbitで管理すれば良い
 ================================================================
 */

const ll BatchSize = 50;
ll Comp[2000000/50*2];
ll Sec[100000/50*2];
string solve(){
    string res;
    ll N,Seed,X,Y,Z; cin >> N >> Seed >> X >> Y >> Z;
    vector<ll> A(N);
    A[0] = Seed;
    for(int i = 1; i < N;i++) A[i] = (X*A[i-1]+Y)%Z;
    for_each(A.begin(), A.end(), [](ll& a){ a%=2;});
    for(int i = 0; i < N;i++) Comp[i/BatchSize] |= A[i]<<(i%BatchSize);
    ll Q; cin >> Q;
    while(Q--){
        ll S,T,U,V; cin >> S >> T >> U >> V;
        ll len = T-S+1;
        S--; U--;
        ll b = S%BatchSize;
        for(int i = 0; i < len/BatchSize+2;i++){
            Sec[i+1] = Comp[S/BatchSize+i];
        }
        for(int i = 0; i < len/BatchSize+2;i++){
            Sec[i+1] = (Sec[i+1]>>b) | (((Sec[i+2]&((1LL<<b)-1)))<<(BatchSize-b));
        }
        for(int i = 0; i < len/BatchSize+4;i++){
            if((i+1)*BatchSize<=len) continue;
            else if((i+1)*BatchSize-len<=BatchSize) Sec[i+1] &=(1LL<<(len%BatchSize))-1;
            else Sec[i+1] = 0;
        }
        b = U%BatchSize;
        for(ll i = len/BatchSize+2; i >= 0; i--) Sec[i+1] = ((Sec[i+1]<<b) | (Sec[i]>>(BatchSize-b))) & ((1LL<<BatchSize)-1);
        for(int i = 0; i < len/BatchSize+2;i++){
            Comp[i+U/BatchSize] ^= Sec[i+1];
        }
    }
    for(int i = 0; i < N;i++){
        res += "EO"[(Comp[i/BatchSize]>>(i%BatchSize))&1];
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
