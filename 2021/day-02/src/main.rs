use std::io::BufReader;
use std::io::prelude::*;
use std::fs::File;
use std::path::Path;

fn get_input(filename: impl AsRef<Path>) -> Vec<String> {
    let f = File::open(filename).expect("unable to open file");
    let f = BufReader::new(f);
    return f.lines().map(|x| x.expect("")).collect();
}

fn parse(line: &String) -> [i32; 2] {
    let vals: Vec<&str> = line.split(" ").collect();
    let command = vals[0];
    let val = vals[1].parse::<i32>().expect("unable to parse");
    match command.as_ref() {
        "forward" => [0, val],
        "up"      => [-val, 0],
        "down"    => [val, 0],
        _         => [0, 0]
    }
}

fn problem_1(input: &Vec<String>) {
    let answer = input.iter()
        .map(parse)
        .fold([0,0], |acc, curr| [acc[0] + curr[0], acc[1] + curr[1]]);
    println!("{}", answer[0] * answer[1]);
}

fn problem_2(input: &Vec<String>) {
    // [ depth , horizonal , aim ]
    let answer = input.iter()
        .map(parse)
        .fold([0,0,0], |acc, curr|
            if curr[1] != 0 {
                [acc[0] + acc[2] * curr[1], acc[1] + curr[1], acc[2]]
            } else {
                [acc[0], acc[1], acc[2] + curr[0]]
            });
    println!("{}", answer[0] * answer[1]);
}

fn main() {
    let input = get_input("input.txt");
    problem_1(&input);
    problem_2(&input);
}
