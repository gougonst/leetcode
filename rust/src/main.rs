use rust::Solution;

fn main() {
    let v = vec![7, 6, 4, 3, 1];
    let ans = Solution::max_profit(v);
    println!("{:?}", ans);
}
