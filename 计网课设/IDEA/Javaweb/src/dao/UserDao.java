package dao;

import entity.User;
import java.util.List;

public interface UserDao {
    boolean add(User var1);

    boolean delete(String var1);

    boolean update(User var1);

    User findById(String var1);

    List<User> findAll();

    int findCount(String var1, UserDao.Type var2, boolean var3);

    List<User> findRange(String var1, UserDao.Type var2, boolean var3, int var4, int var5);

    int userCount();

    boolean idExist(String var1);

    boolean emailExist(String var1);

    public static enum Type {
        ID,
        NAME,
        EMAIL;

        private Type() {
        }
    }
}
