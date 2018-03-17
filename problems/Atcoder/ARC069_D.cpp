#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc069.contest.atcoder.jp/tasks/arc069_b>
問題文============================================================
 すぬけくんは動物が好きなので動物園を作りました。
 
 この動物園では 1,2,3,…,N の番号を割り振られた N 匹の動物が円環状に並べられています。
 i(2≦i≦N−1) 番の動物は i−1 番の動物と i+1 番の動物と隣り合っています。
 また、1 番の動物は N 番の動物と 2 番の動物と隣り合っており、
 N 番の動物は N−1 番の動物と 1 番の動物と隣り合っています。
 
 動物園には本当のことしか言わない正直者の羊と、嘘しか言わない嘘つきの狼の 2 種類の動物がいます。
 
 すぬけくんには羊と狼の区別がつかないので、それぞれの動物に両隣の動物が同じ種類かどうかを訪ねたところ、
 i 番目の動物は si と答えました。si が o ならば両隣の動物が同じ種類であると、
 x ならば異なる種類であると i 番の動物が言ったことを示します。
 
 より形式的には、羊は両隣の動物がどちらも羊あるいはどちらも狼のとき o と答え、そうでないとき x と答えます。
 狼は両隣の動物がどちらも羊あるいはどちらも狼のとき x と答え、そうでないとき o と答えます。
 
 これらの回答結果と矛盾しないような各動物の種別の割り当てが存在するか、すぬけくんは気になっています。
 存在するならば一例を示し、存在しないならば -1 を出力しなさい。
 
=================================================================

解説=============================================================

 動物を 1,2番目を決めてしまえば、 1...Nまでの全ての動物の状態を一意に決定できる
 よって、 SW SS WS WW の４パターンから状態を復元して矛盾がなければそれを結果として出力する
================================================================
*/

string check(string SW,const string& s,const ll &N){
    for(int i = 1; i < N;i++){
        if(s[i] == 'o'){
            if(SW[i] == 'S'){
                SW.push_back(SW[i-1]);
            }else{
                if(SW[i-1] == 'S') SW.push_back('W');
                else SW.push_back('S');
            }
        }else{
            if(SW[i] == 'S'){
                if(SW[i-1] == 'S') SW.push_back('W');
                else SW.push_back('S');
            }else{
                SW.push_back(SW[i-1]);
            }
        }
    }
    if(SW[0] != SW[N]) return "";
    
    if(s[0] == 'o'){
        if(SW[0] == 'S'){
            if(SW[1] != SW[N-1]) return "";
        }else{
            if(SW[1] == SW[N-1]) return "";
        }
    }else{
        if(SW[0] == 'S'){
            if(SW[1] == SW[N-1]) return "";
        }else{
            if(SW[1] != SW[N-1]) return "";
        }
    }
    return SW;
}
void solve(){
    ll N; cin >> N;
    string s; cin >> s;
    
    string ss[4] = {"SS","SW","WS","WW"};
    string ret;
    for(int i = 0; i < 4;i++){
        ret = check(ss[i],s,N);
        if(ret.length() != 0){
            cout << ret.substr(0,N) << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
