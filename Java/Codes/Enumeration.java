enum Laptop{
	Macbook, XPS, Thinkpad, Surface

}
//enum is a class but we can't extend it.
//enum in java extends enum class.
//We can create constructors and methods in enum.
//

//different depiction of enum class

enum Laptops{
	Macbook(2000), XPS(1500), Thinkpad(1000);

	private int price;

	//we are having the constructor private because we are createing the objects inside the class.
	private Laptops (int price){
		this.price = price;
	}

	public int getPrice(){
		return this.price;
	
	}

	public void setPrice(int price){
		this.price = price;
	}
}

public class Enumeration{
	public static void main(String a[]){
            Laptop lap = Laptop.XPS;
	    System.out.println(lap);

	    System.out.println("Here's the values of the enum : ");

	    Laptop lapis[] = Laptop.values();

	    for(Laptop l : lapis){
		    System.out.println("Type : " + l + " and ordinal is :  " + l.ordinal());
	    }


	    //for the Laptops

	   Laptops laps[] = Laptops.values();

	   for( Laptops lapi : laps){
		   System.out.println("Laptop  : " + lapi + " Price" + lapi.getPrice());
	   }

	}
}
