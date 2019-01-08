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
class AlienAndHamburgers {
    public:
    int getNumber(vector <int> type, vector <int> taste) {
        auto ctype = type;
        sort(ctype.begin(),ctype.end());
        ctype.erase(unique(ctype.begin(),ctype.end()),ctype.end());
        for(auto& v:type) v = (int)(lower_bound(ctype.begin(),ctype.end(),v) - ctype.begin());

        int sz = (int)ctype.size();
        
        vector<int> costs(sz);
        for(int i = 0; i < sz;i++){
            int maxv = -INF;
            for(int j = 0; j < type.size();j++){
                if(type[j] == i){
                    maxv = max(maxv,taste[j]);
                }
            }
            
            if(maxv >= 0){
                int sum = 0;
                for(int j = 0; j < type.size();j++){
                    if(type[j] == i){
                        if(taste[j] >= 0) sum += taste[j];
                    }
                }
                costs[i] = sum;
            }else{
                costs[i] = maxv;
            }
        }
        sort(costs.rbegin(),costs.rend());
        int res = 0;
        int sum = 0;
        for(int i = 0; i < sz;i++){
            sum += costs[i];
            res = max(res,(i+1)*sum);
        }
        return res;
    }

    


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
