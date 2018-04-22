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
 <url:https://yukicoder.me/problems/no/54>
 問題文============================================================
 今日はハロウィンなので、太郎君は近所の家におかしをもらいに行くことにしました。
 
 近所には、太郎君の家以外に N軒の家があります。
 それぞれのi家に行くとおかしをVi個もらえるのですが、
 近所のこどもたちに平等におかしを配るため、
 すでにおかしをTi個以上持っていると、おかしを一つももらえないことになっています。
 
 太郎君は、最初におかしを一つも持っていないこととし、近所の家を周るのは好きな順番で周ることができるとき、
 太郎君がもらえるおかしの最大の個数を求めてください。
 同じ家には1回しか回れないとします。
 =================================================================
 解説=============================================================
 
 dpっぽい
 ある家の条件が(V,T)とすると、
 その家を出た時のお菓子の所持数であり得る範囲は [V,V+T-1]
 となる。他の家についても同様のことがいえる。
 ここで、dpによって数を増やして行くには、あり得る範囲が単調増加して行くような仮定があれば、
 そのままdpを行って最適な状態に持って行くことができる為、
 
 前もって、家について V+Tについてソートしておいて、dpを行えばよい
 ================================================================
 */

#define MAX_V 20005
bool dp[MAX_V];
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> V(N),T(N);
    vector<pll> VT(N);
    ll MV = 0,MT = 0;
    for(auto& in:VT){ cin >> in.first >> in.second; MV = max(MV,in.first); MT = max(MT,in.second); }
    sort(VT.begin(),VT.end(),[](const pll& p1,const pll& p2){return (p1.first + p1.second) < (p2.first + p2.second);});
    dp[0] = true;
    for(int i = 0; i < N;i++){
        for(ll j = MT-1; j >= 0;j--){
            if(!dp[j]) continue;
            if(j < VT[i].second){
                dp[j+VT[i].first] = true;
                res = max(res,j+VT[i].first);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
