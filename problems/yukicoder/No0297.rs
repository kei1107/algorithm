#![allow(unused_mut, non_snake_case, unused_imports)]

use std::iter;
use std::cmp::{max, min, Ordering};
use std::mem::swap;
use std::collections::{HashMap, BTreeMap, HashSet, BTreeSet, BinaryHeap, VecDeque};
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
 <url:https://yukicoder.me/problems/no/297>
 問題文============================================================
 =================================================================
 解説=============================================================
 math
 ================================================================
 */
fn main() {
    input!(N:usize,c:[char;N]);
    let c: Vec<char> = c;
    let mut v = c.iter()
        .filter(|&&c| c.is_digit(10))
        .map(|&c| c as i64 - '0' as i64)
        .collect::<Vec<i64>>();
    let mut plus = 0;
    let mut minus = 0;
    for &_c in &c {
        if _c == '+' {
            plus += 1;
        }
        if _c == '-' {
            minus += 1;
        }
    }

    v.sort();
    v.reverse();
    let mut Max = 0_i64;
    {// calc Max
        for i in 0..v.len() - minus - plus {
            Max = Max * 10 + v[i];
        }
        for i in v.len() - minus - plus..v.len() - minus {
            Max += v[i];
        }
        for i in v.len() - minus..v.len() {
            Max -= v[i];
        }
    }

    let mut Min = 0_i64;
    {// calc Min
        if minus != 0 {
            minus -= 1;
            plus += 1;
            for i in 0..v.len() - minus - plus {
                Min = Min * 10 - v[i];
            }
            for i in v.len() - minus - plus..v.len() - plus {
                Min -= v[i];
            }
            for i in v.len() - plus..v.len() {
                Min += v[i];
            }
        } else {
            v.reverse();
            let mut T = vec![0; plus + 1];
            for i in 0..v.len() {
                T[i % (plus + 1)] = T[i % (plus + 1)] * 10 + v[i];
            }
            Min = T.into_iter().sum();
        }
    }
    println!("{} {}", Max, Min);
}