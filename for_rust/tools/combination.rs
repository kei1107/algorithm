static MOD: i64 = 1_000_000_007;
fn fact_init(MAX_N: usize) -> (Vec<i64>, Vec<i64>, Vec<i64>) {
    let mut Inv: Vec<i64> = vec![0; MAX_N];
    let mut fact: Vec<i64> = vec![0; MAX_N];
    let mut factInv: Vec<i64> = vec![0; MAX_N];

    Inv[1] = 1;
    for i in 2..MAX_N as i64 {
        Inv[i as usize] = Inv[(MOD % i) as usize] * (MOD - MOD / i) % MOD;
    }

    fact[0] = 1;
    fact[1] = 1;
    factInv[0] = 1;
    factInv[1] = 1;
    for i in 2..MAX_N as i64 {
        fact[i as usize] = (fact[(i - 1) as usize] * i) % MOD;
        factInv[i as usize] = (factInv[(i - 1) as usize] * Inv[i as usize]) % MOD;
    }
    (Inv, fact, factInv)

    //let (mut Inv,mut fact,mut factInv) = fact_init((N+1) as usize);
}

fn powmod(a: i64, b: i64,_MOD:i64) -> i64 {
    let mut a: i64 = a;
    let mut b: i64 = b;
    let mut res: i64 = 1;
    a %= _MOD;
    while b != 0 {
        if b % 2 == 1 {
            res = res * a % _MOD;
        }
        a = a * a % _MOD;
        b >>= 1;
    }
    res
}

fn inversemod(a: i64, _MOD: i64) -> i64 {
    powmod(a, _MOD - 2,_MOD)
}

fn nCr(n: usize, r: usize,_MOD:i64,fact:&Vec<i64>,factInv:&Vec<i64>) -> i64 {
    let mut ret :i64 = 0;
    if n >= r { ret = fact[n]*factInv[r]%_MOD*factInv[n-r]%_MOD; }
    ret
}