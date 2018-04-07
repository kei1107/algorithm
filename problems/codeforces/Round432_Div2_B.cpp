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
 <url:http://codeforces.com/contest/959/problem/B>
 問題文============================================================
 
 Mahmoud wants to send a message to his friend Ehab.
 Their language consists of n words numbered from 1 to n.
 Some words have the same meaning so there are k groups of
 words such that all the words in some group have the same meaning.
 
 Mahmoud knows that the i-th word can be sent with cost ai. For each word in his message,
 Mahmoud can either replace it with another word of the same meaning or leave it as it is.
 Can you help Mahmoud determine the minimum cost of sending the message?
 
 The cost of sending the message is the sum of the costs of sending every word in it.
 
 =================================================================
 解説=============================================================
 
 同グループ内で一番コストの小さい値を覚えておき、
 各文字が来た時、その最小のコストを選んでいくだけ
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n,k,m; cin >> n >> k >> m;
    vector<string> str(n);
    for(auto& in:str) cin >> in;
    vector<ll> a(n);
    for(auto& in:a) cin >> in;
    vector<ll> mina(k,LINF);
    map<string,int> mp;
    for(int i = 0; i < k;i++){
        ll x; cin >> x;
        for(int j = 0; j < x; j++){
            ll g; cin >> g; g--;
            mina[i] = min(mina[i],a[g]);
            mp[str[g]] = i;
        }
    }
    
    for(int i = 0; i < m;i++){
        string s; cin >> s;
        res += mina[mp[s]];
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
