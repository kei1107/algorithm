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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

ll solve(){
    ll H,W; cin >> H >> W;
    ll res = 1;
    vector<vector<char>> masu(H+2,vector<char>(W+2,'.'));
    vector<pair<double,int>> event;
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            cin >> masu[i][j];
        }
    }
    
    vector<vector<pii>> masu2(H+2,vector<pii>(W+2));
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            masu2[i][j] = {j-1,H-i};
        }
    }

    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            if(masu[i][j] == '#'){
                
                double angle = 0;
                // increment pattern
                //  ..
                //  .#
                if(masu[i-1][j-1] == '.' && masu[i-1][j] == '.' && masu[i][j-1] == '.'){
                    angle = atan2(masu2[i][j].second+1,masu2[i][j].first);
                    event.push_back({angle,-1});
                }
                
                // increment pattern
                //  ##
                //  #.
                if(masu[i+1][j+1] == '.' && masu[i+1][j] == '#' && masu[i][j+1] == '#'){
                    angle = atan2(masu2[i][j].second,masu2[i][j].first+1);
                    event.push_back({angle,-1});
                }
                
                // decrement pattern
                //  .#
                //  ##
                if(masu[i-1][j-1] == '.' && masu[i-1][j] == '#' && masu[i][j-1] == '#'){
                    angle = atan2(masu2[i][j].second+1,masu2[i][j].first);
                    event.push_back({angle,1});
                }
                
                // decrement pattern
                //  #.
                //  ..
                if(masu[i+1][j+1] == '.' && masu[i+1][j] == '.' && masu[i][j+1] == '.'){
                    angle = atan2(masu2[i][j].second,masu2[i][j].first+1);
                    event.push_back({angle,1});
                }
            }
        }
    }
    
    sort(event.begin(),event.end());
    
    ll cnt = 1;
    for(auto it = event.rbegin(); it != event.rend(); it++){
        auto e = *it;
        cnt -= e.second;
        res = max(res,cnt);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
