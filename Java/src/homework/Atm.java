package homework;

import java.util.HashMap;

/**
 * Question 26、a.定义银行账号类Account。为Account类添加帐号，密码，金额，3个属
 * 性，并对其进行封装。
 * b.定义ATM机类Atm. 为Atm类添加查询余额，存款和取款方法。
 * c.定义男孩类Boy, 为Boy定义属性 银行帐号
 * d.定义测试类Test，在main方法中创建Boy的对象，创建一个银行帐号，并把这个帐号赋值给Boy。然后通过ATM去进行查询余额，或者 存钱，或者 存款操作。
 * */
public class Atm {
	private HashMap<String, Account> accounts;

	public Atm(HashMap<String, Account> accounts) {
		this.accounts = accounts;
	}

	public Atm() {
		accounts = new HashMap<String, Account>();
	}

	public HashMap<String, Account> getAccounts() {
		return accounts;
	}

	public void setAccounts(HashMap<String, Account> accounts) {
		this.accounts = accounts;
	}
	
	public boolean isAccountExist(String accountnumber){
		return accounts.containsKey(accountnumber);
	}
	
	public boolean verifyPassword(String accountnumber, String password){
		return password == accounts.get(accountnumber).getPassword();
	}
	
	public Double getSave(People people){
		return getSave(people.getAccount().getAccountnumber(), people.getAccount().getPassword());
	}
	
	public Double getSave(String accountnumber, String password){
		if (isAccountExist(accountnumber)){
			if (verifyPassword(accountnumber, password)){
				System.out.println("The query is succeed");
				return accounts.get(accountnumber).getMoney();
			}else{
				System.out.println("The password which you input is wrong");
				return null;
			}
		}else{
			System.out.println("The account is not exist!");
			return null;
		}
	}
	public boolean deposit(People people, double money){
		return deposit(people.getAccount().getAccountnumber(), money);
	}
	
	public boolean deposit(String accountnumber, double money){
		if (isAccountExist(accountnumber)){
			accounts.get(accountnumber).setMoney(accounts.get(accountnumber).getMoney() + money);
			System.out.println("The operation is succeed");
			return true;
		}else{
			System.out.println("The account is not exist");
			return false;
		}
	}
	
	public boolean draw(People people, double money){
		return draw(people.getAccount().getAccountnumber(), people.getAccount().getPassword(), money);
	}
	public boolean draw(String accountnumber, String password, double money){
		if (isAccountExist(accountnumber)){
			if (verifyPassword(accountnumber, password)){
				if (getSave(accountnumber, password) < money){
					System.out.println("The money in your account is not enough");
					return false;
				}else{
					System.out.println("The operation is succeed");
					deposit(accountnumber, -1 * money);
					return true;
				}
			}else{
				System.out.println("The password which you input is wrong");
				return false;
			}
		}else{
			System.out.println("The account is not exist!");
			return false;
		}
	}

}
