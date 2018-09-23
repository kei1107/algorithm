#![allow(unused_mut, non_snake_case,unused_imports)]
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
 <url:https://yukicoder.me/problems/no/232>
 問題文============================================================
 =================================================================
 解説=============================================================
ごちゃごちゃやって色々と辻褄を合わせればいい
 ================================================================
 */
fn main(){
    input!(T:i64,B:i64,A:i64);
    let mut T:i64 = T;
    let mut A:i64 = A;
    let mut B:i64 = B;
    if T<A||T<B||T+A+B==1{
        println!("NO");
        return;
    }
    println!("YES");
    while T!=0{
        if A < T-1{
            print!("<");
            A+=1;
        }else if A!=0{
            print!(">");
            A-=1;
        }
        if B%2 == T%2{
            if B < T-1{
                print!("v");
                B+=1;
            }else if B!=0{
                print!("^");
                B-=1;
            }
        }
        println!("");
        T-=1;
    }
}