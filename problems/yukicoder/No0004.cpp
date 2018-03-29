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
 <url:https://yukicoder.me/problems/no/4>
 問題文============================================================
 
 授業中にもかかわらず遊んでしまうdaveは、
 理科の実験中に、色んな重さの種類があるおもりをすべて使って、
 ちょうど天秤が水平になるおもりの組み合わせがあるかを知りたくなったようで、それに遊び呆けてる。
 （すべてのおもりを使うため、使わなかったおもりはない。）
 
 あなたは、daveにその組み合わせがあるかどうか教えて、授業に集中させるようにしてください。
 
 もしそのような組み合わせがあれば possible 、なければ impossible を出力してください。
 
 =================================================================
 解説=============================================================
 
 dp[i][j] := i番目の重りを見た時,取得した重りの総和がjになるかどうか
 
 全ての重りの総和を S とすれば
 Sが奇数であれば、どう重りをとっても 天秤を水平にできない
 Sが偶数の時、
     dp[i][j] := i番目の重りを見た時,取得した重りの総和がjになるかどうか
 のdpを行い dp[N][S/2] が trueであるかどうかを見れば良い
 
 O(N*N*W)
 ================================================================
 */

bool dp[110][110*110];
string solve(){
    ll N; cin >> N;
    vector<ll> W(N);
    for(auto& in:W) cin >> in;
    ll sum = accumulate(W.begin(),W.end(),0LL);
    if(sum%2) return "impossible";
    dp[0][0] = true;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < 110*110; j++){
            if(!dp[i][j])continue;
            dp[i+1][j+W[i]] = dp[i+1][j] =  true;
        }
    }
    if(dp[N][sum/2]) return "possible";
    else return "impossible";
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
