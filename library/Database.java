package test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Database {
	public static final String DBDRIVER = "com.mysql.jdbc.Driver" ;
	public static final String DBURL = "jdbc:mysql://localhost:3306/lottery" ;
	public static final String DBUSER = "root" ;
	public static final String DBPASS = "786160313" ;
	public static void main(String args[]) throws Exception{    // 所有异常抛出
	Connection conn = null ;        // 数据库连接
	PreparedStatement pstmt = null ;    // 数据库操作
	ResultSet rs = null ;    // 接收查询结果
	String sql = "SELECT * FROM sql_database" ;
	Class.forName(DBDRIVER) ;    // 加载驱动程序
	conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS) ;
	pstmt = conn.prepareStatement(sql) ;    // 实例化PreapredStatement对象
	rs = pstmt.executeQuery() ;    // 执行查询
	while(rs.next()){
	//int id = rs.getInt(1) ;// rs.getInt(“id”);  编号从1开始
	String date = rs.getString(1) ;
	String cost = rs.getString(2) ;
	String reward = rs.getString(3);
	System.out.println(date+" " +cost+" "+reward );

	}
	rs.close() ;      
	pstmt.close() ;
	conn.close() ;            // 数据库关闭
	}
}
