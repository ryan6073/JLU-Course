package biz;

import dao.UserDao;
import dao.UserDaoImpi;
import entity.User;

import javax.ejb.Stateless;
import java.util.List;
@Stateless
public class LocalUserBean implements biz.impl.UserBean {
    private UserDaoImpi userDao=new UserDaoImpi();
    @Override
    public List<User> getUser() {
        return userDao.findAll();
    }
}
