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
 <url:https://yukicoder.me/problems/no/162>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 上の歯と下の歯は同じ条件なので、一緒に計算できる
 
 ここで、歯の状態をもつとTLEするが、
 まとまった歯の本数を持つことでメモ化再帰で計算が可能
 ================================================================
 */

typedef long double ld;

ld memo[21][15];
ld P[3];
ld rec(int a,int tooth){
    if(a == 0) return tooth;
    ld& ret = memo[a][tooth];
    if(!(ret < 0)) return ret;
    ret = 0;
    if(tooth == 1){
        ret  = (1-P[0])*rec(a-1,tooth);
    }else{
        for(int t = 0; t < (1<<tooth);t++){
            ld Ptooth = 1;
            ld sum = 0;
            int cnt_tooth = 0;
            
            for(int b = 0; b <= tooth;b++){
                if((t>>b)&1){
                    if(b == 0 || b == tooth-1){
                        Ptooth *= (1-P[1]);
                    }else{
                        Ptooth *= (1-P[2]);
                    }
                    cnt_tooth++;
                }else{
                    if(b == 0 || b == tooth-1){
                        Ptooth *= P[1];
                    }else if(b != tooth){
                        Ptooth *= P[2];
                    }
                    if(cnt_tooth){
                        sum += rec(a-1,cnt_tooth);
                    }
                    cnt_tooth = 0;
                }
            }
            ret += Ptooth * sum;
        }
    }
    return ret;
}
ld solve(){
    fill(*memo,*memo+21*15,-1);
    ld res = 0;
    int A; cin >> A; A = 80 - A;
    for(int i = 0; i < 3;i++){ cin >> P[i]; P[i]/=100;}
    res = rec(A,14)*2;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
