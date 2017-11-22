#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2014/2014-sp-tasks/2014-sp-d3.pdf>
 問題文============================================================
 JOIOJI さんは JOI 君の叔父さんである．
 JOIOJI さんは，J，O，I がそれぞれ 2 文字ずつ入った自分の名前を気に入っている．
 最近，JOIOJI さんに子どもが生まれた．JOIOJI さんは，子どもにも自分と同じく，J，O，I からなり，
 それぞれの文字がちょうど同じ数ずつ入った名前を付けようと考えている．
 JOIOJI さんは，家に代々伝わる巻物を持っている．巻物には詩が書かれている．
 詩は J，O，I の 3 種類の文字のみからなる N 文字の文字列である．
 JOIOJI さんは，詩に含まれる連続する文字列で，J，O，I が
 それぞれちょうど同じ数ずつ入ったもののうち最長のものを自分の子どもに名付けるつもりである．
 
 JOIOJI さんの持っている巻物に書かれた詩の情報が与えられる．詩に含まれる連続する文字列のうち，
 J，O，I がそれぞれちょうど同じ数ずつ入ったものの長さの最大値を求めるプログラムを作成せよ
 =================================================================
 解説=============================================================
 
 累積和
 J_cnt[t] - J_cnt[s-1] = O_cnt[t] - O_cnt[s-1] = I_cnt[t] - I_cnt[s-1]
 このままだと左辺・右辺の式に2変数 = O(N^2)
 式変形すると
 J_cnt[t] - O_cnt[t] = J_cnt[s-1] - O_cnt[s-1]
 J_cnt[t] - I_cnt[t] = J_cnt[s-1] - I_cnt[s-1]
 これで1変数となり、同個数のものをまとめる処理を含めてO(N log N)
 
 あとは計算
 ================================================================
 */


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> J_cnt(N,0),O_cnt(N,0),I_cnt(N,0);
    
    for(int i = 0; i < N;i++){
        if(i != 0){
            J_cnt[i] = J_cnt[i-1];
            O_cnt[i] = O_cnt[i-1];
            I_cnt[i] = I_cnt[i-1];
        }
        if(S[i] == 'J') J_cnt[i]++;
        else if(S[i] == 'O')O_cnt[i]++;
        else I_cnt[i]++;
    }
    vector<pair<pair<int,int>,int>> JOI(N+1);
    JOI[0] = {{0,0},0};
    for(int i = 0; i < N;i++){
        JOI[i+1].first.first = J_cnt[i] - O_cnt[i];
        JOI[i+1].first.second =J_cnt[i] - I_cnt[i];
        JOI[i+1].second = i+1;
    }
    sort(JOI.begin(),JOI.end());
    
    int res = 0;
    for(int l = 0; l < N;l++){
        auto r = upper_bound(JOI.begin() + l + 1, JOI.end(), make_pair(make_pair(JOI[l].first.first,JOI[l].first.second),INF)) - JOI.begin();
        if(JOI[l].first.first == JOI[r-1].first.first && JOI[l].first.second == JOI[r-1].first.second){
            res = max(res,JOI[r-1].second - JOI[l].second);
        }
    }
    cout << res << endl;
    return 0;
}
