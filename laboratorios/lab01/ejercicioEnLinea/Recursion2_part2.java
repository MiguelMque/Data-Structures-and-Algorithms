//CodingBat Recursion 2. groupNoAdj
public boolean groupNoAdj(int start, int[] nums, int target) {
  return (start >= nums.length) ? (target == 0) : (groupNoAdj(start+2, nums, target-nums[start]) || groupNoAdj(start+1, nums, target));
}
//CodingBat Recursion 2. groupSumClump
public boolean groupSumClump(int start, int[] nums, int target) {
  if(start >= nums.length) return (target == 0);
  int sum = 0;
  int clump = start;
  while(clump < nums.length && nums[start] == nums[clump]){
    sum += nums[start];
    clump++;
  }
  return groupSumClump(clump, nums, target) || groupSumClump(clump, nums, target-sum);
}
//CodingBat Recursion 2. splitArray
public boolean splitArray(int[] nums) {
  return splitArrayAux(0, 0, nums, 0);
}
private boolean splitArrayAux(int start, int sum1, int[] nums, int sum2){
  if(start >= nums.length) return (sum1 == sum2);
  return splitArrayAux(start+1, sum1+nums[start], nums, sum2) || splitArrayAux(start+1, sum1, nums, sum2+nums[start]);
}
