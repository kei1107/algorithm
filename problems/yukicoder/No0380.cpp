#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/380>
 問題文============================================================
 =================================================================
 解説=============================================================
 クソモン
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string str;
    while(getline(cin,str)){
        for(int i = 0; i < 3;i++){
            if(str.empty() || isalnum(str.back())) break;
            str = str.substr(0,str.length()-1);
        }
        bool ok = false;
        [&](){
            if(str.find("digi") == 0){
                str = str.substr(4);
                if(str.empty() || str.front() != ' ') return;
                for(auto& c:str) c = tolower(c);
                ok = str.rfind("nyo") == str.length()-3;
            }else if(str.find("petit") == 0){
                str = str.substr(5);
                if(str.empty() || str.front() != ' ') return;
                for(auto& c:str) c = tolower(c);
                ok = str.rfind("nyu") == str.length()-3;
            }else if(str.find("rabi") == 0){
                str = str.substr(4);
                if(str.empty() || str.front() != ' ') return;
                for(auto& c:str) c = tolower(c);
                for(auto c:str) ok |= isalnum(c);
            }else if(str.find("gema") == 0){
                str = str.substr(4);
                if(str.empty() || str.front() != ' ') return;
                for(auto& c:str) c = tolower(c);
                ok = str.rfind("gema") == str.length()-4;
            }else if(str.find("piyo") == 0){
                str = str.substr(4);
                if(str.empty() || str.front() != ' ') return;
                for(auto& c:str) c = tolower(c);
                ok = str.rfind("pyo") == str.length()-3;
            }
        }();
        if(ok){
            cout << "CORRECT (maybe)" << endl;
        }else{
            cout << "WRONG!" << endl;
        }
    }
    return 0;
}
