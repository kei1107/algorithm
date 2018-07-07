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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1149&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 指定クエリ通りに実際にシミュレーションしていけば良い
 
 ================================================================
 */

int n,w,d;
vector<ll> solve(){
    vector<ll> res;
    vector<pll> ps(n);
    for(auto& in:ps){cin >> in.first >> in.second; in.first--; }
    vector<pll> pieces; pieces.push_back({w,d});
    for(auto query:ps){
        ll p,s; tie(p,s) = query;
        ll W,D; tie(W,D) = pieces[p];
        pieces.erase(pieces.begin()+p);

        s %= 2*(W+D);
        
        ll W1,W2,D1,D2;
        if(s <= W){
            W1 = s; W2 = W - W1;
            D1 = D2 = D;
        }else if(s <= W+D){
            W1 = W2 = W;
            D1 = s - W; D2 = W+D-s;
        }else if(s <= W+D+W){
            W1 = s - (W+D); W2 = (W+D+W) - s;
            D1 = D2 = D;
        }else{
            W1 = W2 = W;
            D1 = s - (W+D+W); D2 = (W+D+W+D) - s;
        }
        
        if(W1*D1 > W2*D2){
            swap(W1,W2); swap(D1,D2);
        }
        pieces.push_back({W1,D1});
        pieces.push_back({W2,D2});
    }
    
    sort(pieces.begin(),pieces.end(),
         [](const pll& c1,const pll& c2){
             return c1.first*c1.second < c2.first*c2.second;
         });
    for(auto p:pieces){
        res.push_back(p.first*p.second);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n >> w >> d,n|w|d){
        cout << solve() << endl;
    }
    return 0;
}
