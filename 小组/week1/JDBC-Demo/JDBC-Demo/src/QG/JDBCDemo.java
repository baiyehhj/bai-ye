package QG;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.Scanner;

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

    //查询
    public static void query()throws Exception{
        Connection con=getConnection();
        Statement stmt=con.createStatement();
        //stmt.executeUpdate(sql);
        ResultSet rs = stmt.executeQuery("SELECT * FROM test");
        System.out.println("已查询");
    }
    //添加
    public static void add()throws Exception{
        Connection con=getConnection();
        Statement stmt=con.createStatement();
        String sql="INSERT INTO test(id,money,name) VALUES('1','100','张三')";
        stmt.executeUpdate(sql);
       System.out.println("已添加");
    }
    //修改
    public static void update()throws Exception{
        Connection con=getConnection();
        Statement stmt=con.createStatement();
        String sql="update test set money = 1111 where id= 1";
        stmt.executeUpdate(sql);
        System.out.println("已更新");
    }
    //删除
    public static void delete()throws Exception{
        Connection con=getConnection();
        Statement stmt=con.createStatement();
        String sql ="delete from test where id = 1";
        stmt.executeUpdate(sql);
        System.out.println("已删除");
    }

    public static void closeQuietly(Connection con) {
        if (con!=null ) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    public static void closeQuietly(Statement stmt) {
        if (stmt!=null) {
            try {
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
        while(true){
            System.out.println("1.查询所有 2.添加数据 3.修改数据 4.删除数据 5.结束运行");
            System.out.println("请输入操作序号：");
            Scanner scanner=new Scanner(System.in);
            int num=scanner.nextInt();
            if(num==5) break;
            switch (num){
                case 1:query();break;
                case 2:add();break;
                case 3:update();break;
                case 4:delete();break;
            }
        }

        //释放资源
        closeQuietly(con);
        closeQuietly(stmt);
    }
}
