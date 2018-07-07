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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1180&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 じゃけん、シミュレーションしましょうね
 ================================================================
 */
int a; int L;
string getstr(const int V,int dig){
    ostringstream oss;
    oss << setw(dig) << setfill('0') << V;
    return oss.str();
}
vector<ll> solve(){
    vector<ll> res;
    map<string,int> mp;
    int idx = 0;
    while(true){
        string a_str = getstr(a,L);
        if(mp.count(a_str)){
            res = vector<ll>{mp[a_str],a,idx - mp[a_str]};
            break;
        }
        mp[a_str] = idx++;
        string s1 = a_str,s2 = a_str;
        sort(s1.rbegin(),s1.rend());
        sort(s2.begin(),s2.end());
        a = atoi(s1.c_str()) - atoi(s2.c_str());
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> a >> L,L){
        cout << solve() << endl;
    }
    return 0;
}
