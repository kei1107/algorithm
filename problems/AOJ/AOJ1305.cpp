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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1305>
 問題文============================================================
 
 [group1]:[name],[name],....,[name].
 [group2]:....
 .
 .
 .
 
 という形式の文字列が与えられる。
 ここで[name]とある[group]が一致する時、[name]は[group]への参照となるとする時、
 
 [group1]に含まれる[name]の種類を述べよ
 =================================================================
 解説=============================================================
 
 まず、gruopとnameをパースしておく、
 
 その後、groupとなる名前を確認して置き、
 group1を順番に見ていく、その時groupの名前と同一の名前があれば、そのグループへ
 飛んで同様のことを行う。重複した数え上げを防ぐために一度確認したgroupは二度と
 見ないようにしておく
 ================================================================
 */
ll N;
set<string> s;
map<string,int> mp;
vector<string> S_split(string& S) {
    vector<string> ret;
    int l = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '.' || S[i] == ':' || S[i] == ',') {
            ret.push_back(S.substr(l, (i - l)));
            l = i + 1;
        }
    }
    return ret;
}



void dfs(string str,int idx,vector<vector<string>>& T,vector<int>& flag) {
    if(flag[idx] == 1) return;
    flag[idx] = 1;
    for (int i = 1; i < T[idx].size(); i++) {
        if (mp.count(T[idx][i])) {
            dfs(T[idx][i], mp[T[idx][i]], T,flag);
        }
        else {
            s.insert(T[idx][i]);
        }
    }
}

ll solve() {
    s.clear();
    mp.clear();
    ll res = 0;
    vector<string> S(N);
    vector<int> flag(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<string>> T(N);
    for (int i = 0; i < N; i++) {
        T[i] = S_split(S[i]);
        mp[T[i][0]] = i;
    }
    
    dfs(T[0][0], 0, T,flag);
    
    res = s.size();
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while (cin >> N, N) {
        cout << solve() << endl;
    }
    return 0;
}
