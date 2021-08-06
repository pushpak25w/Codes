class Parent{
	void print(){
		System.out.println("Parent Class");
	}
}

class subclass1 extends Parent{
	void print(){
		System.out.println("Subclass1");
	}
}

class subclass2 extends Parent{
	void print(){
		System.out.println("Subclass2");
	}
}

class Override{
	public static void main(String[] args){
		Parent a;
		a=new subclass1();
		a.print();
		a=new subclass2();
		a.print();
	}
}