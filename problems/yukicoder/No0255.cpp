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
 <url:https://yukicoder.me/problems/no/255>
 問題文============================================================
 =================================================================
 解説=============================================================
 疲れた。。てか、、、制約。。。。。。
 
 
 制約がおかしいけど座圧すればなんとかなる。
 
 んで座圧した後の処理の処理も大変
 頂点に重みを持たせて順次更新していく（ただし、他のチームが塗りつぶす時の処理に注意)
 ================================================================
 */

const ll MOD = 1000000000000000009;
const pll INIT = make_pair(0, 0);
struct SegTree {
    int N;
    pll init_v;
    vector<pll> node;
    vector<pll> lazy;
    
    SegTree(int _N):init_v(INIT){
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, init_v);
    }
    
    void build(){
        for(int k = N - 2; k >= 0; k--){
            node[k] = merge(node[2*k+1],node[2*k+2]);
        }
    }
    
    pll merge(pll l,pll r){
        pll ret = INIT;
        ret.first = l.first + r.first;
        ret.second = l.second + r.second;
        return ret;
    }
    
    void lazy_evaluate(ll k) {
        if(lazy[k].second == 0){
            node[k].first += lazy[k].first*node[k].second;
            if (k < N - 1) {
                lazy[2*k+1].first+=lazy[k].first;
                lazy[2*k+2].first+=lazy[k].first;
            }
        }else{
            node[k].first = 0;
            node[k].first += lazy[k].first*node[k].second;
            if (k < N - 1) {
                lazy[2*k+1].first=lazy[k].first; lazy[2*k+1].second = 1;
                lazy[2*k+2].first=lazy[k].first; lazy[2*k+2].second = 1;
            }
        }
        lazy[k] = init_v;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    pll update(ll a, ll b, ll x1,ll x2) { return update(a, b, 0, 0, N, x1,x2); }
    pll update(ll a, ll b, int k, int l, int r, ll x1,ll x2) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeを参照する前には必ず更新
            return node[k];
        }
        if (a <= l && r <= b) {
            lazy_evaluate(k);
            lazy[k] = pll(x1,x2);
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            pll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x1,x2);
            pll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x1,x2);
            return node[k] = merge(vl,vr);
        }
    }
    
    /* [a,b) 引数の範囲に注意!! */
    pll query(ll a, ll b) { return query(a, b, 0, 0, N); }
    pll query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) {
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            pll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            pll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl,vr);
        }
    }
};
vector<ll> solve(){
    vector<ll> res = {0,0,0,0,0};
    ll N; cin >> N;
    ll Q; cin >> Q;
    if(Q==0) return res;
    vector<ll> x(Q),l(Q),r(Q);
    for(int i = 0; i < Q;i++){ cin >> x[i] >> l[i] >> r[i]; r[i]++;}
    
    // coordinate compress
    vector<ll> vs(2*Q);
    for(int i = 0; i < Q;i++){ vs[i] = l[i]; vs[i+Q] = r[i]; }
    
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    
    vector<ll> weight(vs.size()-1);
    for(int i = 0; i < weight.size();i++){
        weight[i] = vs[i+1] - vs[i];
    }
    for(int i = 0; i < Q;i++){
        l[i] = lower_bound(vs.begin(), vs.end(), l[i]) - vs.begin();
        r[i] = lower_bound(vs.begin(), vs.end(), r[i]) - vs.begin();
    }
    
    vector<vector<ll>> scores(Q+1,vector<ll>(5));
    for(int i = 0; i < 5;i++){
        SegTree ST((int)weight.size());
        for(int j = 0; j < weight.size();j++) ST.node[j+ST.N-1] = make_pair(0,weight[j]);
        ST.build();
        for(int j = 0; j < Q;j++){
            if(x[j] == 0){
                scores[j][i] = ST.query(l[j],r[j]).first;
                continue;
            }
            ll team = x[j]-1;
            if(team == i){
                ST.update(l[j],r[j],1,0);
            }else{
                ST.update(l[j],r[j],0,1);
            }
        }
        scores[Q][i] = ST.query(0,weight.size()).first;
    }
    
    for(int j = 0; j < Q;j++){
        if(x[j] != 0) continue;
        ll maxv = *max_element(scores[j].begin(), scores[j].end());
        if(count(scores[j].begin(),scores[j].end(),maxv)!=1) continue;
        for(int i = 0; i < 5;i++){
            if(scores[j][i] == maxv){
                (res[i] += scores[j][i])%=MOD;
            }
        }
    }
    for(int i = 0; i < 5;i++){
        (res[i] += scores[Q][i])%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
