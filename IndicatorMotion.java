import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class IndicatorMotion
{
	public String getMotion(String program, char startState)
	{
		String result="";
		result+=startState;
		String newSequence="";
		for(int i = 0 ; i < program.length()/3; i++){
			String temp = program.substring(i*3,i*3+3);
			newSequence+=helper(temp);
		}
		if(newSequence.length()==0 || program.length()==0)
			return result;
		for(int i = 0 ; i < newSequence.length() ; i++){
			char currentOp = newSequence.charAt(i);
			if(currentOp=='S'){
				result+=startState;
			}
			else if(currentOp=='F'){
				if(startState=='\\'){
					startState='/';
				}
				else if(startState=='/'){
					startState='\\';
				}
				else if(startState=='|'){
					startState='-';
				}
				else
					startState='|';
				result+=startState;	
			}
			else if(currentOp=='R'){
				if(startState=='\\'){
					startState='|';
				}
				else if(startState=='|'){
					startState='/';
				}
				else if(startState=='/'){
					startState='-';
				}
				else
					startState='\\';
				result+=startState;
			}
			else{
				if(startState=='|'){
					startState='\\';
				}
				else if(startState=='\\'){
					startState='-';
				}
				else if(startState=='-'){
					startState='/';
				}
				else
					startState='|';
				result+=startState;				
			}
		}
		return result;
	}
	
	public String helper(String str){
		String temp="";
		int i = Integer.parseInt(str.substring(1,3));
		for(int j = 0 ; j < i ; j++){
			temp+=str.charAt(0);
		}
		return temp;
	}
	

	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		
		time = System.currentTimeMillis();
		answer = new IndicatorMotion().getMotion("F03L02R03S02F04", '-');
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "-|-|\\-\\|///\\/\\/";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new IndicatorMotion().getMotion("F10R01F10", '/');
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "/\\/\\/\\/\\/\\/-|-|-|-|-|-";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new IndicatorMotion().getMotion("", '/');
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "/";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new IndicatorMotion().getMotion("F00R00L00S00", '\\');
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "\\";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}

}
//Powered by [KawigiEdit] 2.0!
