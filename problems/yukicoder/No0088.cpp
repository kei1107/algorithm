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
 <url:https://yukicoder.me/problems/no/88>
 問題文============================================================
 リバーシ(orしろくろ、オセロ)と呼ばれる、８×８マスの盤と表裏が白黒になっている６４枚の石を使うボードゲームがあります。
 今、織田くんとユキコちゃんはこのリバーシで遊んでいます。
 しかし、少し疲れたのでゲームの途中ですが休憩することにしました。
 休憩を終えてゲームを再開しようとしましたが、二人はなんと次がどちらの手番だったか忘れてしまったのです。
 先手(黒番)がどちらだったか、そしてお互いに一回もパスをしなかったことだけは覚えています。
 現在の盤の状態から次どちらが石を置けばいいのか二人に教えてあげてください。
 なお、次の手番のプレイヤーがパスをすることはないとします。
 
 =================================================================
 解説=============================================================
 全体の石の個数は順序が交代するたびに1増えていく
 
 よって、石の総数の偶奇で判断可能
 ================================================================
 */

string solve(){
    string s; cin >> s;
    vector<string> B(8);
    for(auto& in:B) cin >> in;
    ll cnt = 0;
    for(auto& s:B) cnt += (8-count(s.begin(),s.end(),'.'));
    
    if(cnt%2==0){
        return s;
    }else{
        if(s == "oda") return "yukiko";
        else return "oda";
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
