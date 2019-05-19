#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://onlinejudge.u-aizu.ac.jp/problems/2883>
 問題文============================================================
 =================================================================
 解説=============================================================
 数字となる記号はa,b,c,dの4種類しか出てこないため、
 a,b,c,dがそれぞれ0〜9になるまでの 9^4パターンを全てためせばいい
 
 数字が決まればあとは簡単な構文解析をする
 ================================================================
 */


map<int,int> mp;

int bnf(int& i,const string& S){
    int ret = 0;
    
    if(S[i] == '['){
        i++; // [
        char op = S[i++];
        int h1 = bnf(i,S);
        int h2 = bnf(i,S);
        i++; // ]
        
        if(op == '+') ret = h1 | h2;
        if(op == '*') ret = h1 & h2;
        if(op == '^') ret = h1 ^ h2;
    }else{
        ret = S[i] - '0';
        i++;
    }
    return ret;
}

template<class Type>
Type solve(Type res = Type()){
    string S,P;
    while(true){
        cin >> S;
        if(S == ".") break;
        cin >> P;
        
        mp.clear();
        
        string T = S;
        
        int key = -1;
        for(char a = '0'; a <= '9'; a++){
            for(char b = '0'; b <= '9'; b++){
                for(char c = '0'; c <= '9'; c++){
                    for(char d = '0'; d <= '9'; d++){
                        replace(S.begin(),S.end(),'a',a);
                        replace(S.begin(),S.end(),'b',b);
                        replace(S.begin(),S.end(),'c',c);
                        replace(S.begin(),S.end(),'d',d);
 
                        int i = 0;
                        int V = bnf(i,S);
                        if(a == P[0] && b == P[1] && c == P[2] && d == P[3]){
                            key = V;
                        }
                        mp[V]++;
                        
                        
                        S = T;
                    }
                }
            }
        }
        cout << key << " " << mp[key] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // 	cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
