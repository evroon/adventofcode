extern crate aoc_2018;
extern crate chrono;

use std::fs;
use std::io;
use std::time::Instant;

use aoc_2018::get_impl;
use clap::Parser;

/// Run AoC solutions
#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
struct Args {
    /// Number of the day to execute
    #[arg(short, long)]
    day: u32,

    /// Run part 2 instead of part 1
    #[arg(short, long)]
    part2: bool,

    /// Use stdin input instead of file
    #[arg(short, long)]
    stdin: bool,

    /// Print the time for the result
    #[arg(short, long, default_value = "true")]
    time: bool,
}

fn main() {
    let args = Args::parse();

    let input_path = "inputs/day{:0>2}.txt";
    println!(input_path, args.day);

    let mut implementation = get_impl(args.day);
    let mut data: Box<dyn io::Read> = match args.stdin {
        true => Box::new(io::stdin()),
        false => Box::new(fs::File::open(format!(input_path, args.day)).unwrap()),
    };

    let begin = Instant::now();
    let result = match args.part2 {
        true => implementation.part2(&mut data),
        false => implementation.part1(&mut data),
    };

    if args.time {
        eprintln!("Duration: {:?}", Instant::now().duration_since(begin));
    }

    println!("{}", result);
}
