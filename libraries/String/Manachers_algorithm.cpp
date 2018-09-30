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
 <ref:https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4/>
Manacher’s Algorithm
 文字列に含まれる最大部分文字列をO(|文字列長|)で探索する
 
 ただし、1文字の時は例外
 */
struct Manacher{
    string text;
    string palindrome;
    vector<int> LPS;    // LPS Length Array
    int N;  // Position count
    int CP; // CenterPosition
    int CR; // CenterRightPosition
    int i;  // cuttentRightPosition
    int iMirror;    // currentLeftPosition
    int maxLPSLength;
    int maxLPSCenterPosition;
    int start = -1;
    int end = -1;
    int diff = -1;
    Manacher(){};
    Manacher(string text){init(text);};
    void init(string& text){
        this->text = text;
        N = 2*(int)text.length() + 1;
        LPS.clear(); LPS.resize(N); LPS[0] = 0; LPS[1] = 1;
        CP = 1; CR = 2; i = 0;
        maxLPSLength = 0; maxLPSCenterPosition = 0;
    }
    
    void fix(){
        if(N==1){
            palindrome = "";
            return;
        }
        for(i = 2; i < N; i++){
            iMirror = 2*CP - i;
            LPS[i] = 0;
            diff = CR - i;
            if(diff > 0) LPS[i] = min(LPS[iMirror],diff);
            while(((i+LPS[i])<N&&(i-LPS[i])>0)&&(((i+LPS[i]+1)%2==0)||(text[(i+LPS[i]+1)/2]==text[(i-LPS[i]-1)/2]))){
                LPS[i]++;
            }
            if(LPS[i]>maxLPSLength){
                maxLPSLength=LPS[i];
                maxLPSCenterPosition=i;
            }
            if(i+LPS[i]>CR){
                CP = i;
                CR = i + LPS[i];
            }
        }
        start = (maxLPSCenterPosition - maxLPSLength)/2;
        end = start + maxLPSLength - 1;
        palindrome = text.substr(start,maxLPSLength);
    }
    string get_palindrome(){
        return palindrome;
    }
};

// test
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    Manacher manacher;
    vector<string> strs={
        "",
        "b",
        "bb",
        "babcbabcbaccba",
        "abaaba",
        "abababa",
        "abcbabcbabcba",
        "forgeeksskeegfor",
        "caba",
        "abacdfgdcaba",
        "abacdfgdcabba",
        "abacdedcaba"
    };
    for(auto str:strs){
        manacher.init(str);
        manacher.fix();
        cout << "LPS of string is " << str << " : " << manacher.get_palindrome() << endl;
    }
    
    return 0;
}
