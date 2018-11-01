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
 <url:https://yukicoder.me/problems/no/260>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 A以上B以下であれば
 
 F(X) := X以下であり、かつアホになりかつ青春しない数の個数
 としてやれば
 F(B) - F(A-1)で求まる
 
 ここでF(X)を求めるには
 
 dp[i][j][k][l][m]; // i桁目,桁和j,k:3を含むか否か,l:確実にA以下か,m:直近3桁
 として桁dpしてやればいい
 
 ここで、８の倍数の判定にmを導入したが、
 必要なのは末尾3桁だけであるため、末尾3桁を見るときだけmを有効にしてやれば高速に動作する
 ================================================================
 */

const ll MOD = 1e9+7;

ll dpA[2][3][2][2][1000]; // i桁目,桁和j,3を含むか否か,確実にA以下か,直近3桁
ll dpB[2][3][2][2][1000];
ll solve(){
    ll res = 0;
    string A,B; cin >> A >> B;
    
    
    int curA = 0,nextA = 1;
    for(auto& c:A) c -= '0';
    dpA[curA][0][0][0][0] = 1;
    for(int i = 0; i < A.length();i++){
        for(int j = 0; j < 3;j++){
            for(int k = 0; k < 2;k++){
                for(int l = 0; l < 2;l++){
                    if(i < A.length()-3){
                        int m = 0;
                        if(dpA[curA][j][k][l][m] == 0) continue;
                        int lim = l ? 9 : A[i];
                        for(int d = 0; d <= lim;d++){
                            (dpA[nextA][(j+d)%3][k||(d==3)][l||(d < lim)][m]
                             += dpA[curA][j][k][l][m])%=MOD;
                        }
                        dpA[curA][j][k][l][m] = 0;
                    }else{
                        for(int m = 0; m < 1000;m++){
                            if(dpA[curA][j][k][l][m] == 0) continue;
                            int lim = l ? 9 : A[i];
                            for(int d = 0; d <= lim;d++){
                                (dpA[nextA][(j+d)%3][k||(d==3)][l||(d < lim)][m%100*10+d]
                                 += dpA[curA][j][k][l][m])%=MOD;
                            }
                            dpA[curA][j][k][l][m] = 0;
                        }
                    }
                }
            }
        }
        swap(curA,nextA);
    }
    
    int curB = 0,nextB = 1;
    for(auto& c:B) c -= '0';
    dpB[curB][0][0][0][0] = 1;
    for(int i = 0; i < B.length();i++){
        for(int j = 0; j < 3;j++){
            for(int k = 0; k < 2;k++){
                for(int l = 0; l < 2;l++){
                    if(i < B.length()-3){
                        int m = 0;
                        if(dpB[curB][j][k][l][m] == 0) continue;
                        int lim = l ? 9 : B[i];
                        for(int d = 0; d <= lim;d++){
                            (dpB[nextB][(j+d)%3][k||(d==3)][l||(d < lim)][m]
                             += dpB[curB][j][k][l][m])%=MOD;
                        }
                        dpB[curB][j][k][l][m] = 0;
                    }else{
                        for(int m = 0; m < 1000;m++){
                            if(dpB[curB][j][k][l][m] == 0) continue;
                            int lim = l ? 9 : B[i];
                            for(int d = 0; d <= lim;d++){
                                (dpB[nextB][(j+d)%3][k||(d==3)][l||(d < lim)][m%100*10+d]
                                 += dpB[curB][j][k][l][m])%=MOD;
                            }
                            dpB[curB][j][k][l][m] = 0;
                        }
                    }
                }
            }
        }
        swap(curB,nextB);
    }
    
    
    bool flag = false;
    if(accumulate(A.begin(),A.end(),0LL)%3==0||count(A.begin(),A.end(),3)!=0){
        ll thdigit = 0;
        for(int i = 0; i < A.length();i++){
            thdigit = thdigit*10 + A[i];
            thdigit%=1000;
        }
        if(thdigit%8!=0){
            flag = true;
        }
    }
    
    ll sumA = 0;
    for(int j = 0; j < 3;j++){
        for(int k = 0; k < 2;k++){
            for(int l = 0; l < 2;l++){
                for(int m = 0; m < 1000;m++){
                    if(j==0 || k == 1){
                        if(m%8!=0){
                            (sumA+=dpA[curA][j][k][l][m])%=MOD;
                        }
                    }
                }
            }
        }
    }
    ll sumB = 0;
    for(int j = 0; j < 3;j++){
        for(int k = 0; k < 2;k++){
            for(int l = 0; l < 2;l++){
                for(int m = 0; m < 1000;m++){
                    if(j==0 || k == 1){
                        if(m%8!=0){
                            (sumB+=dpB[curB][j][k][l][m])%=MOD;
                        }
                    }
                }
            }
        }
    }
    
    res = (sumB - sumA + MOD)%MOD;
    (res += flag)%=MOD;
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
