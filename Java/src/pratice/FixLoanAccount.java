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
public class FixLoanAccount extends LoanAccount{

	public FixLoanAccount() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FixLoanAccount fix = new FixLoanAccount();
		double temp = 1000000;
		fix.setFund(temp);
		System.out.println(fix.calculateInterest());
		

	}

	public double getInterestRate() {
		// TODO Auto-generated method stub
		return 0.03;
	}

}
