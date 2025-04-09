package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ResourceBundle;

public class DBUtil {
    private static String driver;
    private static String url;
    private static String name;
    private static String pass;

    static {
        ResourceBundle config = ResourceBundle.getBundle("dao.db-config");
        driver = config.getString("jdbc-driver");
        url = config.getString("jdbc-url");
        name = config.getString("jdbc-name");
        pass = config.getString("jdbc-pass");

        try {
            Class.forName(driver);
        } catch (ClassNotFoundException var2) {
            var2.printStackTrace();
            throw new RuntimeException("读取数据库文件或加载数据库驱动错误");
        }
    }

    public DBUtil() {
    }

    public static Connection getConnection() {
        Connection conn = null;

        try {
            conn = DriverManager.getConnection(url, name, pass);
        } catch (SQLException var2) {
            var2.printStackTrace();
        }

        return conn;
    }

    public static void close(Connection conn, Statement state, ResultSet rs) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException var6) {
                var6.printStackTrace();
            }

            rs = null;
        }

        if (state != null) {
            try {
                state.close();
            } catch (SQLException var5) {
                var5.printStackTrace();
            }

            state = null;
        }

        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException var4) {
                var4.printStackTrace();
            }

            conn = null;
        }

    }

    public static int executeUpdate(String sql, Object[] params) throws SQLException {
        return executeUpdateWithNull(sql, params, (int[])null);
    }

    public static int executeUpdateWithNull(String sql, Object[] params, int[] sqlTypes) throws SQLException {
        Connection conn = null;
        PreparedStatement pstate = null;
        boolean var5 = false;

        int result;
        try {
            conn = getConnection();
            pstate = conn.prepareStatement(sql);
            if (sqlTypes == null) {
                fillParams(pstate, params);
            } else {
                fillParamsWithNull(pstate, params, sqlTypes);
            }

            result = pstate.executeUpdate();
        } catch (SQLException var10) {
            var10.printStackTrace();
            throw var10;
        } finally {
            close(conn, pstate, (ResultSet)null);
        }

        return result;
    }

    public static List<Map<String, Object>> executeQuery(String sql, Object[] params) throws SQLException {
        Connection conn = null;
        PreparedStatement pstate = null;
        ResultSet rs = null;
        ArrayList table = new ArrayList();

        try {
            conn = getConnection();
            pstate = conn.prepareStatement(sql);
            fillParams(pstate, params);
            rs = pstate.executeQuery();
            ResultSetMetaData metaData = rs.getMetaData();
            int columns = metaData.getColumnCount();
            String[] columnNames = new String[columns];

            for(int i = 0; i < columns; ++i) {
                columnNames[i] = metaData.getColumnName(i + 1);
            }

            while(rs.next()) {
                Map<String, Object> row = new HashMap();
                String[] var13 = columnNames;
                int var12 = columnNames.length;

                for(int var11 = 0; var11 < var12; ++var11) {
                    String name = var13[var11];
                    row.put(name, rs.getObject(name));
                }

                table.add(row);
            }
        } catch (SQLException var17) {
            var17.printStackTrace();
            throw var17;
        } finally {
            close(conn, pstate, rs);
        }

        return table;
    }

    private static void fillParams(PreparedStatement pstate, Object[] params) throws SQLException {
        if (params != null) {
            for(int i = 0; i < params.length; ++i) {
                pstate.setObject(i + 1, params[i]);
            }

        }
    }

    private static void fillParamsWithNull(PreparedStatement pstate, Object[] params, int[] sqlTypes) throws SQLException {
        if (params != null) {
            if (sqlTypes == null) {
                fillParams(pstate, params);
            } else if (sqlTypes.length != params.length) {
                throw new RuntimeException("parmas与sqlTypes参数不匹配");
            } else {
                for(int i = 0; i < params.length; ++i) {
                    if (params[i] == null) {
                        pstate.setNull(i + 1, sqlTypes[i]);
                    } else {
                        pstate.setObject(i + 1, params[i], sqlTypes[i]);
                    }
                }

            }
        }
    }
}
