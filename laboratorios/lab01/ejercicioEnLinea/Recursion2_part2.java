public boolean groupNoAdj(int start, int[] nums, int target) {
  return (start >= nums.length) ? (target == 0) : (groupNoAdj(start+2, nums, target-nums[start]) || groupNoAdj(start+1, nums, target));
}
