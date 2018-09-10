#![allow(unused_mut, non_snake_case, unused_macros,unused_imports)]
use std::cmp::{max, min, Ordering};
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
 <url:https://yukicoder.me/problems/no/198>
 問題文============================================================
 =================================================================
 解説=============================================================

 3分探索して全体をどの数字にすればいいのかを探索すれば良い
 ================================================================
 */

fn main() {
    input! {B:i64,N:i64,C:[i64;N]}
    let B: i64 = B;
    let N: i64 = N;
    let C: Vec<i64> = C;

    let mut l: i64 = 0;
    let tmp: i64 = C.iter().sum();
    let mut r: i64 = (tmp + B) / N;
    while r - l > 2 {
        let ml = (r - l) / 3 + l;
        let mr = (r - l) * 2 / 3 + l;

        let cntl: i64 = C.iter().map(|&v| (v - ml).abs()).sum();
        let cntr: i64 = C.iter().map(|&v| (v - mr).abs()).sum();

        if cntl < cntr {
            r = mr;
        } else {
            l = ml;
        }
    }
    let mut ans = i64::max_value();
    for c in l..r+1{
        let cnt:i64 = C.iter().map(|&v| (v - c).abs()).sum();
        ans = min(ans,cnt);
        //println!{"{} {}",c,cnt}
    }
    println!("{}", ans);
}