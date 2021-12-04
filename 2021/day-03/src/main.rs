#![feature(iter_zip)]

use std::io::BufReader;
use std::io::prelude::*;
use std::fs::File;
use std::path::Path;
use std::iter::zip;

fn get_input(filename: impl AsRef<Path>) -> Vec<String> {
    let f = File::open(filename).expect("unable to open file");
    let f = BufReader::new(f);
    return f.lines().map(|x| x.expect("")).collect();
}

fn bits_to_u32(input: &Vec<bool>) -> u32 {
    return input.iter().rev()
        .enumerate()
        .fold(0u32, |acc, (i, b)| if *b { acc + 2u32.pow(i as u32) } else { acc });
}

fn get_gamma_bits(input: &Vec<String>) -> Vec<bool> {
    let n_bits = input[0].len();
    let n_vals = input.len() as u32;
    return input.iter()
        .fold(vec![0;n_bits], |acc, curr|
                zip(acc.iter(),
                    curr.chars().map(|x| x.to_digit(10).expect("unable to parse")))
                .map(|(a, b)| a + b)
                .collect())
        .iter()
        .map(|x| if x > &(n_vals/2) {true} else {false})
        .collect();
}

fn problem_1(input: &Vec<String>) {
    let g_bits = get_gamma_bits(&input);
    let e_bits:Vec<bool> = g_bits.iter().map(|x| !x).collect();
    let g = bits_to_u32(&g_bits);
    let e = bits_to_u32(&e_bits);
    println!("{}", g * e);
}

fn main() {
    let input = get_input("input.txt");
    problem_1(&input);
}
