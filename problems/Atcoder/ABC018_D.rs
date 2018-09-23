#![allow(unused_mut, non_snake_case, unused_imports)]
use std::iter;
use std::cmp::{max, min, Ordering};
use std::mem::{swap};
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
 <url:https://beta.atcoder.jp/contests/abc018/tasks/abc018_4>
 問題文============================================================
 =================================================================
 解説=============================================================
 c++での解説参照
 ================================================================
 */

fn next_combination(sub: i64) -> i64 {
    let x = sub & (-sub);
    let y = sub + x;
    (((sub & (!y)) / x) >> 1) | y
}

fn main() {
    input!(N:usize,M:usize,P:usize,Q:usize,R:usize,pair:[(usize1,usize1,usize);R]);
    let mut cost = vec![[0;30];30];
    for &(x,y,z) in &pair{ cost[x][y] = z; }
    let mut bit = (1<<P)-1;
    let mut ans = 0;
    while bit < (1<<N){
        let mut path_cost:Vec<i64> = iter::repeat(0).take(M).collect();
        for i in (0..N).filter(|&i| (bit>>i)&1 == 1) {
            for j in 0..M{
                path_cost[j] += cost[i][j] as i64;
            }
        }
        path_cost.sort_by_key(|&v| -v);
        let T:i64 = path_cost.into_iter().take(Q).sum();
        ans = max(ans,T);
        bit = next_combination(bit);
    }
    println!("{}",ans);

}