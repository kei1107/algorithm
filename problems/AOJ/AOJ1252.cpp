#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1252>
 問題文============================================================
 
 文字列配列が与えられる。
 
 ある文字列に
 
 1.任意の位置の文字を削除
 2.任意の位置にある文字を挿入
 3.任意の位置の文字を別のある文字に交換する
 4.隣接する二文字を入れ替える
 
 という操作が許されるとき、編集距離がd(1<=d<=2)となる組み合わせを出力する
 また文字列は200個以下、長さは16以下である。
 =================================================================
 解説=============================================================
 編集距離が 1 or 2 であるので,あらかじめ各文字列に許される操作を全て実施した結果を
 求めておき
 
 d = 1の時は
  ある文字列の変換後集合の中に確認する文字列が含まれていれば組
 d = 2の時は
  ある文字列の変換後集合及び確認する変換後集合に共通する文字列が存在すれば組
 ================================================================
 */

void transforms(const string& s1,set<string>& s){
    string tmp;
    for(int i = 0; i < s1.length();i++){
        tmp = s1;
        tmp.erase(tmp.begin() + i);
        s.insert(tmp);
    }
    for(int i = 0; i <=s1.length();i++){
        for(int j = 0; j < 26;j++){
            tmp = s1;
            char c = 'a' + j;
            tmp.insert(i,string(1,c));
            s.insert(tmp);
        }
    }
    for(int i = 0; i < s1.length();i++){
        for(int j = 0; j < 26;j++){
            tmp = s1;
            char c = 'a' + j;
            tmp.replace(i,1,string(1,c));
            s.insert(tmp);
        }
    }
    for(int i = 0; i < s1.length() - 1;i++){
        tmp = s1;
        swap(tmp[i],tmp[i+1]);
        s.insert(tmp);
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n,d;
    vector<pii> res;
    vector<string> name;
    set<string> s[201];
    while(cin >> n, n){
        cin >> d;
        res.clear();
        name.clear();
        name.resize(n);
        for(int i = 0; i < n;i++){
            cin >> name[i];
        }
        sort(name.begin(),name.end());
        
        for(int i = 0; i < n;i++){
            s[i].clear();
            transforms(name[i],s[i]);
        }
        
        if(d == 1){
            for(int i = 0; i < n - 1;i++){
                for(int j = i + 1; j < n;j++){
                    if(s[i].find(name[j]) != s[i].end()){
                        res.push_back({i,j});
                    }
                }
            }
        }else{
            for(int i = 0; i < n-1;i++){
                for(int j = i + 1; j < n;j++){
                    for(auto tmp_s:s[i]){
                        if(s[j].find(tmp_s) != s[j].end()){
                            res.push_back({i,j});
                            break;
                        }
                    }
                }
            }
        }
        
        for(auto ans:res){
            cout << name[ans.first] << "," <<name[ans.second]<<endl;
        }
        cout << res.size() << endl;
    }
    return 0;
}
