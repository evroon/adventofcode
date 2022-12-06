use std::io;
use std::io::prelude::*;

use crate::common;


#[derive(Default)]
pub struct Day01 {}

impl Day01 {
    pub fn new() -> Day01 {
        Default::default()
    }
}

pub struct LineIter<'a> {
    reader: io::BufReader<&'a mut dyn Read>,
    buffer: String,
}

impl<'a> LineIter<'a> {
    pub fn new(input: &'a mut dyn Read) -> Self {
        Self {
            reader: io::BufReader::new(input),
            buffer: String::new(),
        }
    }

    /// Get the next line, or None
    ///
    /// This is deliberately not an [Iterator] impl as those cannot hand out references to self.
    pub fn next(&mut self) -> Option<&str> {
        self.buffer.clear();

        if matches!(self.reader.read_line(&mut self.buffer), Ok(n) if n > 0) {
            Some(self.buffer.trim_end_matches('\n'))
        } else {
            None
        }
    }
}

impl common::Solution for Day01 {
    fn part1(&mut self, input: &mut dyn io::Read) -> String {
        let mut reader = LineIter::new(input);

        "".to_string()
    }

    fn part2(&mut self, input: &mut dyn io::Read) -> String {
        let mut buffer = String::new();
        input
            .read_to_string(&mut buffer)
            .expect("Could not read buffer");
        buffer
    }
}
