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
 <url:https://beta.atcoder.jp/contests/abc009/tasks/abc009_4>
 問題文============================================================
 =================================================================
 解説=============================================================

 xor -> +
 and -> x
 と見立てて行列累乗ができる
 ================================================================
 */

fn mul(A: &Vec<Vec<i64>>, B: &Vec<Vec<i64>>, _MOD: i64) -> Vec<Vec<i64>> {
    let mut C: Vec<Vec<i64>> = Vec::new();
    for i in 0usize..A.len() {
        let mut c: Vec<i64> = (0usize..B[0].len()).map(|v| 0i64).collect();
        C.push(c);
    }

    for i in 0usize..A.len() {
        for k in 0usize..B.len() {
            if A[i][k] == 0 {
                continue;
            }
            for j in 0usize..B[0].len() {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= _MOD;
            }
        }
    }
    C
}

fn pow(A: &Vec<Vec<i64>>, n: i64, _MOD: i64) -> Vec<Vec<i64>> {
    let mut A = A.clone();
    let mut n = n.clone();

    let mut B: Vec<Vec<i64>> = Vec::new();
    for i in 0usize..A.len() {
        let mut b: Vec<i64> = (0usize..A.len()).map(|v| 0i64).collect();
        B.push(b);
    }

    for i in 0usize..A.len() {
        B[i][i] = 1;
    }
    while n > 0 {
        if n % 2 == 1 {
            B = mul(&B, &A, _MOD);
        }
        A = mul(&A, &A, _MOD);
        n >>= 1;
    }
    B
}

fn bitmul(A: &Vec<Vec<i64>>, B: &Vec<Vec<i64>>) -> Vec<Vec<i64>> {
    let mut C: Vec<Vec<i64>> = Vec::new();
    for i in 0usize..A.len() {
        let mut c: Vec<i64> = (0usize..B[0].len()).map(|v| 0i64).collect();
        C.push(c);
    }

    for i in 0usize..A.len() {
        for k in 0usize..B.len() {
            for j in 0usize..B[0].len() {
                C[i][j] ^= A[i][k] & B[k][j];
            }
        }
    }
    C
}

fn bitpow(A: &Vec<Vec<i64>>, n: i64) -> Vec<Vec<i64>> {
    let mut A = A.clone();
    let mut n = n.clone();

    let mut B: Vec<Vec<i64>> = Vec::new();
    for i in 0usize..A.len() {
        let mut b: Vec<i64> = (0usize..A.len()).map(|v| 0i64).collect();
        B.push(b);
    }
    for i in 0usize..A.len() {
        B[i][i] = -1;
    }
    while n > 0 {
        if n % 2 == 1 {
            B = bitmul(&B, &A);
        }
        A = bitmul(&A, &A);
        n >>= 1;
    }
    B
}


fn main() {
    input!(K:i64,M:i64,A:[i64;K],C:[i64;K]);
    if M <= K {
        println!("{}", A[(M - 1) as usize]);
    } else {
        let mut B: Vec<Vec<i64>> = Vec::new();
        for i in 0..K {
            let mut b: Vec<i64> = (0..K).map(|v| 0i64).collect();
            B.push(b);
        }

        for i in 0..K {
            B[0][i as usize] = C[i as usize];
        }
        for i in 0..K - 1 {
            B[1 + i as usize][i as usize] = -1;
        }
        B = bitpow(&B, M - K);
        let mut ans = 0;
        for i in 0..K{
            ans ^= B[0][i as usize]&A[(K-1-i) as usize];
        }
        println!("{}", ans);
    }
}