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
 <url:https://yukicoder.me/problems/no/721>
 問題文============================================================
 =================================================================
 解説=============================================================
 ウルウ年だけ注意
 ================================================================
 */


fn twoDay(mut YYYY:i32,mut MM:i32,mut DD:i32) -> (i32,i32,i32){
    let mut DAY:Vec<i32>  = vec![31,28,31,30,31,30,31,31,30,31,30,31];
    DD += 2;
    if (YYYY % 4 == 0 &&YYYY%100!=0)|| YYYY%400==0{DAY[1] = 29};
    if DAY[(MM-1) as usize] < DD{
        DD -= DAY[(MM-1) as usize];
        MM+=1;
    }
    if MM==13{
        MM = 1;
        YYYY+=1;
    }
    (YYYY,MM,DD)
}
fn main(){
    input!(input:String);
    let mut input:String = input;
    let vecin:Vec<&str> = input.split("/").collect();
    let mut YYYY:i32 = vecin[0].parse().unwrap();
    let mut MM:i32 = vecin[1].parse().unwrap();
    let mut DD:i32 = vecin[2].parse().unwrap();
    let (Y,M,D) = twoDay(YYYY,MM, DD);
    println!("{:04}/{:02}/{:02}",Y,M,D);
}