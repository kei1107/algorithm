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
 <url:https://beta.atcoder.jp/contests/abc109/tasks/abc109_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 上の行から下の行に向けて順番に、奇数枚のマスのコインを下に移動
一番下の行では左から右に向けて奇数枚のマスのコインを右のマスに移動
 ================================================================
 */
fn main(){
    input!{
    H:usize,
    W:usize,
    a:[[usize;W];H]
    }
    let mut query:usize = 0;
    let mut ans:Vec<Vec<usize>> = Vec::new();
    for i in 0..H-1{
        for j in 0..W{
            if a[i][j]%2 == 1{
                a[i+1][j] += 1;
                a[i][j] -= 1;
                query += 1;
                ans.push(vec![i + 1, j + 1, i + 1 + 1, j + 1]);
            }
        }
    }
    let i = H-1;
    for j in 0..W-1{
        if a[i][j]%2 == 1{
            a[i][j+1] += 1;
            a[i][j] -= 1;
            query += 1;
            ans.push(vec![i + 1, j + 1, i + 1, j + 1 + 1]);
        }
    }
    println!("{}",query);
    for v in ans{
        println!("{} {} {} {}",v[0],v[1],v[2],v[3]);
    }
}