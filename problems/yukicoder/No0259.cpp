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
 <url:https://yukicoder.me/problems/no/259>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 魚が時刻0の時点でどちらの向きを向いており、どこにいるのかを逆算して解くことによって
 BITを用いた計算を行うことができる
 ================================================================
 */

template<typename type>
struct BIT0 { // 0-index
    int N;
    int nn;
    vector<type> data;
    //動的はmap<int?,type>data
    BIT0(int n) {
        N = n + 1;
        data = vector<type>(n + 1, 0);
        nn = 1;
        while (nn * 2 <= N)nn *= 2;
    }
    void add(ll i, type w) { // a[i] += w
        i++;
        for (int x = i; x < N; x += x & -x) {
            data[x] += w;
        }
    }
    type sum(ll i) { // iまでの和 [0,i)
        if(i < 0) return 0;
        type ret = 0;
        for (int x = i; x > 0; x -= x & -x) {
            ret += data[x];
        }
        return ret;
    }
    // [l, r)
    type sum(ll l, ll r) {
        return sum(r) - sum(l);
    }
};

int N,Q;
pll updateL(ll t,ll y,ll z,vector<BIT0<ll>>& bit){
    t %= 2*N;
    y += t;
    
    ll ind = -1;
    if(y < N){
        ind = 0;
    }else if(y < 2*N){
        y -= N;
        y = (N-1) - y;
        ind = 1;
    }else{
        y -= 2*N;
        ind = 0;
    }
    bit[ind].add(y,z);
    return pll(ind,y);
}
pll updateR(ll t,ll y,ll z,vector<BIT0<ll>>& bit){
    t %= 2*N;
    y -= t;
    
    ll ind = -1;
    if(y >= 0){
        ind = 1;
    }else if(y >= -N){
        y += N;
        y = (N-1) - y;
        ind = 0;
    }else{
        y += 2*N;
        ind = 1;
    }
    bit[ind].add(y,z);
    return pll(ind,y);
}
ll query(ll t,ll y,ll z,vector<BIT0<ll>>& bit){
    ll ret = 0;

    z--;
    {
        pll p1 = updateL(t,y,0,bit);
        pll p2 = updateL(t,z,0,bit);
        if(p1.first == p2.first){
            if(p1.first == 0){
                ret += bit[p1.first].sum(p1.second,p2.second+1);
            }else{
                ret += bit[p1.first].sum(p2.second,p1.second+1);
            }
        }else{
            if(p1.first == 0){
                ret += bit[p1.first].sum(p1.second,N) + bit[p2.first].sum(p2.second,N);
            }else{
                ret += bit[p1.first].sum(p1.second+1) + bit[p2.first].sum(p2.second+1);
            }
        }
    }
    {
        pll p1 = updateR(t,y,0,bit);
        pll p2 = updateR(t,z,0,bit);
        if(p1.first == p2.first){
            if(p1.first == 0){
                ret += bit[p1.first].sum(p2.second,p1.second+1);
            }else{
                ret += bit[p1.first].sum(p1.second,p2.second+1);
            }
        }else{
            if(p1.first == 0){
                ret += bit[p1.first].sum(p1.second+1) + bit[p2.first].sum(p2.second+1);
            }else{
                ret += bit[p1.first].sum(p1.second,N) + bit[p2.first].sum(p2.second,N);
            }
        }
    }
    
    return ret;
}
void solve(){
    cin >> N >> Q;
    vector<BIT0<ll>> bit;
    bit.push_back(BIT0<ll>(N)); bit.push_back(BIT0<ll>(N));
    while(Q--){
        char x;
        ll t,y,z;
        cin >> x >> t >> y >> z;
        if(x == 'L'){
            updateL(t,y,z,bit);
        }else if(x == 'R'){
            updateR(t,y,z,bit);
        }else{
            cout << query(t,y,z,bit) << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
