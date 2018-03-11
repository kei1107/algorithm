#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc064.contest.atcoder.jp/tasks/abc064_d>
問題文============================================================
 ( と ) で構成される N 文字の文字列 S が与えられる。S にいくつかの ( または ) を挿入することで正しい括弧列を作りたい。
 ただし、正しい括弧列は次のように定義されている：
 
 () は正しい括弧列である。
 X が正しい括弧列であるとき、(、X、) をこの順につなげたものは正しい括弧列である。
 X、Y が正しい括弧列であるとき、X と Y をこの順につなげたものは正しい括弧列である。
 それ以外の括弧列は正しくない。
 そのとき、作れる最も文字数が少ない正しい括弧列を求めなさい。このようなものが複数ある場合は、辞書順最小のものを求めなさい。
 
=================================================================

解説=============================================================

 良くあるパターン
 
 stackを使って 左括弧の情報（数）を保持しておき、
 dequeを用いて、復元を行えば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;
    deque<char> dq;
    stack<char> st;
    for(int i = 0; i < N;i++){
        if(S[i] == '('){
            st.push('(');
            dq.push_back('(');
        }else{
            dq.push_back(')');
            if(st.empty()){
                dq.push_front('(');
            }else{
                st.pop();
            }
        }
    }
    while(!st.empty()) {dq.push_back(')'); st.pop(); }
    cout << string(dq.begin(),dq.end()) << endl;
	return 0;
}
