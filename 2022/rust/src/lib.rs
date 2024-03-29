extern crate chrono;
extern crate itertools;
extern crate regex;

pub mod common;

pub fn get_impl(day: u32) -> Box<dyn common::Solution> {
    match day {
        1 => panic!("Unimplemented day 1"),
        val => panic!("Unimplemented day {val}"),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_impl() {
        // Verify that we can load all days
        let last_implemented = 0;
        for d in 1..=last_implemented {
            get_impl(d);
        }
    }
}
