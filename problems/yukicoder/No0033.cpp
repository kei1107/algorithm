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
 <url:https://yukicoder.me/problems/no/33>
 問題文============================================================
 N匹のアメーバが１直線上にいます。
 各アメーバには初期座標が与えられます。
 初期座標はすべて整数座標です。
 アメーバは１秒後に３つに分裂します。
 その後、１匹は現在の座標から−Dだけ移動します。
 もう１匹は現在の座標から+Dだけ移動します。
 最後の１匹はそのままの座標です。
 また、アメーバは同じ座標に２匹以上いると、
 合体して１匹になります。
 最初にN匹いたアメーバがT秒後には
 何匹になっているか答えなさい。
 =================================================================
 解説=============================================================
 
 合体する可能性がありうるのは
 abs(Xi - Xj)%D == 0 となり得る i,jの組である。
 よって合体する可能性があり得るグループのみで独立して計算すれば良い
 
 計算の仕方についてか、
 
 座標順にソートした時、端にいるアメーバは　左端なら負の座標方向、右端なら正の座標方向に必ず　T匹に分裂する
 
 その他の部分に関しては
 
            X                 Y
 -----------+-----------------+------------
 となっているとすれば
 X,Yから伸びたアメーバが互いに合体しないほど離れていれば　2*T匹増える
 合体したとすれば、X-Y間のDずつの座標は全てアメーバで埋め尽くされるので (Y-X)/D - 1 匹増える
 
 よって、各区間に関して min(2*T,(Y-X)/D - 1)で判定でき、
 それを全てのグループで行えば良い
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,D,T; cin >> N >> D >> T;
    vector<ll> X(N); for(auto& in:X) cin >> in;
    vector<int> group(N,-1);
    int g = 0;
    for(int i = 0; i < N;i++){
        if(group[i] != -1) continue;
        for(int j = i; j < N; j++) if(abs(X[i]-X[j])%D == 0) group[j] = g;
        g++;
    }
    
    vector<vector<ll>> G(g);
    for(int i = 0; i < N;i++) G[group[i]].push_back(X[i]);
    for(auto& a:G){
        sort(a.begin(),a.end()); a.erase(unique(a.begin(),a.end()),a.end());
        
        res += a.size() + 2*T;
        for(int i = 1; i < a.size();i++){
            res += min((a[i]-a[i-1])/D - 1,2*T);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
