import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class FontSize
{
	public int getPixelWidth(String sentence, int[] uppercase, int[] lowercase)
	{
		int width = 0;
		for(int i = 0 ; i < sentence.length() ; i++){
			if(sentence.charAt(i)==' '){
				width+=3;
			}
			else if(Character.isUpperCase(sentence.charAt(i))){
				width+=uppercase[sentence.charAt(i)-'A'];
			}
			else{
				width+=lowercase[sentence.charAt(i)-'a'];				
			}
			if(i!=sentence.length()-1)
				width++;
		}
		return width;
	}
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	private static boolean KawigiEdit_RunTest(int testNum, String p0, int[] p1, int[] p2, boolean hasAnswer, int p3) {
		System.out.print("Test " + testNum + ": [" + "\"" + p0 + "\"" + "," + "{");
		for (int i = 0; p1.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print(p1[i]);
		}
		System.out.print("}" + "," + "{");
		for (int i = 0; p2.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print(p2[i]);
		}
		System.out.print("}");
		System.out.println("]");
		FontSize obj;
		int answer;
		obj = new FontSize();
		long startTime = System.currentTimeMillis();
		answer = obj.getPixelWidth(p0, p1, p2);
		long endTime = System.currentTimeMillis();
		boolean res;
		res = true;
		System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
		if (hasAnswer) {
			System.out.println("Desired answer:");
			System.out.println("\t" + p3);
		}
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		if (hasAnswer) {
			res = answer == p3;
		}
		if (!res) {
			System.out.println("DOESN'T MATCH!!!!");
		} else if ((endTime - startTime) / 1000.0 >= 2) {
			System.out.println("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			System.out.println("Match :-)");
		} else {
			System.out.println("OK, but is it right?");
		}
		System.out.println("");
		return res;
	}
	public static void main(String[] args) {
		boolean all_right;
		all_right = true;
		
		String p0;
		int[] p1;
		int[] p2;
		int p3;
		
		// ----- test 0 -----
		p0 = "Dead Beef";
		p1 = new int[]{6,6,6,7,7,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
		p2 = new int[]{5,5,5,4,4,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
		p3 = 49;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = "Hello World";
		p1 = new int[]{7,8,8,8,7,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8};
		p2 = new int[]{5,6,6,6,5,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6};
		p3 = 74;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = "Hello World";
		p1 = new int[]{7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,7,7};
		p2 = new int[]{5,5,5,6,6,5,5,5,5,5,5,1,5,5,6,5,5,6,5,5,5,5,5,5,5,5};
		p3 = 63;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = "ThE qUiCk BrOwN fOx JuMpEd OvEr ThE lAzY dOg";
		p1 = new int[]{36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11};
		p2 = new int[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
		p3 = 778;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 4 -----
		p0 = "two  spaces";
		p1 = new int[]{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
		p2 = new int[]{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
		p3 = 43;
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		if (all_right) {
			System.out.println("You're a stud (at least on the example cases)!");
		} else {
			System.out.println("Some of the test cases had errors.");
		}
	}
	// END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!