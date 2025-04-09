package dao;

import entity.User;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class UserDaoImpi implements UserDao {
    public UserDaoImpi() {
    }

    public boolean add(User user) {
        String sql = "INSERT INTO user VALUES(?, ?, ?, ?, ?, ?, ?, ?)";
        Object[] params = new Object[]{user.getId(), user.getSalt(), user.getPass(), user.isFreeze(), user.getName(), user.getEmail(), user.getSex(), user.getIntro()};
        int[] types = new int[]{1, 1, 1, -7, 1, 12, 1, 12};
        int result = 0;

        try {
            result = DBUtil.executeUpdateWithNull(sql, params, types);
        } catch (SQLException var7) {
            var7.printStackTrace();
        }

        return result == 1;
    }

    public boolean delete(String id) {
        String sql = "DELETE FROM user WHERE id=?";
        int result = 0;

        try {
            result = DBUtil.executeUpdate(sql, new Object[]{id});
        } catch (SQLException var5) {
            var5.printStackTrace();
        }

        return result == 1;
    }

    public boolean update(User user) {
        String sql = "UPDATE user SET salt=?, pass=?, freeze=?, name=?, email=?, sex=?, intro=? WHERE id=?";
        Object[] params = new Object[]{user.getSalt(), user.getPass(), user.isFreeze(), user.getName(), user.getEmail(), user.getSex(), user.getIntro(), user.getId()};
        int[] types = new int[]{1, 1, -7, 1, 12, 1, 12, 1};
        int result = 0;

        try {
            result = DBUtil.executeUpdateWithNull(sql, params, types);
        } catch (SQLException var7) {
            var7.printStackTrace();
        }

        return result == 1;
    }

    public User findById(String id) {
        String sql = "SELECT * FROM user WHERE id=?";
        List<User> result = this.search(sql, new Object[]{id});
        return result.size() == 1 ? (User)result.get(0) : null;
    }

    public List<User> findAll() {
        String sql = "SELECT * FROM user";
        return this.search(sql, new Object[0]);
    }

    public int findCount(String value, Type type, boolean isFuzzySearch) {
        String sql = "SELECT COUNT(*) num FROM user WHERE";
        if (type == Type.ID) {
            sql = sql + " id like ?";
        } else if (type == Type.NAME) {
            sql = sql + " name like ?";
        } else {
            sql = sql + " email like ?";
        }

        if (isFuzzySearch) {
            value = this.addFuzzy(value);
        }

        List result = null;

        try {
            result = DBUtil.executeQuery(sql, new Object[]{value});
        } catch (SQLException var7) {
            var7.printStackTrace();
        }

        return result != null && result.size() == 1 ? (int)((Map)result.get(0)).get("num") : 0;//
    }

    public List<User> findRange(String value, Type type, boolean isFuzzySearch, int offset, int limit) {
        String sql = "SELECT * FROM user WHERE";
        if (type == Type.ID) {
            sql = sql + " id like ?";
        } else if (type == Type.NAME) {
            sql = sql + " name like ?";
        } else {
            sql = sql + " email like ?";
        }

        if (offset >= 0 && limit > 0) {
            sql = sql + " limit " + limit + " offset " + offset;
        }

        if (isFuzzySearch) {
            value = this.addFuzzy(value);
        }

        return this.search(sql, new Object[]{value});
    }

    public int userCount() {
        String sql = "SELECT COUNT(*) num FROM user";
        List result = null;

        try {
            result = DBUtil.executeQuery(sql, new Object[0]);
        } catch (SQLException var4) {
            var4.printStackTrace();
        }

        return result != null && result.size() == 1 ? (int)((Map)result.get(0)).get("num") : 0;//
    }

    public boolean idExist(String id) {
        String sql = "SELECT COUNT(*) AS num FROM user WHERE id = ?";
        List list = null;

        try {
            list = DBUtil.executeQuery(sql, new Object[]{id});
        } catch (SQLException var6) {
            var6.printStackTrace();
        }

        if (list == null) {
            return true;
        } else {
            long num = (Long)((Map)list.get(0)).get("num");
            return num > 0L;
        }
    }

    public boolean emailExist(String email) {
        String sql = "SELECT COUNT(*) AS num FROM user WHERE email = ?";
        List list = null;

        try {
            list = DBUtil.executeQuery(sql, new Object[]{email});
        } catch (SQLException var6) {
            var6.printStackTrace();
        }

        if (list == null) {
            return true;
        } else {
            long num = (Long)((Map)list.get(0)).get("num");
            return num > 0L;
        }
    }

    private String addFuzzy(String value) {
        return "".equals(value) ? "%" : "%" + value + "%";
    }

    private List<User> search(String sql, Object[] params) {
        List table = null;

        try {
            table = DBUtil.executeQuery(sql, params);
        } catch (SQLException var5) {
            var5.printStackTrace();
        }

        return this.toUsers(table);
    }

    private User toUser(Map<String, Object> record) {
        String id = this.toStringAndTrime(record.get("id"));
        String salt = this.toStringAndTrime(record.get("salt"));
        String pass = this.toStringAndTrime(record.get("pass"));
        boolean freeze = (Boolean)record.get("freeze");
        String name = this.toStringAndTrime(record.get("name"));
        String email = this.toStringAndTrime(record.get("email"));
        String sex = this.toStringAndTrime(record.get("sex"));
        String intro = this.toStringAndTrime(record.get("intro"));
        return new User(id, salt, pass, freeze, name, email, sex, intro);
    }

    private List<User> toUsers(List<Map<String, Object>> table) {
        List<User> result = new ArrayList();
        if (table == null) {
            return result;
        } else {
            Iterator iter = table.iterator();

            while(iter.hasNext()) {
                result.add(this.toUser((Map)iter.next()));
            }

            return result;
        }
    }

    public String toStringAndTrime(Object o) {
        return o == null ? null : ((String)o).trim();
    }
}
