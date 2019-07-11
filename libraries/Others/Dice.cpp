/*
 Dice
 */
typedef unsigned long long ull;
const ull MOD = 1e9+7;
struct Dice{
    ll s[6];
    void roll(char c){
        //the view from above
        // N
        //W E
        // S
        //s[0]:top
        //s[1]:south
        //s[2]:east
        //s[3]:west
        //s[4]:north
        //s[5]:bottom
        ll b;
        if(c=='E'){
            b=s[0];
            s[0]=s[3]; s[3]=s[5]; s[5]=s[2]; s[2]=b;
        }
        if(c=='W'){
            b=s[0];
            s[0]=s[2]; s[2]=s[5]; s[5]=s[3]; s[3]=b;
        }
        if(c=='N'){
            b=s[0];
            s[0]=s[1]; s[1]=s[5]; s[5]=s[4]; s[4]=b;
        }
        if(c=='S'){
            b=s[0];
            s[0]=s[4]; s[4]=s[5]; s[5]=s[1]; s[1]=b;
        }
        // migi neji
        if(c=='R'){
            b=s[1];
            s[1]=s[2]; s[2]=s[4]; s[4]=s[3]; s[3]=b;
        }
        
        if(c=='L'){
            b=s[1];
            s[1]=s[3]; s[3]=s[4]; s[4]=s[2]; s[2]=b;
        }
        
    }
    ll top() {
        return s[0];
    }
    ull hash(){
        ull res=0;
        for(int i=0;i<6;i++) res=res*MOD+s[i];
        return res;
    }
};
vector<Dice> makeDices(Dice d){
    vector<Dice> res;
    for(int i=0;i<6;i++){
        Dice t(d);
        if(i==1) t.roll('N');
        if(i==2) t.roll('S');
        if(i==3) {t.roll('S'); t.roll('S');}
        if(i==4) t.roll('L');
        if(i==5) t.roll('R');
        for(int k=0;k<4;k++){
            res.push_back(t);
            t.roll('E');
        }
    }
    return res;
}
