import Foundation

class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var low = 0
        var high = nums.count - 1

        while low <= high {
            var mid = low + (high - low) / 2
            if nums[mid] < target {
                low = mid + 1
            } else if nums[mid] > target {
                high = mid - 1
            } else {
                return mid
            }
        }
        return low
    }
}
