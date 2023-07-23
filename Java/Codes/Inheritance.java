class Calculator{
	

	public int add(int num1, int num2){
		return num1+num2;
	}

	public int substract(int num1, int num2){
		return num1-num2;
	}

}

class AdvCalc extends Calculator{
	public int mult(int n, int m){
		return n*m;
	}

	public int divide(int num, int deno){
		return num/deno;
	}
}

class ScientificCalc extends AdvCalc{
	public int powerOfN(int a, int n){
			if(n == 0)return 1;

			return a *powerOfN(a, n-1);
	}

	public int fibo(int n){
		if(n <= 1) return n;

		return fibo(n-1) + fibo(n-2);
	}
}

public class Inheritance{

	public  static void main(String a[]){
		Calculator cal = new Calculator();
		int sum = cal.add(4,5);

		System.out.println("SUM IS : " +sum);
		
		int sub = cal.substract(6,3);

		System.out.println("Substraction IS : " + sub);
		
		AdvCalc calcu = new AdvCalc();

		int add = calcu.add(4, 11);

		int subs = calcu.substract(30, 14);

		int mul = calcu.mult(4, 5);

		int div = calcu.divide(20, mul);

		System.out.println("Addition with Adv calc : " + add);	
		System.out.println("Substraction with Adv calc : " + subs);
		System.out.println("Multiplication with Adv calc : " + mul);
		System.out.println("Division with Adv calc : " + div);


		ScientificCalc sci = new ScientificCalc();
		int power = sci.powerOfN(2, 3);
		System.out.println(" a to the power of n : " + power);

		int fib = sci.fibo(4);
		System.out.println("Hey the fibonnaci no. : "+ fib);
	}
}
