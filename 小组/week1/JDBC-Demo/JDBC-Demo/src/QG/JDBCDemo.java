package QG;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCDemo {
    //注册驱动
    static {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    //获取连接
    public static Connection getConnection() throws Exception {
        String url="jdbc:mysql://127.0.0.1:3306/qg";
        String username = "root";
        String password ="123456";
        return DriverManager.getConnection(url,username, password);
    }

    public static void closeQuietly(Connection con,Statement stmt) {
        if (con!=null && stmt!=null) {
            try {
                con.close();
                stmt.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws Exception{
        //获取连接
        Connection con=getConnection();
        //执行sql
        Statement stmt=con.createStatement();
        String sql1="update test set money = 3000 where id= 1";
        String sql2="INSERT INTO test(id,money,name) VALUES('3','2024','王五')";
        String sql3 ="delete from test where id = 2";
        int rowsAffected1=stmt.executeUpdate(sql1);
        System.out.println("Rows affected by SQL statement 1: " + rowsAffected1);
        int rowsAffected2 = stmt.executeUpdate(sql2);
        System.out.println("Rows affected by SQL statement 2: " + rowsAffected2);
        int rowsAffected3 = stmt.executeUpdate(sql3);
        System.out.println("Rows affected by SQL statement 3: " + rowsAffected3);
        //释放资源
        closeQuietly(con,stmt);
    }
}
