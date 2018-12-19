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
 <url:https://atcoder.jp/contests/code-festival-2014-relay/tasks/code_festival_relay_j>
 問題文============================================================
 =================================================================
 解説=============================================================
 コードのtest関数などを実行(時間がかかるので途中で止めた方がいい)して、
 値を眺めると規則性が見えてくる
 
 Nが奇数なら first
 Nが偶数なら
    K >= N/2    first
    otherwise   second
 ================================================================
 */

bool rec(int pre,bool turn,int k,vector<int>& flag){
    bool ret;
    int n = (int)flag.size();
    if(turn == false){
        ret = false;
        if(pre == -1){ // 初手
            for(int i = 0; i < n;i++){
                flag[i] = true;
                ret |= rec(i,!turn,k,flag);
                flag[i] = false;
            }
        }else{ // 3手以降
            for(int i = 0; i < n;i++){
                if(flag[i]) continue;
                if(abs(i-pre)<=k) continue;
                flag[i] = true;
                ret |= rec(i,!turn,k,flag);
                flag[i] = false;
            }
        }
        return ret;
    }else{
        ret = true;
        // 2手以降
        for(int i = 0; i < n;i++){
            if(flag[i]) continue;
            if(abs(i-pre)<=k) continue;
            flag[i] = true;
            ret &= rec(i,!turn,k,flag);
            flag[i] = false;
        }
    }
    return ret;
}
void test(){
    for(int n = 1; n <= 50;n++){
        vector<int> flag(n);
        for(int k = 0; k <= n;k++){
            fill(flag.begin(),flag.end(),false);
            bool ret = rec(-1,false,k,flag);
            if(ret){
                cout << "mp[pll("<<n<<","<<k<<")=true"<<endl;
            }else{
                cout << "mp[pll("<<n<<","<<k<<")=false"<<endl;
            }
        }
    }
}
template<class Type>
Type solve(Type res = Type()){
    ll n,k; cin >> n >> k;
    if(n%2==1 || k >= n/2){
        res = "first";
    }else{
        res = "second";
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //test();
    //solve<ll>();
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}
