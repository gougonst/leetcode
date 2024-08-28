use std::collections::HashMap;

pub struct Solution;

impl Solution {
    // 1-TwoSum
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hm = HashMap::with_capacity(nums.len());
        for (i, &num) in nums.iter().enumerate() {
            match hm.get(&num) {
                Some(&j) => return vec![i as i32, j as i32], 
                None => {
                    hm.insert(target - num, i);
                }
            }
        }
        unreachable!();
    }

    // 20-ValidParentheses
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        let table = HashMap::from([
            (')', '('), 
            (']', '['), 
            ('}', '{'), 
        ]);
        for c in s.chars() {
            match table.get(&c) {
                Some(pair) => {
                    if stack.last().is_some_and(|last: &char| last == pair) {
                        stack.pop();
                    } else {
                        return false;
                    }
                }, 
                None => {
                    stack.push(c);
                }
            }
        }
        stack.is_empty()
    }
}
