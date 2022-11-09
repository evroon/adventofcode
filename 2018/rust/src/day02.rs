use std::collections::HashSet;
use std::io;
use std::io::prelude::*;

use crate::common;

#[derive(Default)]
pub struct Day02 {}

impl Day02 {
    pub fn new() -> Day02 {
        Default::default()
    }
}

impl common::Solution for Day02 {
    fn part1(&mut self, input: &mut dyn io::Read) -> String {
        let reader = io::BufReader::new(input);

        let sum: i32 = reader
            .lines()
            .map(|x| x.unwrap().parse::<i32>().unwrap())
            .sum();

        sum.to_string()
    }

    fn part2(&mut self, input: &mut dyn io::Read) -> String {
        let reader = io::BufReader::new(input);
        let mut freqs = HashSet::new();
        freqs.insert(0);

        let mut sum = 0;
        let nums: Vec<i32> = reader
            .lines()
            .map(|x| x.unwrap().parse().unwrap())
            .collect();
        loop {
            for amount in &nums {
                sum += amount;
                if freqs.contains(&sum) {
                    return sum.to_string();
                } else {
                    freqs.insert(sum);
                }
            }
        }
    }
}
