#![allow(unused_mut, non_snake_case,unused_imports)]
use std::iter;
use std::cmp::{max, min, Ordering};
use std::mem::{swap};
use std::collections::{HashMap,BTreeMap,HashSet,BTreeSet,BinaryHeap,VecDeque};
use std::iter::FromIterator;

//　高速 EOF要
//macro_rules! input {(source = $s:expr, $($r:tt)*) => {let mut iter = $s.split_whitespace();input_inner!{iter, $($r)*}};($($r:tt)*) => {let mut s = {use std::io::Read;let mut s = String::new();std::io::stdin().read_to_string(&mut s).unwrap();s};let mut iter = s.split_whitespace();input_inner!{iter, $($r)*}};}
//macro_rules! input_inner {($iter:expr) => {};($iter:expr, ) => {};($iter:expr, $var:ident : $t:tt $($r:tt)*) => {let $var = read_value!($iter, $t);input_inner!{$iter $($r)*}};}
//macro_rules! read_value {($iter:expr, ( $($t:tt),* )) => {( $(read_value!($iter, $t)),* )};($iter:expr, [ $t:tt ; $len:expr ]) => {(0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()};($iter:expr, chars) => {read_value!($iter, String).chars().collect::<Vec<char>>()};($iter:expr, usize1) => {read_value!($iter, usize) - 1};($iter:expr, $t:ty) => {$iter.next().unwrap().parse::<$t>().expect("Parse error")};}
// 低速 EOF不要
macro_rules! input {(source = $s:expr, $($r:tt)*) => {let mut iter = $s.split_whitespace();let mut next = || { iter.next().unwrap() };input_inner!{next, $($r)*}};($($r:tt)*) => {let stdin = std::io::stdin();let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));let mut next = move || -> String{bytes.by_ref().map(|r|r.unwrap() as char).skip_while(|c|c.is_whitespace()).take_while(|c|!c.is_whitespace()).collect()};input_inner!{next, $($r)*}};}
macro_rules! input_inner {($next:expr) => {};($next:expr, ) => {};($next:expr, $var:ident : $t:tt $($r:tt)*) => {let $var = read_value!($next, $t);input_inner!{$next $($r)*}};}
macro_rules! read_value {($next:expr, ( $($t:tt),* )) => {( $(read_value!($next, $t)),* )};($next:expr, [ $t:tt ; $len:expr ]) => {(0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()};($next:expr, chars) => {read_value!($next, String).chars().collect::<Vec<char>>()};($next:expr, usize1) => {read_value!($next, usize) - 1};($next:expr, $t:ty) => {$next().parse::<$t>().expect("Parse error")};}

/*
 <url:https://beta.atcoder.jp/contests/abc110/tasks/abc110_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 Mの同じ素因数の個数とNとの重複組み合わせの積
 ================================================================
 */

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
    let mut ret: i64 = 0;
    if n >= r { ret = fact[n] * factInv[r] % _MOD * factInv[n - r] % _MOD; }
    ret
}

fn nHr(n: usize, r: usize,_MOD:i64,fact:&Vec<i64>,factInv:&Vec<i64>) -> i64 {
    if n == 0 && r == 0 { return 1;}
    return nCr(n+r-1,r,_MOD,fact,factInv);
}

// 素因数分解
fn prime_fact(n: u64) -> Vec<u64> {
    let mut n = n;
    let mut ret = Vec::<u64>::new();
    while n != 1 {
        if n == 2 || n == 3 {
            ret.push(n);
            n /= n;
            continue;
        }
        let mut prime_flag = false;
        let mut i = 2;
        while i * i <= n {
            if n % i == 0 {
                ret.push(i);
                n /= i;
                prime_flag = true;
                break;
            }
            i += 1;
        }
        if !prime_flag {
            ret.push(n);
            n /= n;
        }
    }
    ret
}

// 素数列挙
fn prime_enum(n: u64) -> Vec<u64> {
    let mut n = n;
    let mut ret = Vec::<u64>::new();
    let mut i = 2;
    while i * i <= n {
        if n % i == 0 {
            ret.push(i);
        }
        while n % i == 0 { n /= i; }
        i += 1;
    }
    if n > 1 { ret.push(n); }
    ret.sort();
    ret
}


fn main(){
    input!(N:i64,M:i64);

    let (mut Inv,mut fact,mut factInv) = fact_init(200000);

    let mut Prime = prime_fact(M as u64);
    let mut mp = HashMap::new();
    for prime in Prime{
        let count = mp.entry(prime).or_insert(0);
        *count += 1;
    }

    let mut ans = 1;

    for (v,k) in mp{
        let ret = nHr(N as usize,k,MOD,&fact,&factInv);
        ans *= ret;
        ans%=MOD;
    }
    println!("{}",ans);
}
