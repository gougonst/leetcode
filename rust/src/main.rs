use rust::Solution;

fn main() {
    let s = String::from("([])");
    let ans = Solution::is_valid(s);
    println!("{:?}", ans);
}
