package practice;
import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;

// 배열을 입력받아 합으로 0을 만들 수 있는 3개의 엘리먼트를 출력하라.
/**
 * 입력 : num = [-1, 0, 1, 2, -1, -5]
 * 출력 : [
 *          [-1, 0, 1],
 *          [-1, -1, 2],
 *       ]
 * **/
public class ThreeSum {
    public static List<List<Integer>> threeSumWithBruteForce (int[] nums) {
        List<List<Integer>> results = new LinkedList<>();
        Arrays.sort(nums);

        // n^3 반복
        for (int i = 0; i < nums.length - 2; i++) {
            // 중복된 값 건너뛰기. 이 처리를 하지 않으면 같은 값이 두 번 나옴.
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            for (int j = i + 1; j < nums.length - 1; j++) {
                // 중복된 값 건너뛰기
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;

                for (int k = j + 1; k < nums.length; k++) {
                    // 중복된 값 건너뛰기
                    if (k > j + 1 && nums[k] == nums[k - 1]) 
                        continue;

                    if (nums[i] + nums[j] + nums[k] == 0) 
                        results.add(Arrays.asList(nums[i], nums[j], nums[k]));
                }
            }
        }
        return results;
    }
}
