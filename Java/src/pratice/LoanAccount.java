package pratice;

/**
 * Question 30、模版模式：
 * abstract class LoanAccount{
 *	//利息，本金
 *	private double interest, fund;
 *	public double calculateInterest(){		
 *		//用于计算利息的算法：本金*利率，但是利率的算法实现并没有在这个类中实现
 *		interest=getFund()*getInterestRate();
 *		return interest;
 *	} 	
 *	//不同的存款类型有不同的利率， 因此，不在这个父类中实现利率的计算方法，
 *	 // 而将它推迟到子类中实现 
 *	protected abstract double getInterestRate();
 *	
 *	public void setFund(double fund){
 *		this.fund = fund;
 *	}
 *	public double getFund(){
 *		return fund;
 *	}
 * }
 * 实现定期存储，年利率为3.5%, 假设存款本金为20W,请计算1年利息为多少？
 */
public abstract class LoanAccount {
	private double interest;
	private double fund;
	
	public double calculateInterest(){
		return fund * getInterestRate();
	}
	
	public double getInterest() {
		return interest;
	}

	public void setInterest(double interest) {
		this.interest = interest;
	}

	public double getFund() {
		return fund;
	}

	public void setFund(double fund) {
		this.fund = fund;
	}

	public abstract double getInterestRate();

	public LoanAccount() {
	}

}
