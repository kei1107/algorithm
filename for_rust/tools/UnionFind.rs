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


#[derive(PartialEq,Debug,Clone)]
pub struct UnionFind(Vec<i32>);
impl UnionFind{
    pub fn new(size:usize) -> UnionFind{
        let V = vec![-1;size];
        UnionFind(V)
    }

    pub fn root(&mut self,x:i32) -> i32{
        if self.0[x as usize] < 0{
            return x;
        }else{
            let v = self.0[x as usize];
            self.0[x as usize] = self.root(v);
            return self.0[x as usize];
        }
    }

    pub fn unionSet(&mut self,x:i32,y:i32) -> bool{
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x != y {
            if self.0[y as usize] < self.0[x as usize] { swap(& mut x,& mut y); }
            self.0[x as usize] += self.0[y as usize];
            self.0[y as usize] = x;
        }
        return x!=y;
    }
    pub fn findSet(&mut self,x:i32,y:i32) -> bool{
        return self.root(x) == self.root(y);
    }
    pub fn size(&mut self,x:i32) -> i32{
        let r = self.root(x);
        return -self.0[r as usize];
    }

}
fn main(){
    input!(N:usize,M:usize,Q:[(usize1,usize1);M]);
    let Q:Vec<(usize,usize)> = Q;
    let mut UF = UnionFind::new(N as usize);
    for (a,b) in Q{
        UF.unionSet(a as i32,b as i32);
    }
    let N:usize = N;
    let mut V:HashSet<i32> = (0..N).into_iter().map(|i| UF.root(i as i32)).collect();
    println!("{}",V.len()-1);
}