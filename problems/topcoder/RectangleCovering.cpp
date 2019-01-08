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
class RectangleCovering {
    public:
    int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
        int res = INF;
        int n = (int)boardH.size();
        vector<int> X;
        for(int i = 0; i < n;i++){
            if(boardH[i]<=holeH&&boardW[i]<=holeH) continue;
            else if(boardH[i]>holeH&&boardW[i]<=holeH){
                X.push_back(boardW[i]);
            }else if(boardH[i]<=holeH&&boardW[i]>holeH){
                X.push_back(boardH[i]);
            }else{
                X.push_back(max(boardW[i],boardH[i]));
            }
        }
        sort(X.rbegin(),X.rend());
        ll L = 0;
        for(int i = 0; i < X.size();i++){
            L += X[i];
            if(L>=holeW){
                res = min(res,i+1);
                break;
            }
        }
        
        X.clear();
        
        for(int i = 0; i < n;i++){
            if(boardH[i]<=holeW&&boardW[i]<=holeW) continue;
            else if(boardH[i]>holeW&&boardW[i]<=holeW){
                X.push_back(boardW[i]);
            }else if(boardH[i]<=holeW&&boardW[i]>holeW){
                X.push_back(boardH[i]);
            }else{
                X.push_back(max(boardW[i],boardH[i]));
            }
        }
        sort(X.rbegin(),X.rend());
        L = 0;
        for(int i = 0; i < X.size();i++){
            L += X[i];
            if(L>=holeH){
                res = min(res,i+1);
                break;
            }
        }
        if(res == INF) res = -1;
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {8,8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {6,6,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10000; int Arg1 = 5000; int Arr2[] = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1442,2448,42,1818,3535,3333,3456,7890,1,52}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    RectangleCovering ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
