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
 <url:https://yukicoder.me/problems/no/121>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 まず、全てが異なるという条件を無視したとき、
 真ん中の要素が最小or最大となるような場合は
 ある要素を見たとき、それよりも左右にある自身よりも大きい数の積と小さい数の積となる。
 これは座標圧縮をしておくことでBITを二つ使えば求めることができる
 
 あとは左右の要素が等しい場合に関しては
 
 左から順番に 連鎖的に求めることができる
 
 ================================================================
 */

struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    ll sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

const int MAXN = 1e6+10;
ll solve(){
    ll res = 0;
    int N; cin >> N;
    vector<int> A(N); for(auto& in:A) cin >> in;
    
    // compress
    vector<int> compA(A);
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    for(int i = 0; i < N;i++){
        compA[i] = (int)((lower_bound(A.begin(),A.end(),compA[i]) - A.begin()) + 1);
    }
    
    // main calc
    BIT lbit(MAXN),rbit(MAXN);
    res = 0;
    for(int i = 0; i < N;i++) rbit.add(compA[i],1);
    for(int i = 0; i < N;i++){
        int V = compA[i];
        rbit.add(V,-1);
        
        res += lbit.sum(V-1)*rbit.sum(V-1);
        res += lbit.sum(V+1,MAXN)*rbit.sum(V+1,MAXN);

        lbit.add(V,1);
    }

    vector<ll> Lcnt(MAXN),Rcnt(MAXN);
    for(int i = 0; i < N;i++) Rcnt[compA[i]]++;
    ll sub = 0;
    for(int i = 0; i < N;i++){
        sub -= Lcnt[compA[i]]*Rcnt[compA[i]];
        res -= sub;
        Lcnt[compA[i]]++; Rcnt[compA[i]]--;
        sub += Lcnt[compA[i]]*Rcnt[compA[i]];
    }
    res -= sub;

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
