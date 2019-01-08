#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

const ll MOD = 1e9+7;
class TaroFillingAStringDiv1 {
public:
    int getNumber(int N, vector <int> position, string value) {
        int res = 0;
        int n = (int)position.size();
        vector<pair<int,char>> info(n);
        for(int i = 0; i < n;i++) info[i] = {position[i],value[i]};
        sort(info.begin(),info.end());
        
        vector<ll> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n;i++){
            int D = info[i].first-info[i-1].first;
            if(info[i].second == info[i-1].second){
                if(D%2 == 0){
                    dp[i] = dp[i-1];
                }else{
                    dp[i] = dp[i-1]*D%MOD;
                }
            }else{
                if(D%2 == 0){
                    dp[i] = dp[i-1]*D%MOD;
                }else{
                    dp[i] = dp[i-1];
                }
            }
        }
        
        //        string tmp(N,'_');
        //        for(auto p:info) tmp[p.first-1] = p.second;
        //        cout << tmp << endl;
        //        for(int i = 0; i < n;i++) cout << dp[i] << " "; cout << endl;
        res = (int)dp[n-1];
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AB"; int Arg3 = 2; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBA"; int Arg3 = 1; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 25; int Arr1[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBBBABABBAAABA"; int Arg3 = 1; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 305; int Arr1[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABAABBABBAABABBBBAAAABBABBBA"; int Arg3 = 43068480; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
int main(){
    TaroFillingAStringDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
