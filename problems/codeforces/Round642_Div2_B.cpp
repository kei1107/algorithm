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
 <url:https://codeforces.com/contest/1287/problem/B>
 問題文============================================================
 B. Hyperset
 =================================================================
 解説=============================================================
 選択する文字列のうち2つを決め打ちする。
 この時、3つ目であるべき文字列が一意に定まる。
 よって、事前に各文字列について、その文字列がいくつ存在するのかを求めておいて、
 数え上げればいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){

    int N,K; cin >> N >> K;

    map<string,int> mp;
    vector<string> F(N);
    for(string& in:F){
        cin >> in;

        for_each(in.begin(),in.end(),[](char& c){
            switch (c) {
                case 'S':
                    c = 1;
                    break;
                case 'E':
                    c = 2;
                    break;
                case 'T':
                    c = 3;
                default:
                    break;
            }
        });
        mp[in]++;
    }

    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            string target = "";
            for(int k = 0; k < K;k++){
                if(F[i][k] == F[j][k]){
                    target.push_back(F[i][k]);
                }else{
                    target.push_back(6-F[i][k]-F[j][k]);
                }
            }
            res += mp[target];
        }
    }
    return res/3;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
