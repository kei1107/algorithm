#![allow(unused_mut, non_snake_case, unused_macros, unused_imports)]

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
 <url:https://beta.atcoder.jp/contests/abc001/tasks/abc001_3>
 問題文============================================================
 =================================================================
 解説=============================================================
 気合い
 ================================================================
 */
fn main() {
    input!(Deg:usize,Dis:usize);
    let mut Deg: usize = Deg;
    Deg = (Deg * 10 + 1125) / 2250;
    let Dir = match Deg {
        0 => "N",
        1 => "NNE",
        2 => "NE",
        3 => "ENE",
        4 => "E",
        5 => "ESE",
        6 => "SE",
        7 => "SSE",
        8 => "S",
        9 => "SSW",
        10 => "SW",
        11 => "WSW",
        12 => "W",
        13 => "WNW",
        14 => "NW",
        15 => "NNW",
        _ => "N"
    };
    let W = if Dis < 15 { 0 } else if Dis < 93 { 1 } else if Dis < 201 { 2 } else if Dis < 327 { 3 } else if Dis < 477 { 4 } else if Dis < 645 { 5 } else if Dis < 831 { 6 } else if Dis < 1029 { 7 } else if Dis < 1245 { 8 } else if Dis < 1467 { 9 } else if Dis < 1707 { 10 } else if Dis < 1959 { 11 } else { 12 };
    if W==0{
        println!("C {}",W);
    }else{
        println!("{} {}",Dir,W);
    }
}