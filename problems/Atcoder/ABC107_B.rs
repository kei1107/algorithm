#![allow(unused_mut)]
#![allow(non_snake_case)]

//　高速 EOF要
//macro_rules! input {(source = $s:expr, $($r:tt)*) => {let mut iter = $s.split_whitespace();input_inner!{iter, $($r)*}};($($r:tt)*) => {let mut s = {use std::io::Read;let mut s = String::new();std::io::stdin().read_to_string(&mut s).unwrap();s};let mut iter = s.split_whitespace();input_inner!{iter, $($r)*}};}
//macro_rules! input_inner {($iter:expr) => {};($iter:expr, ) => {};($iter:expr, $var:ident : $t:tt $($r:tt)*) => {let $var = read_value!($iter, $t);input_inner!{$iter $($r)*}};}
//macro_rules! read_value {($iter:expr, ( $($t:tt),* )) => {( $(read_value!($iter, $t)),* )};($iter:expr, [ $t:tt ; $len:expr ]) => {(0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()};($iter:expr, chars) => {read_value!($iter, String).chars().collect::<Vec<char>>()};($iter:expr, usize1) => {read_value!($iter, usize) - 1};($iter:expr, $t:ty) => {$iter.next().unwrap().parse::<$t>().expect("Parse error")};}
// 低速 EOF不要
macro_rules! input {(source = $s:expr, $($r:tt)*) => {let mut iter = $s.split_whitespace();let mut next = || { iter.next().unwrap() };input_inner!{next, $($r)*}};($($r:tt)*) => {let stdin = std::io::stdin();let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));let mut next = move || -> String{bytes.by_ref().map(|r|r.unwrap() as char).skip_while(|c|c.is_whitespace()).take_while(|c|!c.is_whitespace()).collect()};input_inner!{next, $($r)*}};}
macro_rules! input_inner {($next:expr) => {};($next:expr, ) => {};($next:expr, $var:ident : $t:tt $($r:tt)*) => {let $var = read_value!($next, $t);input_inner!{$next $($r)*}};}
macro_rules! read_value {($next:expr, ( $($t:tt),* )) => {( $(read_value!($next, $t)),* )};($next:expr, [ $t:tt ; $len:expr ]) => {(0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()};($next:expr, chars) => {read_value!($next, String).chars().collect::<Vec<char>>()};($next:expr, usize1) => {read_value!($next, usize) - 1};($next:expr, $t:ty) => {$next().parse::<$t>().expect("Parse error")};}

/*
 <urlhttps://beta.atcoder.jp/contests/abc107/tasks/abc107_b>
 問題文============================================================
 =================================================================
 解説=============================================================

 一列・一行が全て白であるならば印をつけておき、
 あとで、その印がついている行or列を読み飛ばして出力すればよい
 ================================================================
 */

fn main() {
    input! {
    h: usize,
    w: usize,
    board: [chars; h],}

    let mut board: Vec<Vec<char>> = board;
    for i in { 0..h } {
        let mut ok = true;
        for j in { 0..w } {
            if board[i][j] == b'#' as char {
                ok = false;
                break;
            }
        }
        if !ok {
            continue;
        }
        for j in { 0..w } {
            board[i][j] = b'X' as char;
        }
    }

    for j in { 0..w } {
        let mut ok = true;
        for i in { 0..h } {
            if board[i][j] == b'#' as char{
                ok = false;
                break;
            }
        }
        if !ok {
            continue;
        }
        for i in { 0..h } {
            board[i][j] = b'X' as char;
        }
    }

    for i in {0..h}{
        let mut pri = false;
        for j in {0..w}{
            if board[i][j] == b'X' as char{
                continue
            }
            pri = true;
            print!("{}",board[i][j]);
        }
        if pri {
            print!("\n");
        }
    }
}