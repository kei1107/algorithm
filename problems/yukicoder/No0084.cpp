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
 <url:https://yukicoder.me/problems/no/84>
 問題文============================================================
 太郎君はそろばんが苦手で、特に、珠の位置によってその珠が表す数が違うことに納得ができなかった。
 そこで、太郎君は二次元の各場所に珠があるかどうかのみで表す整数を決めるような新しい方法を考えだした。
 以下ではわかりやすさを優先して、抽象化して説明する。
 R 行 C 列のマス目があり、各マスには珠があるかどうかである。
 珠は合計で RC−1 個ある。つまり、1 マスだけ珠がないマスが存在する。
 各盤面に対して 0 以上の整数を対応させる。
 また、対応させる整数の最大値を K とすると、0 以上 K 以下の全ての整数に対して対応する盤面が存在しなければいけない。
 ただし、そろばんはひっくり返すことはできないが、
 回転することができるため、回転して一致する盤面に対しては同じ整数を対応させなくてはいけない。
 R と C が与えられるので、対応させる整数の最大値 K の最大値を求めるプログラムを書いてください。
 =================================================================
 解説=============================================================
 
 対称性にはパターンがあるので、実際に調べ
 規則性を見つけ出してかぞえあげる。
 
 今回の場合は　R、Cが一致するか、R*Cが偶数、奇数かという場合で
 区別できる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll R,C; cin >> R >> C;
    if(R!=C){
        if(R*C%2==0)res = R*C/2-1;
        else res = R*C/2;
    }else{
        if(R*C%2==0)res = R*C/4-1;
        else res = R*C/4;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
