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
 <url:https://atcoder.jp/contests/abc122/tasks/abc122_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 (病み上がりで(まだ病み上がってないけど)頭が回らなかったので、
 dp[文字列長][5文字前の文字][4文字前の文字][3文字前の文字][2文字前の文字][1文字前の文字]をした
 ================================================================
 */

/*
 A()G()C
*/

char cs[5] = {'#','A','C','G','T'};
bool check(int i1,int i2,int i3,int i4,int i5){
    string S = string(1,cs[i1]) + string(1,cs[i2]) + string(1,cs[i3]) + string(1,cs[i4]) + string(1,cs[i5]);
    
    for(int i = 2; i < 5;i++){
        if(S[i-2] == 'A' && S[i-1] == 'G' && S[i] == 'C') return false;
    }
    for(int i = 0; i < 4;i++){
        swap(S[i],S[i+1]);
        for(int i = 2; i < 5;i++){
            if(S[i-2] == 'A' && S[i-1] == 'G' && S[i] == 'C') return false;
        }
        swap(S[i],S[i+1]);
    }
    return true;
}
ll dp[101][5][5][5][5][5];
const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    ll N;cin >> N;
    dp[0][0][0][0][0][0] = 1;
    for(int n = 0; n < N;n++){
        for(int i1 = 0; i1 < 5;i1++){
            for(int i2 = 0; i2 < 5;i2++){
                for(int i3 = 0; i3 < 5; i3++){
                    for(int i4 = 0; i4 < 5;i4++){
                        for(int i5 = 0; i5 < 5 ;i5++){
                            if(dp[n][i1][i2][i3][i4][i5] == 0) continue;
                            for(int i6 = 1; i6 < 5;i6++){
                                if(check(i2,i3,i4,i5,i6)){
                                    (dp[n+1][i2][i3][i4][i5][i6] += dp[n][i1][i2][i3][i4][i5]) %=MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i1 = 0; i1 < 5;i1++){
        for(int i2 = 0; i2 < 5;i2++){
            for(int i3 = 0; i3 < 5; i3++){
                for(int i4 = 0; i4 < 5;i4++){
                    for(int i5 = 0; i5 < 5 ;i5++){
                        (res += dp[N][i1][i2][i3][i4][i5])%=MOD;
                    }
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
