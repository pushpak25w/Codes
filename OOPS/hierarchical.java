class A{
	public void print_A(){
		System.out.println("Class A");
	}
}

class B extends A{
	public void print_B(){
		System.out.println("Class B");
	}
}

class C extends A{
	public void print_C(){
		System.out.println("Class C");
	}
}

class D extends A{
	public void print_D(){
		System.out.println("Class D");
	}
}

public class hierarchical{
	public static void main(String[] args){
		B obj_b=new B();
		obj_b.print_A();
		obj_b.print_B();

		C obj_c=new C();
		obj_c.print_A();
		obj_c.print_C();

		D obj_d=new D();
		obj_d.print_A();
		obj_d.print_D();
	}
}