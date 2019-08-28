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



	//Inserta el demás código aquí Pablo

}



