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
 <url:https://yukicoder.me/problems/no/145>
 問題文============================================================
 =================================================================
 解説=============================================================
 yukiが降順に並んでいるので貪欲にパターンを決めることができる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; string S; cin >> N >> S;
    int abcdefgh,i,j,k,lmnopqrst,u,vwx,y,z;
    abcdefgh = i = j = k = lmnopqrst = u = vwx = y = z = 0;
    for(int x = 0; x < N;x++){
        if(S[x] == 'z') z++;
        else if(S[x] == 'y') y++;
        else if(S[x] > 'u') vwx++;
        else if(S[x]=='u') u++;
        else if(S[x]>'k')  lmnopqrst++;
        else if(S[x]=='k') k++;
        else if(S[x]>'i')  j++;
        else if(S[x]=='i') i++;
        else abcdefgh++;
    }
    while(y && u && k && i && abcdefgh){res++; y--; u--; k--;i--;abcdefgh--;}
    while(y && u && k && i>=2){res++;y--;u--;k--;i-=2;}
    while(y && u && k && j){res++;y--;u--;k--;j--;}
    while(y && u && k>=2){res++;y--;u--;k-=2;}
    while(y && u && lmnopqrst){res++;y--;u--;lmnopqrst--;}
    while(y && u>=2){res++;y--;u-=2;}
    while(y && vwx){res++;y--;vwx--;}
    while(y>=2){res++;y-=2;}
    while(z){res++;z--;}
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
