#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://agc005.contest.atcoder.jp/tasks/agc005_a>
 問題文============================================================
 文字列 X が与えられます。X の長さは偶数であり、半分は S 、もう半分は T からなります。
 
 高橋君は ST という文字列が苦手です。なので以下の操作を 10^10000 回行うことにしました。
 
 X の(連続な)部分文字列で ST となるもののうち、最も左側にあるものを取り除く。存在しないならば何もしない。
 最終的に X は何文字になるかを求めてください。
 
 =================================================================
 
 解説=============================================================
 
 問題名 STring
 
 STはstackの ST
 よってstack
 
 stackで一つ手前の文字を確認しつつ左から右へなめる
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string X; cin >> X;
    stack<string> st;
    for(int i = 0; i < (int)X.length(); i++){
        if(X[i] == 'S') st.push("S");
        else{
            if(!st.empty()){
                string c = st.top();
                if(c == "S") {
                    st.pop();
                    continue;
                }
            }
            st.push("T");
        }
    }
    cout << st.size() << endl;
    return 0;
}
