package dao;

import entity.Admin;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

public class AdminDaoImpi implements AdminDao {
    public AdminDaoImpi() {
    }

    public Admin findById(String id) {
        String sql = "SELECT * FROM admin WHERE id = ?";
        List table = null;

        try {
            table = DBUtil.executeQuery(sql, new Object[]{id});
        } catch (SQLException var5) {
            var5.printStackTrace();
        }

        if (table != null && table.size() == 1) {
            Map<String, Object> record = (Map)table.get(0);
            return new Admin(((String)record.get("id")).trim(), ((String)record.get("pass")).trim());
        } else {
            return null;
        }
    }
}
