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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1155&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 頑張って構文解析。
 
 P,Q,Rは２７通りしかないので、
 先にP,Q,Rの値を決め打ちして各場合に関して、その答えが2になるか確かめれば良い
 ================================================================
 */

int rec(int& i,const string& s){
    int ret = 0;
    if(s[i] >= '0' && s[i] <= '3'){
        ret = s[i] - '0';
        i++;
    }else if(s[i] == '-'){
        i++;
        int tmp = rec(i,s);
        if(tmp == 0) ret = 2;
        if(tmp == 1) ret = 1;
        if(tmp == 2) ret = 0;
    }else if(s[i] == '('){
        i++;
        int l = rec(i,s);
        char c = s[i];
        i++;
        int r = rec(i,s);
        i++;
        if(c == '+') ret = max(l,r);
        if(c == '*') ret = min(l,r);
    }
    return ret;
}
int solve(const string& s){
    int res = 0;
    string tmp;
    for(int P = 0; P < 3; P++){
        for(int Q = 0; Q < 3; Q++){
            for(int R = 0; R < 3; R++){
                tmp = s;
                char p = '0'+P;
                char q = '0'+Q;
                char r = '0'+R;
                replace(tmp.begin(),tmp.end(),'P',p);
                replace(tmp.begin(),tmp.end(),'Q',q);
                replace(tmp.begin(),tmp.end(),'R',r);
                int i = 0;
                if(rec(i,tmp) == 2) res++;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string s;
    while(cin >> s){
        if(s == ".") break;
        cout << solve(s) << endl;
    }
    return 0;
}
