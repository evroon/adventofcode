extern crate chrono;
extern crate itertools;
extern crate regex;

pub mod common;
pub mod day01;

pub fn get_impl(day: u32) -> Box<dyn common::Solution> {
    match day {
        1 => Box::new(day01::Day01::new()),
        val => panic!("Unimplemented day {}", val),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_impl() {
        // Verify that we can load all days
        let last_implemented = 1;
        for d in 1..=last_implemented {
            get_impl(d);
        }
    }
}
