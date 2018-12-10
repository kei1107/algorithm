
// 約数列挙
fn get_divisors(n: u64) -> Vec<u64> {
let mut ret = Vec::<u64>::new();
let mut i = 1;
while i * i <= n {
    if n % i == 0 {
        ret.push(i);
        if n != i * i { ret.push(n / i); }
    }
    i += 1;
}
ret.sort();
ret
}
 let divisor:Vec<_> = (1..(N as f64).sqrt().ceil() as i64 + 1).filter(|&v| N%v==0).collect();
 

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

// 素数列挙
fn prime_enum(n: u64) -> Vec<u64> {
    let mut n = n;
    let mut ret = Vec::<u64>::new();
    let mut i = 2;
    while i * i <= n {
        if n % i == 0 {
            ret.push(i);
        }
        while n % i == 0 { n /= i; }
        i += 1;
    }
    if n > 1 { ret.push(n); }
    ret.sort();
    ret
}
