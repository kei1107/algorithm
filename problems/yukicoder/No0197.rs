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
 <url:https://yukicoder.me/problems/no/197>
 問題文============================================================
 =================================================================
 解説=============================================================

 前後でコインの数に変化があれば成功
 コインの数に変化がないのであれば、
  N = 0　であれば　単純な比較
  N = 1 であれば　シミュレーション
  N = 2以上であれば　どんな状態にでもできるので必ず失敗
 ================================================================
 */

fn solve() -> String{
    input!{
    S1 :chars,
    N:usize,
    S2:chars
    }
    let mut S1:Vec<char> = S1;
    let N:usize = N;
    let mut S2:Vec<char> = S2;

    let c1 = S1.iter().fold(0,|sum,c| sum + (*c=='o') as i32);
    let c2 = S2.iter().fold(0,|sum,c| sum + (*c=='o') as i32);
    if c1 != c2 {
        return "SUCCESS".to_string();
    }
    if N == 0{
        if S1 != S2{
            return "SUCCESS".to_string();
        }
    }else if N == 1{
        let mut S3 = S1.clone();
        let mut S4 = S1.clone();
        S3.swap(0,1);
        S4.swap(1,2);

        if S3 != S2 && S4 != S2{
            return "SUCCESS".to_string();
        }
    }
    "FAILURE".to_string()
}
fn main(){
    println!("{}",solve());
}