import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class Truckloads
{
	public int numTrucks(int numCrates, int loadSize)
	{
		Stack<Integer> st = new Stack<Integer>();
		st.push(numCrates);
		ArrayList<Integer> list = new ArrayList<Integer>();
		while(!st.empty()){
			Integer i = st.peek();
			st.pop();
			if(i<=loadSize)
				list.add(i);
			else{
				Integer i2 = i-i/2;
				st.push(i/2);
				st.push(i2);
			}
		}
		return list.size();
	}
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	private static boolean KawigiEdit_RunTest(int testNum, int p0, int p1, boolean hasAnswer, int p2) {
		System.out.print("Test " + testNum + ": [" + p0 + "," + p1);
		System.out.println("]");
		Truckloads obj;
		int answer;
		obj = new Truckloads();
		long startTime = System.currentTimeMillis();
		answer = obj.numTrucks(p0, p1);
		long endTime = System.currentTimeMillis();
		boolean res;
		res = true;
		System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
		if (hasAnswer) {
			System.out.println("Desired answer:");
			System.out.println("\t" + p2);
		}
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		if (hasAnswer) {
			res = answer == p2;
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
		
		int p0;
		int p1;
		int p2;
		
		// ----- test 0 -----
		p0 = 14;
		p1 = 3;
		p2 = 6;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = 15;
		p1 = 1;
		p2 = 15;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = 1024;
		p1 = 5;
		p2 = 256;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
