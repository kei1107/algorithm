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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1240>
 問題文============================================================
 ある文字列を指定された順番に指定された操作を行ってできた文字列が与えられる。
 元の文字列を出力せよ
 =================================================================
 解説=============================================================
 実際に復元を行えば良い
 ================================================================
 */

void C(string& str){
    str = str.substr(1) + *str.begin();
}
void J(string& str){
    str = *str.rbegin() + str.substr(0,str.length()-1);
}
void E(string& str){
    if(str.length()&1) str = str.substr(str.length()/2+1) + str[str.length()/2] + str.substr(0,str.length()/2);
    else str = str.substr(str.length()/2) + str.substr(0,str.length()/2);
}
void A(string& str){
    reverse(str.begin(),str.end());
}
void M(string& str){
    for(char& c:str){
        if(isdigit(c)){
            c = (c-'0'+1)%10 + '0';
        }
    }
}
void P(string& str){
    for(char& c:str){
        if(isdigit(c)){
            c = (c-'0'+9)%10 + '0';
        }
    }
}
map<char,int> char2idx;
void (*Func[])(string& str) = {J,C,E,A,P,M};
void init(){
    string FuncName = "JCEAPM";
    for(int i = 0; i < FuncName.length();i++) char2idx[FuncName[i]] = i;
}
string solve(){
    string order,res;
    cin >> order >> res;
    reverse(order.begin(),order.end());
    for(char& c:order){
        Func[char2idx[c]](res);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init();
    int n; cin >> n;
    while(n--){
        cout << solve() << endl;
    }
    return 0;
}
