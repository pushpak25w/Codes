interface one{
	public void print_eli();
}

interface two{
	public void print_the();
}

interface three extends one,two{
	public void print_ice();
}

class child implements three{
	public void print_eli(){
		System.out.println("Eli");
	}
	public void print_the(){
		System.out.println("the");
	}
	public void print_ice(){
		System.out.println("Ice");
	}
}

public class multiple{
	public static void main(String[] args){
		child c=new child();
		c.print_eli();
		c.print_the();
		c.print_ice();
	}
}