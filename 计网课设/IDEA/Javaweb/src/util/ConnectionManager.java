package util;

import java.sql.Connection;
import java.sql.SQLException;
import javax.sql.DataSource;

/*连接对象的管理者*/

public final class ConnectionManager {
    /*确保在每一个连接里是同一个连接对象，方便以后做事务的管理，针对每个线程创建一个独立的容器*/
    /*使用泛型标准*/
    private final static ThreadLocal<Connection> LOCAL=new ThreadLocal();
    private static DataSource dataSource;

    public static void setDadaSource(DataSource dataSource) {
        /*不能使用this*/
        ConnectionManager.dataSource=dataSource;
    }

    /*返回连接对象*/
    public static Connection getConnection() throws SQLException {
        /*获取连接对象*/
        Connection conn=LOCAL.get();
        if(null != conn) {
            return conn;
        }

        /*通过数据源得到连接，并放入线程中管理，再返回连接对象*/
        conn=dataSource.getConnection();
        LOCAL.set(conn);
        return conn;
    }

    /*释放连接对象*/
    public static void release() {
        Connection conn=LOCAL.get();
        if(null != conn) {
//            DBUtil.release(conn);
            LOCAL.remove();
        }
    }
}