#![feature(iter_zip)]
#![feature(iter_advance_by)]

use std::io::BufReader;
use std::io::prelude::*;
use std::fs::File;
use std::path::Path;
use std::iter::zip;

fn solve_1(vals: Vec<u32>) -> u32 {
    let mut count = 0;
    let mut last = u32::MAX;
    for next in vals {
        if next > last {
            count += 1;
        }
        last = next;
    }
    return count;
}

fn get_input(filename: impl AsRef<Path>) -> Vec<u32> {
    let f = File::open(filename).expect("unable to open file");
    let f = BufReader::new(f);
    return f
        .lines()
        .map(|l| l.expect("unable to read line").parse::<u32>().expect("unable to parse"))
        .collect();
}

fn main() {

    let input = get_input("input.txt");
    let mut it = input.iter();
    it.advance_by(1);
    let count = zip(input.iter(), it)
        .rfold(0, |acc, (a, b)| if a < b { acc + 1 } else { acc });

    println!("{}", count);
}
