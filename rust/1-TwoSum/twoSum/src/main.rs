use std::collections::HashMap;

struct Solution;

impl Solution {
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
}

fn main() {
    let nums = vec![3, 2, 4];
    let target = 6;
    let ans: Vec<i32> = Solution::two_sum(nums, target);
    println!("{:?}", ans);
}
