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
 <url:https://arc068.contest.atcoder.jp/tasks/arc068_c>
 問題文============================================================
 すぬけくんは鉄道会社を運営するゲームで遊ぶことにしました。
 すぬけ鉄道には M+1 個の駅があり、 0 から M までの番号がついています。
 すぬけ鉄道の列車は駅 0 から d 駅ごとに停車します。 例えば d=3 のとき駅 0,駅 3,駅 6,駅 9, … に停車します。
 
 すぬけ鉄道が走っている地域には N 種類の名産品があり、
 種類 i の名産品は 駅 li,駅 li+1,駅 li+2, …, 駅 ri のいずれかに列車が停車したとき購入することが可能です。
 
 列車が停車する間隔 d は 1,2,3,…,M の M 種類が存在しています。
 M 種類の列車それぞれについて、その列車に駅 0 で乗車した場合に購入可能な名産品の種類数を求めなさい。
 なお、列車から別の列車への乗り換えは許されないものとします。
 
 =================================================================
 解説=============================================================
 
 imos法＋BIT
 
 d駅ごとに停車する場合、
 [r-l+1]がd以上であれば、必ず購入できる。
 よって、 r-l+1がd未満のみの場合を着目すればよい
 
 これは、imos法とBITを使うことによって、対数時間で計算できる。
 
 ================================================================
 */

struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
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

void solve(){
    int N,M; cin >> N >> M;
    vector<pii> lr(N);
    for(auto& in:lr) cin >> in.first >> in.second;
    vector<vector<pii>> sec(M+2);
    for(auto& p:lr){
        sec[p.second-p.first+1].push_back(p);
    }
    BIT bit(M+2);
    ll incl = 0;
    for(int d = 1; d <= M;d++){
        for(auto p:sec[d-1]){
            bit.add(p.first,1);
            bit.add(p.second+1,-1);
        }
        incl += sec[d-1].size();
        ll out = N - incl;
        for(int x = d; x <= M; x += d){
            out += bit.sum(x);
        }
        cout << out << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
