#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc081.contest.atcoder.jp/tasks/arc081_c>
問題文============================================================
 文字列 S に対して，その文字列を構成する文字を 0 文字以上取り除き，
 残った文字を元の順番で並べて得られる文字列を S の部分列と呼びます．
 たとえば，arc や artistic や (空文字列) は artistic の部分列ですが，
 abc や ci は artistic の部分列ではありません．
 
 英小文字からなる文字列 A が与えられます．
 このとき，英小文字からなる文字列で，A の部分列ではないようなもののうち，最も短いものを求めてください．
 ただし，そのようなものが複数ある場合には，辞書順で最小のものを求めてください．
=================================================================

解説=============================================================
解説を見た
 
 後ろから利用できる文字に対して印をつけていき、
 のちに復元を行う
================================================================
*/

string solve(){
    string res = "";
    string A; cin >> A;
    vector<int> f(26,0);
    vector<int> nextC(A.length()+1,0);
    for(int i = (int)A.length()-1; i >= 0; i--){
        int cnt = 0;
        f[A[i]-'a'] = true;
        nextC[i] = nextC[i+1];
        for(int j = 0; j < 26;j++){
            if(f[j]) cnt++;
            else break;
        }
        if(cnt == 26) for(int j = 0; j < 26;j++) f[j] = false;
        nextC[i] = cnt%26;
    }
    for(int i = 0; i < A.length(); i++){
        char c = nextC[i] + 'a';
        res += c;
        while(i < A.length() && A[i] != c) i++;
    }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
