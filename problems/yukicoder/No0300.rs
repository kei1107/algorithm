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
 <url:https://yukicoder.me/problems/no/300>
 問題文============================================================
 =================================================================
 解説=============================================================
 素因数分解して素因数の数が奇数個のものを掛け合わせる`
 ================================================================
 */
// 素因数分解
fn prime_fact(n: u64) -> Vec<u64> {
    let mut n = n;
    let mut ret = Vec::<u64>::new();
    while n != 1 {
        if n == 2 || n == 3 {
            ret.push(n);
            n /= n;
            continue;
        }
        let mut prime_flag = false;
        let mut i = 2;
        while i * i <= n {
            if n % i == 0 {
                ret.push(i);
                n /= i;
                prime_flag = true;
                break;
            }
            i += 1;
        }
        if !prime_flag {
            ret.push(n);
            n /= n;
        }
    }
    ret
}
fn main() {
    input!(X:u64);
    let mut Y = 1;
    let mut Fact = prime_fact(X);
    let mut mp: HashMap<u64, u64> = HashMap::new();
    for fact in Fact {
        let count = mp.entry(fact).or_insert(0);
        *count += 1;
    }
    for (k,v) in mp{
        if v%2==1{
            Y*=k;
        }
    }
    println!("{}",Y);
}