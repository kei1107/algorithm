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
 <url:https://beta.atcoder.jp/contests/arc005/tasks/arc005_2>
 問題文============================================================
 =================================================================
 解説=============================================================
 がんばる
 ================================================================
 */
fn main(){
    input!(x:usize1,y:usize1,W:chars,cs:[chars;9]);
    let W:Vec<char> = W;
    let mut dx:i32 = match W.first().unwrap() {
        &'R' => 1,
        &'L' => -1,
        _ => 0,
    };
    let mut dy:i32 = match W.last().unwrap() {
        &'D' => 1,
        &'U' => -1,
        _ => 0
    };

    let mut nx:i32 = x as i32;
    let mut ny:i32 = y as i32;
    let mut ans = 0;
    for _ in 0..4{
        ans = ans*10 + cs[ny as usize][nx as usize] as i32 - '0' as i32;
        nx += dx;
        ny += dy;

        if ny < 0 || ny >= 9 || nx < 0|| nx >= 9{
            let (prex,prey) = (dx,dy);
            if ny < 0 || ny >= 9{
                dy *= -1;
            }
            if nx < 0 || nx >= 9{
                dx *= -1;
            }
            nx -= prex;
            ny -= prey;
            nx += dx;
            ny += dy;
        }
    }
    println!("{:04}",ans);
}