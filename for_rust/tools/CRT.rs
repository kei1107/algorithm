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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

// CRT
fn _mod(a:i64,m:i64) -> i64 { return (a%m + m)%m;}
// ref:https://github.com/kgtkr/procon-lib-rs/blob/master/src/gcd.rs
//拡張ユークリッド(参照版)
pub fn extgcd_ref(a: i64, b: i64, x: &mut i64, y: &mut i64) -> i64 {
    let mut d = a;
    if b != 0 {
        d = extgcd_ref(b, a % b, y, x); *y -= (a / b) * *x;
    } else {
        *x = 1; *y = 0;
    }
    return d;
}

//拡張ユークリッド
//(gcd(a,b),x,y)
pub fn extgcd(a: i64, b: i64) -> (i64, i64, i64) {
    let mut x = 0;
    let mut y = 0;
    let gcd = extgcd_ref(a, b, &mut x, &mut y);
    return (gcd, x, y);
}


fn CRT(b:&[i64],m:&[i64]) -> (i64,i64){
    let mut r = 0_i64;
    let mut M = 1_i64;
    for i in 0..b.len(){
        let (d,p,_) = extgcd(M,m[i]);
        if(b[i]-r)%d != 0 { return (0_i64,-1_i64)}
        let tmp = (b[i]-r)/d*p%(m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return (_mod(r,M),M);
}
fn main(){
    input!(b:[i64;3]);
    let m:Vec<i64> = vec![17,107,1000000007];
    let (a,_) = CRT(&b,&m);
    println!("{}",a);
}