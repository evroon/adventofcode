use std::io::{self};

use crate::common;

#[derive(Default)]
pub struct Day01 {}

impl Day01 {
    pub fn new() -> Day01 {
        Default::default()
    }
}

impl common::Solution for Day01 {
    fn part1(&mut self, input: &mut dyn io::Read) -> String {
        let mut buffer = String::new();
        input
            .read_to_string(&mut buffer)
            .expect("Could not read buffer");
        buffer
    }

    fn part2(&mut self, input: &mut dyn io::Read) -> String {
        let mut buffer = String::new();
        input
            .read_to_string(&mut buffer)
            .expect("Could not read buffer");
        buffer
    }
}
