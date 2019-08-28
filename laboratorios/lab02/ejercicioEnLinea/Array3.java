public class Array3{

	public static void main(String args[]){

	}



	public int[] fix34(int[] nums) {

		int[] arr = new int[nums.length];

		int counter = 0;

		for(int i = 0; i < nums.length; i++){
			if(nums[i] == 3){
				arr[i] = 3;
				if(i < nums.length-1){
					arr[i+1] = 4;
					counter = counter + 2;
				}
			}
		}

		int[] gar = new int[nums.length-counter];

		counter = 0;
		for(int i = 0; i < nums.length; i++) if(nums[i] != 3 && nums[i] != 4){
			gar[counter] = nums[i];
			counter++;
		} 


		counter = 0;


		for(int i = 0; i < nums.length; i++){

			if(arr[i] == 0){
				arr[i] = gar[counter];
				counter++;

			}


		}

		return arr;


	}


	public int countClumps(int[] nums) {

		if(nums.length == 0) return 0;

		int x = nums[0];
		boolean ad = true;
		int c = 0;



		for(int i = 0; i < nums.length-1; i++){

			if(x==nums[i+1] && ad){
				c++;
				ad = false;

			} else if(x!=nums[i+1]) {
				x = nums[i+1];
				ad = true;

			}



		}
		return c;

	}


	public int[] squareUp(int n) {
		int[] arr = new int[n*n];
		int m = n;
		int x = 1;

		for(int i = n*n-1; i >= 0; i--){

			if((i+1)%n == 0 && i!=n*n-1){
				m--;
				x = 1;
			}

			if(x > m){

				arr[i] = 0;

			} else {

				arr[i] = x;
				x++;

			}

		}

		return arr;

	}

}
