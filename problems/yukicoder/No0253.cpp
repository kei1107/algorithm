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
 <url:https://yukicoder.me/problems/no/253>
 問題文============================================================
 =================================================================
 解説=============================================================
 最初、現時点でのロウソクのさ長さを出せだと思ってて迷走した。
 
 ロウソクがもともと短い場合はにぶたんに誤差が出るので、
 その場合だけ例外処理
 
 それ以外では、l,rを一回の施行ごとに-1していってにぶたんすればいい
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll l = 10, r = 1000000000+1;
    
    ll add = 0;
    {
        cout << "? " << 50 << endl;
        ll rep; cin >> rep;
        add++;
        if(rep == 0){
            cout << "! 50" << endl;
            return 0;
        }
        if(rep == -1){
            while(true){
                cout << "? 0" << endl;
                ll rep; cin >> rep;
                if(rep == 0){
                    cout << "! " << add << endl;
                    return 0;
                }
                add++;
            }
        }
        
    }
    while(r-l>1){
        ll m = (l+r)/2;
        cout << "? " << m << endl;
        ll rep; cin >> rep;
        if(rep == 0){
            cout << "! " << m+add << endl;
            return 0;
        }
        if(rep >= 0){
            l = m;
        }else{
            r = m;
        }
        if(l!=0)l--;
        if(r!=0)r--;
        add++;
    }
    cout << "! " << l+add << endl;
    return 0;
}
