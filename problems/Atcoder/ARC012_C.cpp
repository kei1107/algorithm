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
 <url:https://atcoder.jp/contests/arc012/tasks/arc012_3>
 問題文============================================================
 C - 五目並べチェッカー 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    vector<vector<char>> masu(19,vector<char>(19));
    for(auto& vec:masu) for(auto& in:vec) cin >> in;

    int black = 0, white = 0;
    for(int i = 0; i < 19;i++){
        for(int j = 0; j < 19;j++){
            if(masu[i][j] == 'o') black++;
            if(masu[i][j] == 'x') white++;
        }
    }
    if(black == 0 && white == 0) return "YES";

    if(black < white || abs(black-white) >= 2) return "NO";

    auto check = [&](char c){
        int dx[8] = {1,1,1,0,-1,-1,-1,0};
        int dy[8] = {-1,0,1,1,1,0,-1,-1};

        for(int i = 0; i < 19;i++){
            for(int j = 0; j < 19;j++){

                if(masu[i][j] != c) continue;

                for(int k = 0; k < 8;k++){

                    bool ng = false;
                    for(int l = 0; l < 5;l++){
                        int ni = i + dx[k]*l;
                        int nj = j + dy[k]*l;

                        if(ni < 0 || ni >=19 || nj < 0 || nj >= 19){
                            ng = true;
                            break;
                        }
                        if(masu[ni][nj] != c){
                            ng = true;
                            break;
                        }

                    }
                    if(!ng){
                        return true;
                    }
                }
            }
        }
        return false;
    };

    // 両者勝利条件を満たしている
    if(check('o') && check('x')) return "NO";

    if(black == white){
        for(int i = 0; i < 19;i++){
            for(int j = 0; j < 19;j++){
                if(masu[i][j] == 'x'){
                    masu[i][j] = '.';
                    if(!check('x') && !check('o')) return "YES";
                    masu[i][j] = 'x';
                }
            }
        }

    }else{
        for(int i = 0; i < 19;i++){
            for(int j = 0; j < 19;j++){
                if(masu[i][j] == 'o'){
                    masu[i][j] = '.';
                    if(!check('x') && !check('o')) return "YES";
                    masu[i][j] = 'o';
                }
            }
        }
    }
    return "NO";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}