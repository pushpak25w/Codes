class one{
	public void print_eli(){
		System.out.println("Eli");
	}
}

class two extends one{
	public void print_the(){
		System.out.println("the");
	}
}

class three extends two{
	public void print_ice(){
		System.out.println("Ice");
	}
}

public class multilevel{
	public static void main(String[] args){
		three g=new three();
		g.print_eli();
		g.print_the();
		g.print_ice();
	}
}