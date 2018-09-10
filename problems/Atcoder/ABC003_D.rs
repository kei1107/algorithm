#![allow(unused_mut, non_snake_case, unused_imports)]

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
 <url:https://beta.atcoder.jp/contests/abc003/tasks/abc003_4>
 問題文============================================================
 =================================================================
 解説=============================================================
 包除原理を用いて、対象パターンを計算する
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

fn main() {
    input!(R:i64,C:i64,X:i64,Y:i64,D:i64,L:i64);
    let (mut Inv, mut fact, mut factInv) = fact_init((X * Y + 1) as usize);
    let mut ans = 0i64;
    for i in 0i64..1 << 4 {
        let Xflag = (i >> 0 & 1) + (i >> 1 & 1);
        let Yflag = (i >> 2 & 1) + (i >> 3 & 1);
        if X <= Xflag || Y <= Yflag {
            continue;
        }
        let Area = (X - Xflag) * (Y - Yflag);
        if Area < D + L {
            continue;
        }
        let T = fact[Area as usize] * factInv[D as usize] % MOD * factInv[L as usize] % MOD * factInv[(Area - D - L) as usize] % MOD;
        ans += if (Xflag + Yflag) % 2 == 0 { T } else { MOD - T };
        ans %=MOD;
    }
    ans *= (R - X + 1) % MOD * (C - Y + 1) % MOD;
    ans %= MOD;
    println!("{}", ans);
}