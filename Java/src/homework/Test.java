package homework;

import java.util.HashMap;

/**
 * Question 26、a.定义银行账号类Account。为Account类添加帐号，密码，金额，3个属
 * 性，并对其进行封装。
 * b.定义ATM机类Atm. 为Atm类添加查询余额，存款和取款方法。
 * c.定义男孩类Boy, 为Boy定义属性 银行帐号
 * d.定义测试类Test，在main方法中创建Boy的对象，创建一个银行帐号，并把这个帐号赋值给Boy。然后通过ATM去进行查询余额，或者 存钱，或者 存款操作。
 * */
public class Test {

	public static void main(String[] args) {
		 Boy boy = new Boy();
		 Account account = new Account("6363663636", "786160", 100000.0);
		 boy.setAccount(account);
		 HashMap<String, Account> accounts = new HashMap<String, Account>();
		 accounts.put(account.getAccountnumber(), account);
		 Atm atm = new Atm(accounts);
		 System.out.println(atm.getSave(boy));
		 atm.deposit(boy, 10000.0);
		 System.out.println(atm.getSave(boy));
		 atm.draw(boy, 100);
		 System.out.println(atm.getSave(boy));
		 

	}

}
