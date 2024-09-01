use std::collections::HashMap;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}

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

    // 21-MergeTwoSortedLists
    pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None, 
            (Some(list), None) | (None, Some(list)) => Some(list), 
            (Some(mut first), Some(mut second)) => {
                if first.val < second.val {
                    first.next = Self::merge_two_lists(first.next, Some(second));
                    Some(first)
                } else {
                    second.next = Self::merge_two_lists(second.next, Some(first));
                    Some(second)
                }
            }
        }
    }

    // 121 - Best time to buy and sell stock
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut buy = 0;
        let mut ans = 0;
        for price in prices.into_iter().skip(1) {
            ans = ans.max(price - buy);
            buy = buy.min(price);
        }
        ans
    }

    // 125 - Valid Palindrome
    pub fn is_palindrome(s: String) -> bool {
        let iter = s
            .chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase());

        iter.clone().eq(iter.rev())
    }
}
