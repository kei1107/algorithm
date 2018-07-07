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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1137&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 頑張って復元とMCXI言語化しましょう
 ================================================================
 */
map<char,int> mp;
map<int,char> mpmp;
int mcxi2int(const string& s){
    int ret = 0;
    string MCXI = "1" + s;
    for(int i = 0; i < MCXI.length();i++){
        if(isdigit(MCXI[i])) continue;
        ret += mp[MCXI[i]]*(isdigit(MCXI[i-1])?(MCXI[i-1]-'0'):1);
    }
    return ret;
}
string int2mcxi(int val){
    string ret;
    string vals = to_string(val);
    reverse(vals.begin(),vals.end());
    for(int i = 0; i < vals.length();i++){
        int V = pow(10,i);
        if(vals[i] == '0') continue;
        string T;
        if(vals[i] != '1') T += vals[i];
        T += mpmp[V];
        ret = T + ret;
    }
    return ret;
}
string solve(){
    string res;
    string a,b; cin >> a >> b;
    int vala = mcxi2int(a),valb = mcxi2int(b);
    int val = vala + valb;
    res = int2mcxi(val);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    mp['m'] = 1000; mp['c'] = 100; mp['x'] = 10; mp['i'] = 1;
    mpmp[1000] = 'm'; mpmp[100] = 'c'; mpmp[10] = 'x'; mpmp[1] = 'i';
    int n; cin >> n;
    while(n--){
        cout << solve() << endl;
    }
    return 0;
}
