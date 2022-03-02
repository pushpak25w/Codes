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

public class single{
	public static void main(String[] args){
		two g=new two();
		g.print_eli();
		g.print_the();
		g.print_eli();
	}
}