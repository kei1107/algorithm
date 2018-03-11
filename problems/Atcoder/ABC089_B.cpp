#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://beta.atcoder.jp/contests/abc089/tasks/abc089_b>
問題文============================================================
 日本では、3 月 3 日にひなあられという、色のついたお菓子をお供えする習慣があります。
 
 1 つの袋があり、ひなあられがN 個入っています。
 
 この袋には、桃色、白色、緑色の 3 種類か、
 桃色、白色、緑色、黄色の 4 種類のひなあられが入っていることが分かっています。
 
 桃色を P、白色を W、緑色を G、黄色を Y と表したとき、
 袋からひなあられを 1 粒ずつ取り出していったところ、
 i 番目に取り出したひなあられの色はSi でした。
 
 この袋に 3 種類のひなあられが入っていた場合は Three、
 4 種類のひなあられが入っていた場合は Four と出力してください。
 
 1 ≤ N ≤ 100
 Si は P か W か G か Y
 Si = P、 Sj = W、 Sk = G を満たす i , j , k が必ず存在する
=================================================================

解説=============================================================
 与えられた文字列の中に Y があれば Four
================================================================
*/
void solve(){
    ll N; cin >> N;
    vector<char> S(N);
    for(auto &in:S) cin >> in;
    bool f1,f2,f3,f4;
    f1 = f2 = f3 = f4 = false;
    for(int i = 0; i < N;i++){
        if(S[i] == 'P') f1 = true;
        if(S[i] == 'W') f2 = true;
        if(S[i] == 'G') f3 = true;
        if(S[i] == 'Y') f4 = true;
    }
    if(f4){
        cout << "Four" << endl;
    }else{
        cout << "Three" << endl;
    }
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
