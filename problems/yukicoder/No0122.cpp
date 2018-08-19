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
 <url:https://yukicoder.me/problems/no/122>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ほう助原理を用いて、数え上げる
 
 >> http://kmjp.hatenablog.jp/entry/2015/01/09/0930
 ================================================================
 */

const ll MOD = 1e9+7;
const ll MAX = 20010;

ll U[2][MAX],S[2][MAX],D[2][MAX];

ll solve(){
    ll res = 0;
    int x[7][2];
    vector<int> order = {0,4,1,5,2,6,3};
    for(auto idx : order) cin >> x[idx][0] >> x[idx][1];
    
    for(int i = 1; i < MAX;i++){
        for(int j = 0; j < 4;j++){
            int a=j%4,b=(a+1)%4,c=(b+1)%4,d=(c+1)%4;
            if(x[a][0]<=i&&i<=x[a][1]){
                
                {
                    ll _B = max(0,min(i,x[b][1]+1)-x[b][0]);
                    ll _C = max(0,min(i,x[c][1]+1)-x[c][0]);
                    ll _D = max(0,min(i,x[d][1]+1)-x[d][0]);
                    ll _BC = max(0,min(i,min(x[b][1],x[c][1])+1)-max(x[b][0],x[c][0]));
                    ll _BD = max(0,min(i,min(x[b][1],x[d][1])+1)-max(x[b][0],x[d][0]));
                    ll _CD = max(0,min(i,min(x[c][1],x[d][1])+1)-max(x[c][0],x[d][0]));
                    ll _BCD = max(0,min(i,min({x[b][1],x[c][1],x[d][1]})+1)-max({x[b][0],x[c][0],x[d][0]}));
                    if(_B&&_C&&_D){
                        D[0][i] += _B*_C*_D;
                        D[0][i] -= _BC*_D;
                        D[0][i] -= _CD*_B;
                        D[0][i] -= _BD*_C;
                        D[0][i] += 2*_BCD;
                    }
                }
                
                {
                    ll _B = max(0,x[b][1]-max(i,x[b][0]-1));
                    ll _C = max(0,x[c][1]-max(i,x[c][0]-1));
                    ll _D = max(0,x[d][1]-max(i,x[d][0]-1));
                    ll _BC = max(0,min(x[b][1],x[c][1])-max(i,max(x[b][0],x[c][0])-1));
                    ll _BD = max(0,min(x[b][1],x[d][1])-max(i,max(x[b][0],x[d][0])-1));
                    ll _CD = max(0,min(x[c][1],x[d][1])-max(i,max(x[c][0],x[d][0])-1));
                    ll _BCD = max(0,min({x[b][1],x[c][1],x[d][1]})-max(i,max({x[b][0],x[c][0],x[d][0]})-1));
                    if(_B&&_C&&_D){
                        U[0][i] += _B*_C*_D;
                        U[0][i] -= _BC*_D;
                        U[0][i] -= _CD*_B;
                        U[0][i] -= _BD*_C;
                        U[0][i] += 2*_BCD;
                    }
                }
            }
        }
        
        for(int j = 0; j < 3;j++){
            int a=j%4+4,b=(j+1)%3+4,c=(j+2)%3+4;
            if(x[a][0]<= i && i <= x[a][1]){
                {
                    ll _B = max(0,min(i,x[b][1]+1)-x[b][0]);
                    ll _C = max(0,min(i,x[c][1]+1)-x[c][0]);
                    ll _BC = max(0,min(i,min(x[b][1],x[c][1])+1)-max(x[b][0],x[c][0]));
                    
                    D[1][i] += _B*_C - _BC;
                }
                
                {
                    ll _B = max(0,x[b][1]-max(i,x[b][0]-1));
                    ll _C = max(0,x[c][1]-max(i,x[c][0]-1));
                    ll _BC = max(0,min(x[b][1],x[c][1])-max(i,max(x[b][0],x[c][0])-1));
                    
                    U[1][i] += _B*_C - _BC;
                }
            }
        }
        
        for(int j = 0; j < 2;j++){
            D[j][i] %= MOD;
            U[j][i] %= MOD;
        }
    }
    
    for(int i = 0; i < 2;i++){
        for(int j = 1; j < MAX;j++){
            (S[i][j]=S[i][j-1]+U[i][j])%=MOD;
        }
    }
    for(int i = 1; i < MAX;i++){
        for(int j = 0; j < 2;j++){
            (res += (S[j][MAX-1]-S[j][i]+MOD)*D[!j][i])%=MOD;
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
