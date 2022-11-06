use std::io;

/// Solution trait
///
/// Every day's solution should implement this function so that it can
/// be easily run from the main program.
pub trait Solution {
    /// Solve the first part of the day
    fn part1(&mut self, input: &mut dyn io::Read) -> String;

    /// Solve the second part of the day
    fn part2(&mut self, input: &mut dyn io::Read) -> String;
}
