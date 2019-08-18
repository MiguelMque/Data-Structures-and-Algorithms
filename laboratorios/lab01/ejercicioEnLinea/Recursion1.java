
public class Recursion1{

			
	public static String allStar(String str, int n){
		if(n == str.length()-1){
			return String.valueOf(str.charAt(n));	
		}
		
		return str.charAt(n) + "*" + allStar(str, n+1);
	}





	public static void main (String args[]){

	System.out.println("''All Star''");
	System.out.println("Input: helloworld");
	System.out.println("Output: " + allStar("helloworld", 0));


	}


}
