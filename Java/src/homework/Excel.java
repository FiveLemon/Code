package homework;

/**
 * Question 44
 * */
public class Excel extends MsProduct implements Office, Serializable{
	private double price;
	private String version;
	
	public Excel() {
		super();
	}
	public Excel(double price, String version) {
		super();
		this.price = price;
		this.version = version;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public String getVersion() {
		return version;
	}
	public void setVersion(String version) {
		this.version = version;
	}
	public void start() {
		System.out.println("Excel Start!");
	}	
}
