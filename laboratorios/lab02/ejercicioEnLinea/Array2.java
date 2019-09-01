public class Array2{


	public static void main(String args[]){






	}


	public boolean isEverywhere(int[] nums, int val) {

  		if(nums.length == 0 || nums.length == 1) return true;

		if(nums[0] == val){

			for(int i = 0; i < nums.length; i = i + 2){

      			if(nums[i] != val) return false;

    			}

    			return true;

  		} else if(nums[1] == val){

   			for(int i = 1; i < nums.length; i = i + 2){

      			if(nums[i] != val) return false;

    			}

   			 return true;

 		 }

		return false;

	}


	public int[] zeroFront(int[] nums) {
  
  		int[] arr = new int[nums.length];

	       	int k = 0;
  
		for(int i = 0; i < nums.length; i++) if(nums[i] == 0){
			arr[k] = 0;
			k++;
    
		}
  
		for(int i = 0; i < nums.length; i++) if(nums[i] != 0){
			arr[k] = nums[i];
			k++;
		}

  		return arr;
  
	}



	public int bigDiff(int[] nums) {
  		int max = nums[0];
  		int min = nums[0];
  
  		for(int i = 0; i < nums.length; i++)
  		{
    			max = Math.max(max, nums[i]);
    			min = Math.min(min, nums[i]);
  		}
  		return max - min;
	}
	
	public boolean has12(int[] nums) {
  		boolean one = false;
 		boolean two = false;
  		for(int i=0; i<nums.length; i++){
    			if(nums[i] == 1){
     				one = true;
     				for(int j = i; j<nums.length; j++){
        				if(nums[j] == 2) two = true;
      				}
    			}
  		}
  		return (one && two);
	}


	
	public String[] fizzBuzz(int start, int end) {
  		String[] array = new String[end - start];
  		for(int i = start; i<end; i++){
    			if(i%3 == 0 && i%5 == 0) array[i-start] = "FizzBuzz";
    			else if(i%3 == 0) array[i-start] = "Fizz";
    			else if(i%5 == 0) array[i-start] = "Buzz";
    			else array[i-start] = String.valueOf(i);
  		}
  		return array;
	}

}



