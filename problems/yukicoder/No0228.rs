#![allow(unused_mut, non_snake_case, unused_macros, unused_imports)]
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
 <url:https://yukicoder.me/problems/no/228>
 問題文============================================================
 =================================================================
 解説=============================================================
 一度スライドしたパネルは動かすことができないので、
 復元作業を行うときの作業は一意に定まる。

 復元作業をできるだけ行い、最終盤面が初期盤面になっているかどうかを調べる
 ================================================================
 */
fn main() {
    input! {a:[[i32;4];4]}
    let mut a:Vec<Vec<i32>> = a;
    let dir:Vec<i32> = vec![1, 0, -1, 0];
    loop {
        let mut update = false;
        'check: for i in 0..4{
            for j in 0..4{
                if a[i as usize][j as usize] != 0 {
                    continue;
                }
                let now = i*4 + j + 1;
                for k in 0..4 as usize{
                    let ny:i32= i + dir[k];
                    let nx:i32 = j + dir[k^1];
                    if ny < 0 || ny >= 4||nx < 0||nx >= 4{
                        continue;
                    }
                    if a[ny as usize][nx as usize] == now{
                        update = true;
                        let t = a[i as usize][j as usize].clone();
                        a[i as usize][j as usize] = a[ny as usize][nx as usize].clone();
                        a[ny as usize][nx as usize] = t;
                        break 'check;
                    }
                }
                break 'check;
            }
        }
        if update {
            continue;
        }
        break;
    }
    let mut ok = true;
    for i in 0..4{
        for j in 0..4{
            if a[i as usize][j as usize] as usize == (i*4+j+1){
                continue;
            }
            if i == 3 && j == 3{
                continue;
            }
            ok = false;
        }
    }
    println!("{}", if ok {"Yes"} else {"No"});
}