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
        if let None = list1 {
            return list2;
        }
        if let None = list2 {
            return list1;
        }

        let merge_list = ListNode::new(0);
        let mut tail = merge_list;

        while list1.is_some() && list2.is_some() {
            let list1_val = list1.unwrap().val;
            let list2_val = list2.unwrap().val;

            if list1_val < list2_val {
                tail.next = 
            }
        }

        merge_list
    }
}
