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
 <url:https://yukicoder.me/problems/no/15>
 問題文============================================================
 太郎君はカタログショッピングが大好き。
 
 今日もカタログから商品を選んで購入したのだが、
 太郎君はとてもお金持ちなので適当に商品を選んでしまい、
 何を購入したかいつも忘れてしまいます。
 
 幸い、クレジットカードの明細は手元にあるので、
 購入した合計金額だけはわかりました。
 
 太郎君が何を購入したのかを計算し、その商品番号を太郎君に教えてあげてください。
 ただし、一つの商品を複数買うことはないものとします。
 =================================================================
 解説=============================================================
 
 半分全列挙
 
 dp に対して、合計だけではなく、その集合を表すbitなどを一緒に持たせると楽
 ================================================================
 */

void solve(){
    ll N,S; cin >> N >> S;
    vector<ll> P(N);
    for(auto& in:P) cin >> in;
    
    ll n1 = N/2;
    ll n2 = N - n1;
    vector<pll> dp(1LL<<n1,{0,0});
    for(int i = 0; i < (1LL<<n1); i++){
        for(int j = 0; j < n1;j++){
            if((i>>j)&1) dp[i].first += P[j];
        }
        dp[i].second = i;
    }
    sort(dp.begin(),dp.end());
    vector<ll> ans;
    for(ll i = 0; i < (1LL<<n2); i++){
        ll Sum = 0;
        for(int j = 0; j < n2;j++){
            if((i>>j)&1) Sum += P[n1+j];
        }
        if(Sum > S) continue;
        auto l = lower_bound(dp.begin(), dp.end(),pll(S-Sum,0));
        auto r = upper_bound(dp.begin(), dp.end(), pll(S-Sum,(1LL<<N)));
        for(;l!=r;l++){
            if(S - Sum != (l->first)) break;
            ll mask = 0;
            for(int k = 0; k < n1;k++){
                if((l->second>>k)&1) mask |= (1<<(N-1-k));
            }
            for(int k = 0; k  <n2;k++){
                if((i>>k)&1) mask |= (1<<(n2-1-k));
            }
            ans.push_back(mask);
        }
    }
    sort(ans.begin(),ans.end(),greater<ll>());
    for(auto mask:ans){
        vector<ll> v;
        for(ll i = N-1; i >= 0;i--){
            if((mask>>i)&1){
                v.push_back(N-1 - i + 1);
            }
        }
        cout << v << endl;
    }
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
