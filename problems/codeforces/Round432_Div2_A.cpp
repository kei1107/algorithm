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
 <url:http://codeforces.com/contest/959/problem/A>
 問題文============================================================
 
 Mahmoud and Ehab play a game called the even-odd game.
 Ehab chooses his favorite integer n and then they take turns,
 starting from Mahmoud. In each player's turn,
 he has to choose an integer a and subtract it from n such that:
 
 
 1 ≤ a ≤ n.
 If it's Mahmoud's turn, a has to be even, but if it's Ehab's turn, a has to be odd.
 
 
 If the current player can't choose any number satisfying the conditions, he loses. Can you determine the winner if they both play optimally?
 
 =================================================================
 解説=============================================================
 
 nが偶数であればMahmoudの勝利
 
 ================================================================
 */

string solve(){
    ll n; cin >> n;
    if(n == 1) return "Ehab";
    else {
        if(n%2==0){
            return "Mahmoud";
        }else{
            return "Ehab";
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
