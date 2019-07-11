/*
 BIT2D 1-index
 add : [s,t] に x を加算
 sum : [s,t] の総和を出力
 */
struct BIT2D {
    int H,W;
    vector<vector<ll>> bit;
    BIT2D(int H,int W):H(H),W(W) {
        /* BITは[1..H][1..W]で扱う */
        bit.assign(H+1,vector<ll>(W+1,0));
    }
    
    void add(int a,int b,int val){
        for(int x = a; x<= H; x+= x & -x){
            for(int y = b; y<=W;y+=y&-y){
                bit[x][y] += val;
            }
        }
    }
    
    int sum(int a,int b){
        int ret = 0;
        for(int x = a; x > 0; x-= x& -x){
            for(int y = b; y > 0; y-= y&-y){
                ret += bit[x][y];
            }
        }
        return (ret);
    }
};
