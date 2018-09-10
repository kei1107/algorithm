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
 <url:https://yukicoder.me/problems/no/193>
 問題文============================================================
 =================================================================
 解説=============================================================
 全ての開始点から全探索
 ================================================================
 */

fn get_value(S:&str) -> i32{
    let mut ret = 0;
    let L = S.len();
    let S = S.as_bytes();
    if S[0 as usize] == '+' as u8 || S[0 as usize] == '-' as u8 || S[L-1] == '+' as u8 || S[L-1] == '-' as u8 {return i32::min_value();}

    let mut plus = true;
    let mut now = 0;
    for i in 0..L{
        if S[i] == '+' as u8 || S[i] == '-' as u8{
            if plus{
                ret += now;
            }else{
                ret -= now;
            }
            if S[i] =='+' as u8{
                plus = true;
            }else{
                plus = false;
            }
            now = 0;
        }else{
            now *= 10;
            now += S[i] as i32 - '0' as i32;
        }
    }
    if plus{
        ret += now;
    }else{
        ret -= now;
    }

    return ret;
}
fn main(){
    input!(S:String);
    let Len = S.len();
    let S:String = S.repeat(2);

    let mut ans = i32::min_value();
    for i in 0..Len{
        let T = S.clone();
        ans = max(ans,get_value(&T[i..i+Len].to_string()));
    }
    println!("{}",ans);
}