
public class Recursion1{

			
	public static String allStar(String str, int n){
		if(n == str.length()-1){
			return String.valueOf(str.charAt(n));	
		}
		
		return str.charAt(n) + "*" + allStar(str, n+1);
	}

	public static boolean array220(int[] nums, int index){
	if(index == nums.length-1 || nums.length == 0) return false;

	if(nums[index]*10 == nums[index+1]) return true;

	else return false || array220(nums, index+1);

	}



	public static void main (String args[]){

	System.out.println("''All Star''");
	System.out.println("Input: helloworld");
	System.out.println("Output: " + allStar("helloworld", 0) + "\n");

	System.out.println("''Array220''");
	System.out.println("Input: [1, 2, 3, 4, 5, 50]");
	
	int[] nums = {1, 2, 3, 4, 5, 50};
	
	System.out.println("Output: " + Boolean.toString(array220(nums, 0)));

	}


}
