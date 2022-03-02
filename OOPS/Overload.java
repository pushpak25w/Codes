class Multiplyfun{
	static int Multiply(int a,int b){
		return a*b;
	}
	static double Multiply(double a,double b){
		return a*b;
	}
	static int Multiply(int a,int b,int c){
		return a*b*c;
	}
}
class Overload{
	 public static void main(String[] args){
		System.out.println(Multiplyfun.Multiply(2,4));
		System.out.println(Multiplyfun.Multiply(1.6,1.5));
		System.out.println(Multiplyfun.Multiply(4,2,3));
	}
}