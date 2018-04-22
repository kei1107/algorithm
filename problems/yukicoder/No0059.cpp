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
 <url:https://yukicoder.me/problems/no/59>
 問題文============================================================
 列車が出発駅から終点駅まで向かう。
 その間に中間駅がN個ある。
 列車は必ずすべての中間駅に停車する。
 列車は出発駅では荷物を1つも積んでいない。
 各中間駅では荷物を１つ積むか降ろすことが決まっている。
 荷物には重さWが設定されている。
 各中間駅では積むか降ろす荷物の重さが指定される。
 ・Wが正の数の場合は、重さ|W|の荷物を詰む。
 ・Wが負の数の場合は、重さ|W|の荷物を降ろす。
 
 ここでひとつ変わったルールがある。
 
 ・荷物を積むまえにすでにその荷物の重さ以上の荷物がK個以上列車に積まれている場合にはその荷物を積めない。
 
 この変わったルールのために荷物を積めない場合がある。
 ルールに反しなければ必ず荷物を積む。
 
 また、荷物を降ろす場合に指定した重さの荷物が積まれていない場合も考えられる。
 この場合は指定された荷物が無いのだから荷物を降ろす必要は無い。
 もし指定された重さの荷物があれば必ず1つ降ろす。
 最終的に何個の荷物を最終駅まで運ぶことになるだろうか？
 =================================================================
 解説=============================================================
 
 重さを頂点としたBITを使って、クエリ順に処理していけばよい
 
 ================================================================
 */

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, int val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    int sum(int x){
        int ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};

#define MAX_W 1000000
BIT bit(MAX_W);
ll solve(){
    int res = 0;
    int N,K; cin >> N >> K;
    vector<int> W(N); for(auto& in:W) cin >> in;
    for(int i = 0; i < N;i++){
        if(W[i] > 0){
            ll Sum = bit.sum(MAX_W);
            if(W[i]!=1) Sum -= bit.sum(W[i]-1);
            if(Sum >= K) continue;
            bit.add(W[i],1);
        }else{
            W[i] = -W[i];
            ll now = bit.sum(W[i]);
            if(W[i]!=1) now -= bit.sum(W[i]-1);
            if(now) bit.add(W[i],-1);
        }
    }
    res = bit.sum(MAX_W);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
