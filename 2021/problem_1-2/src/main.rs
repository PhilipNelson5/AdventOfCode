#![feature(iter_zip)]
#![feature(iter_advance_by)]

use std::io::BufReader;
use std::io::prelude::*;
use std::fs::File;
use std::path::Path;
use std::iter::zip;

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
    let chunks: Vec<u32> = input.windows(3).map(|x| x.iter().sum()).collect();
    let mut it = chunks.iter();
    it.advance_by(1);
    let count = zip(chunks.iter(), it)
        .rfold(0, |acc, (a, b)| if a < b { acc + 1 } else { acc });

    println!("{}", count);
}
