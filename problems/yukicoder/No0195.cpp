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
 <url:https://yukicoder.me/problems/no/195>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 今回の式は
 F{A,B}(i) = F{1,0}(i)*A + F{0,1}(i)*B
 として表される (F{x,y}(i) は初項がx,第二項がyのフィボナッチ数列のi番目)
 
 この時、F{1,0}(i)とF{0,1}(i)はそれぞれ大体45項を越えると10^9を越える値となるため、
 i,j,kについてそれぞれ45までの全探索をすることで解くことができる。
 
 この時、与えられたX,Y,Zのうちの種類が
 
 1種類なら　A=1を固定化して計算
 2種類なら　連立方程式を解く
 3種類なら　i,jについて連立方程式をとき、kについて等号が満たすことを確認すれば良い
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}

vector<ll> fibA,fibB;
pll calc1(ll i,vector<ll> v){
    ll A = 1,B = LINF;
    ll D = v[0] - fibA[i];
    if(D<=0||fibB[i]==0||D%fibB[i]!=0) return make_pair(LINF,LINF);
    B = D/fibB[i];
    return make_pair(A, B);
}
pll calc2(ll i,ll j,vector<ll> v){
    ll A = LINF,B = LINF;
    if(i == j) make_pair(LINF, LINF);
    if(i>j){
        swap(i,j);
        swap(v[0],v[1]);
    }
    if(i==0&&j==1){
        A = v[0];
        B = v[1];
    }
    if(i==0&&j>=2){
        A = v[0];
        ll D = v[1] - fibA[j]*A;
        if(D<=0 || D%fibB[j]!=0) return make_pair(LINF, LINF);
        B = D/fibB[j];
    }
    if(i==1&&j>=2){
        B = v[0];
        ll D = v[1] - fibB[j]*B;
        if(D<=0 || D%fibA[j]!=0) return make_pair(LINF, LINF);
        A = D/fibA[j];
    }
    if(i>=2&&j>=2){
        ll LCM = lcm(fibA[i],fibA[j]);
        ll muli = LCM/fibA[i],mulj = LCM/fibA[j];
        
        ll D1 = muli*v[0] - mulj*v[1];
        ll D2 = muli*fibB[i] - mulj*fibB[j];
        
        if(D2==0||D1%D2!=0) return make_pair(LINF, LINF);
        B = D1/D2;
        if(B<=0) return make_pair(LINF, LINF);
        
        ll D = v[1] - fibB[j]*B;
        if(D<=0 || D%fibA[j]!=0) return make_pair(LINF, LINF);
        A = D/fibA[j];
    }
    return make_pair(A, B);
}
pll calc3(ll i,ll j,ll k,vector<ll> v){
    ll A = LINF,B = LINF;
    tie(A,B) = calc2(i,j,v);
    if(A==LINF) return make_pair(LINF,LINF);
    if(v[2]!=fibA[k]*A+fibB[k]*B) return make_pair(LINF,LINF);
    return make_pair(A, B);
}
vector<ll> solve(){
    vector<ll> res = {LINF,LINF};
    fibA.resize(47); fibB.resize(47);
    fibA[0] = 1; fibA[1] = 0; fibB[0] = 0; fibB[1] = 1;
    for(int i = 2; i < fibA.size();i++){ fibA[i] = fibA[i-1] + fibA[i-2]; fibB[i] = fibB[i-1] + fibB[i-2];}
    
//    cout << fibA << endl;
//    cout << fibB << endl;
    
    ll X,Y,Z; cin >> X >> Y >> Z;
    vector<ll> v = {X,Y,Z};
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i = 0; i < fibA.size();i++){
        if(v.size() == 1){
            pll ret = calc1(i,v);
            res = min(res,vector<ll>{ret.first,ret.second});
            continue;
        }
        for(int j = 0; j < fibA.size();j++){
            if(v.size() == 2){
                pll ret = calc2(i,j,v);
                res = min(res,vector<ll>{ret.first,ret.second});
                continue;
            }
            for(int k = 0; k < fibA.size();k++){
                pll ret = calc3(i,j,k,v);
                res = min(res,vector<ll>{ret.first,ret.second});
            }
        }
    }
    if(res.front() == LINF) res = vector<ll>{-1};
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
