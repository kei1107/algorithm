#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_c>
 問題文============================================================
 XXXX年のCODE FESTIVALには、世界中から高橋君を含めて N+1 人の参加者が集まりました。
 
 高橋君の都市と他の N 人の都市の時刻の差を調べてみたところ、i 番目の人の都市との時刻の差は Di 時間でした。
 ただし 2 つの都市について、片方の都市で 0 時の瞬間にもう一方の都市で d 時であるようなとき、
 これらの都市の時刻の差は min(d,24−d) であるものとします。
 ここで、時刻の表記には 24 時間表記を用いるものとします。
 つまり、例えば高橋君の都市で 0 時の瞬間には i 番目の人の都市は Di 時または 24−Di 時のいずれかとなります。
 
 高橋君は次に、N+1 人のうちの全ての 2 人組についてその人の都市どうしの時刻の差を書き出し、
 それらの時刻の差のうちの最小値を s としました。
 
 s として考えられる最大値を求めて下さい。
 =================================================================
 
 解説=============================================================
 
 高橋君を 0時とすることを最初に確定しておく。
 時差をソートしておき、順番に時間を見て行った時、
 おく時の選択は D[i] or 24 - D[i] となる
 
 ここで、その二つの選択に関して、それまでに確定した時間との差の最小値をそれぞれ見て行き、
 差が大きい選択をその都市の時間とすれば良い
 （ソートされているので時間は必ず　0 -> 12 or 24 -> 12 で埋まって行く）
 
 
 解説を確認したところ
 この選択方法は
     D[i] と 24-D[i] を交互に選択した場合と同義になる。（確かにそれは、そう）
 
 ================================================================
 */
ll solve(){
    ll ret = INF;
    ll N; cin >> N;
    vector<ll> D(N);
    for(auto& in:D) cin >> in;
    sort(D.begin(),D.end());
    vector<ll> t; t.push_back(0);
    for(int i = 0; i < N;i++){
        ret = min(ret,D[i]);
        
        ll t1 = D[i],t2 = 24 - D[i];
        ll dif1 = INF, dif2 = INF;
        for(auto T:t){
            dif1 = min(dif1,min(abs(t1-T),abs(24+t1-T)));
            dif2 = min(dif2,min(abs(t2-T),abs(24+t2-T)));
        }
        ret = min(ret,max(dif1,dif2));
        if(dif1 > dif2){
            t.push_back(t1);
        }else{
            t.push_back(t2);
        }
    }
    return ret;
}

ll solve_2(){
    ll ret = INF;
    ll N; cin >> N;
    vector<ll> D(N);
    for(auto& in:D) cin >> in;
    sort(D.begin(),D.end());
    vector<ll> t; t.push_back(0);
    for(int i = 0; i < N;i++){
        if(i%2 == 0){
            t.push_back(D[i]);
        }else{
            t.push_back(24-D[i]);
        }
    }
    for(int i = 0; i <= N;i++){
        for(int j = i+1; j <= N;j++){
            ret = min(ret,abs(t[i]-t[j]));
        }
    }
    return ret;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
