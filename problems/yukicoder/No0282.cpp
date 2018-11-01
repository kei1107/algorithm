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
 <url:https://yukicoder.me/problems/no/282>
 問題文============================================================
 =================================================================
 解説=============================================================
 奇偶転置ソートを実装する
 https://ja.wikipedia.org/wiki/%E5%A5%87%E5%81%B6%E8%BB%A2%E7%BD%AE%E3%82%BD%E3%83%BC%E3%83%88
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> omori(N); iota(omori.begin(),omori.end(),1);
    bool update;
    for(int kassa = 0;;kassa++){
        update = false;
        vector<pll> tenbin(N);
        {
            fill(tenbin.begin(),tenbin.end(),make_pair(0, 0));
            for(int i = 0; i < N-1;i+=2) tenbin[i] = {omori[i],omori[i+1]};
            cout << "?";
            for(int i = 0; i < N;i++) cout << " " << tenbin[i].first << " " << tenbin[i].second;
            cout << endl;
            
            vector<char> rep(N); for(auto& in:rep) cin >> in;
            for(int i = 0; i < N;i++){
                if(tenbin[i].first == 0 || tenbin[i].second == 0) continue;
                if(rep[i] == '>'){
                    swap(omori[i],omori[i+1]);
                    update = true;
                }
            }
        }
        {
            fill(tenbin.begin(),tenbin.end(),make_pair(0, 0));
            for(int i = 0; i < N-2;i+=2) tenbin[i] = {omori[i+1],omori[i+2]};
            cout << "?";
            for(int i = 0; i < N;i++) cout << " " << tenbin[i].first << " " << tenbin[i].second;
            cout << endl;
            
            vector<char> rep(N); for(auto& in:rep) cin >> in;
            for(int i = 0; i < N;i++){
                if(tenbin[i].first == 0 || tenbin[i].second == 0) continue;
                if(rep[i] == '>'){
                    swap(omori[i+1],omori[i+2]);
                    update = true;
                }
            }
        }
        if(!update) break;
    }
    cout << "! " << omori << endl;
    return 0;
}
