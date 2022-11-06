extern crate aoc_2022;
extern crate chrono;
#[macro_use]
extern crate clap;

use std::fs;
use std::io;
use std::time::Instant;

use clap::Arg;

use aoc_2022::get_impl;

fn main() {
    let matches = app_from_crate!()
        .arg(
            Arg::with_name("day")
                .value_name("DAY")
                .help("Number of the day to execute")
                .required(true)
                .takes_value(true),
        )
        .arg(
            Arg::with_name("part2")
                .short("2")
                .help("Run part 2 instead of part 1")
                .long("part2"),
        )
        .arg(
            Arg::with_name("stdin")
                .short("i")
                .long("stdin")
                .help("Use stdin input instead of file"),
        )
        .arg(
            Arg::with_name("time")
                .short("t")
                .long("time")
                .help("Print the time for the result")
                .default_value("true"),
        )
        .get_matches();

    let mut implementation = get_impl(value_t_or_exit!(matches, "day", u32));
    let mut data: Box<dyn io::Read> = match matches.is_present("stdin") {
        true => Box::new(io::stdin()),
        false => Box::new(
            fs::File::open(format!(
                "inputs/{:0>2}.txt",
                matches.value_of("day").unwrap()
            ))
            .unwrap(),
        ),
    };

    let begin = Instant::now();
    let result = match matches.is_present("part2") {
        true => implementation.part2(&mut data),
        false => implementation.part1(&mut data),
    };

    if matches.is_present("time") {
        eprintln!("Duration: {:?}", Instant::now().duration_since(begin));
    }

    println!("{}", result);
}
