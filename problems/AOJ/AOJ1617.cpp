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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1617&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 頑張ってparserを書いて比較する
 ================================================================
 */

pair<vector<string>,vector<string>> reader(const string s){
    vector<string> ret1,ret2;
    
    stringstream ss(s);
    int counter = 0;
    string t;
    while(getline(ss,t,'"')){
        if(counter%2 == 1){
            ret2.push_back(t);
        }else{
            ret1.push_back(t);
        }
        counter++;
    }
    return {ret1,ret2};
}
template<class Type>
Type solve(Type res = Type()){
    string s1,s2;
    while(cin>>s1){
        if(s1 == ".") break;
        cin >> s2;
        
        if(s1 == s2){
            cout << "IDENTICAL" << endl;
            continue;
        }
        vector<string> r11,r12,r21,r22;
        tie(r11,r12) = reader(s1);
        tie(r21,r22) = reader(s2);
        
//        cout << r11 << endl;
//        cout << r12 << endl;
//        cout << r21 << endl;
//        cout << r22 << endl;
        if(r11 != r21 || r12.size()!=r22.size()){
            cout << "DIFFERENT" << endl;
            continue;
        }
    
        int cnt = 0;
        for(int i = 0; i < r12.size();i++){
            if(r12[i]!=r22[i])cnt++;
        }
        if(cnt==0){
            cout << "IDENTICAL" << endl;
        }else if(cnt == 1){
            cout << "CLOSE" << endl;
        }else{
            cout << "DIFFERENT" << endl;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
