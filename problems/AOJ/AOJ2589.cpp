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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589>
 問題文============================================================
 =================================================================
 解説=============================================================
 問題文通り、シミュレーションを頑張る
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
string S;
string solve(){
    string res;
    int i = (int)S.length()-1, a = 0, k = 1;
    while(S[i] != 'n' && S[i] != 'w') i--;
    if(S[i] == 'n') a = 0;
    else if(S[i] == 'w') a = 90;
    if(i > 0) i--;
    while(i!= 0){
        i--;
        if(S[i] == 'n'){
            a*=2; a -= 90; k *= 2;
        }else if(S[i] == 'w'){
            a*=2; a += 90; k *= 2;
        }
    }
    while(a%2==0&&k%2==0){ a/=2; k/=2;}
    if(k == 1) res = to_string(a);
    else res = to_string(a) + "/" + to_string(k);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> S){
        if(S == "#") break;
        cout << solve() << endl;
    }
    return 0;
}
