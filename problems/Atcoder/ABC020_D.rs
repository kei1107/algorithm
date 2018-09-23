#![allow(unused_mut, non_snake_case, unused_imports)]

use std::iter;
use std::cmp::{max, min, Ordering};
use std::mem::swap;
use std::collections::{HashMap, HashSet, BinaryHeap, VecDeque};
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
 <url:https://beta.atcoder.jp/contests/abc020/tasks/abc020_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 解説AC

 こういうのはちゃんと解けるようにならなきゃな。。。
 https://www.slideshare.net/chokudai/abc020
 ================================================================
 */

static MOD: i64 = 1_000_000_007;

// 約数列挙
fn get_divisors(n: u64) -> Vec<u64> {
    let mut ret = Vec::<u64>::new();
    let mut i = 1;
    while i * i <= n {
        if n % i == 0 {
            ret.push(i);
            if n != i * i { ret.push(n / i); }
        }
        i += 1;
    }
    ret.sort();
    ret
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

fn LCM_sum(N: i64, K: i64) -> i64 {
    let mut ret: i64 = 0;
    let primes = prime_enum(K as u64);
    let primes_num = primes.len();
    for bit in 0..1 << primes_num {
        let mut mul: i64 = 1;
        let mut bit_count = 0;
        for i in 0..primes_num {
            if (bit >> i) & 1 == 1 {
                mul *= primes[i] as i64;
                bit_count += 1;
            }
        }
        let _N: i64 = N / mul;
        let F = mul;
        let L = _N * mul;
        let V = (F + L) * _N / 2 % MOD;
        if bit_count % 2 == 0 { ret += V; } else { ret += MOD - V; }
        ret %= MOD;
    }
    ret %= MOD;
    ret *= K;
    ret %= MOD;
    ret
}

fn main() {
    input!(N:u64,K:u64);
    let N: u64 = N;
    let K: u64 = K;
    let mut Ans = 0;
    let divisors = get_divisors(K);
    for divisor in divisors {
        // gcd(divisor*i,K) => divisor*gcd(i,K/divisor)
        let new_N = N / divisor;
        let new_K = K / divisor;
        let sum = LCM_sum(new_N as i64, new_K as i64) as u64;
        Ans += sum * divisor;
        Ans %= MOD as u64;
    }
    println!("{}", Ans);
}