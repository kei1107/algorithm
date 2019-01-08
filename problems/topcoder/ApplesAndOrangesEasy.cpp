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
class ApplesAndOrangesEasy {
public:
    int maximumApples(int N, int K, vector <int> info) {
        int res = 0;
        sort(info.begin(),info.end());
        vector<int> filled(N,0);
        for(int v:info) filled[v-1] = true;
        for(int i = 0; i < N;i++){
            if(filled[i]) continue;
            filled[i] = 1;
            
            int sum = 0;
            for(int j = 0; j < K;j++) sum += filled[max(0,i-K+1)+j];
            bool ok = true;
            for(int j = max(0,i-K+1); j <= min(i+K-1,N-1)-K+1;j++){
                if(sum > K/2){
                    ok = false; break;
                }
                sum -= filled[j];
                sum += filled[j+K];
            }
            if(!ok) filled[i] = 0;
        }
        res = (int)count(filled.begin(),filled.end(),1);
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {3, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {1, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(2, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {2, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arg0 = 23; int Arg1 = 7; int Arr2[] = {3, 2, 9, 1, 15, 23, 20, 19}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(4, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    ApplesAndOrangesEasy ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
