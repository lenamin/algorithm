/**
 * The knows API is defined in the parent class VersionControl.
 *     func isBadVersion(_ version: Int) -> Bool{}
 */

import Foundation 

class Solution: VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var low = 1
        var high = n
        
        while low < high {
            var mid = low + (high - low) / 2
            if !isBadVersion(mid) { // false가 나오면 mid 이후를 찾음               

                low = mid + 1
            } else { // true가 나오면 언제 처음 나왔는지 찾아야 하니까 mid가 high가 되겠지 
                high = mid
            }
        }
        return low
    }
}
