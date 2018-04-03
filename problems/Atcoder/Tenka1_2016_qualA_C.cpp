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
 <url:https://tenka1-2016-quala.contest.atcoder.jp/tasks/tenka1_2016_qualA_c>
 問題文============================================================
 天下一株式会社に勤務するワタナベくんは、社内のコミュニケーションにチャットツールを使っています。
 チャットツールには補完機能があり、@で始まるアカウント名を入力しようとすると、
 プレフィックスの一致するアカウント名の一覧を辞書順で補完候補として表示してくれます。
 
 ところが、ワタナベくんは補完候補の中から @yamamoto を選ぼうとした時に、
 間違って @yamada を選択してしまうことが多々あります。
 @yamada は @yamamoto より辞書順で小さく、 @yama まで入力した際に、候補の先頭に表示されてしまうためです。
 
 ワタナベくんは不思議な特技を持っていて、アルファベットの順番を自由に並べ替えることができます。
 例えば、ワタナベくんが特技を使ってアルファベットの順番を abcefghijklmdnopqrstuvwxyz にすると、
 m は d より小さくなり、 @yamamoto を @yamada より辞書順で小さくすることができます。
 
 アカウント名 Ai をアカウント名 Bi より辞書順で小さくしたいという要求が N 個与えられます。
 与えられた要求をすべて満たすような、ワタナベくんの特技によって並べ替えられたアルファベットの順番を求めてください。
 条件を満たすようなアルファベットの順番が複数存在する場合は、
 並べ替えられる前のアルファベットの順番での辞書順最小の順番を求めてください。
 =================================================================
 解説=============================================================
 
 まず、注目すべき文字はAとBで最初に異なる文字のみである。
 
 この遷移について、他の文字との遷移と照会し、遷移がDAGであれば辞書順最小の文字を作ることができる。
 DAGでなければ矛盾が生じるため -1
 
 DAGの場合　ワーシャルフロイドなどで遷移を伸ばして必要おき、のちに矛盾が生じないように一文字づつ決めて行けば良い
 ================================================================
 */

string solve(){
    string res = "";
    
    int N; cin >> N;
    vector<string> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];
    vector<pii> st;
    
    for(int i = 0; i < N;i++){ // 必要な遷移を抜き出す
        [&]{
            for(int j = 0; j < min(A[i].length(),B[i].length());j++){
                char s = A[i][j], t = B[i][j];
                if(s == t) continue;
                st.push_back({s-'a',t-'a'});
                return;
            }
            if(A[i].length() > B[i].length()) res = "-1";
        }();
        if(res == "-1") return res;
    }
    
    vector<vector<int>> G(26,vector<int>(26,false));
    for(auto p : st){ G[p.first][p.second]=true; } // 必要な遷移にへんを張る
    
    for(int i = 0; i < 26;i++){
        for(int j = 0; j < 26;j++){
            for(int k = 0; k < 26; k++){
                G[j][k] |= (G[j][i]&&G[i][k]); // ワーシャルフロイドの要領で必要な同士を遷移をつないでいく
            }
        }
    }
    for(int i = 0; i < 26;i++){
        for(int j = 0; j < 26;j++){
            if(i==j)continue;
            if(G[i][j]&&G[j][i]) return res = "-1"; // 遷移がDAGでなければ矛盾
        }
    }
    
    
    vector<int> used(26,false);
    while(true){
        if(res.length() >= 26) break;
        for(int i = 0; i < 26;i++){
            if(!used[i]){ // 未使用
                [&]{
                    for(int j = 0; j < 26;j++){
                        if(i == j) continue;
                        if(used[j]) continue;  // すでに使用済みであれば
                        if(G[j][i]) return; // 未使用なアルファベットから自身へ伸びる辺があれば
                    }
                    used[i] = 1;
                    res += ('a'+i);
                    return;
                }();
                if(used[i]) break;
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
