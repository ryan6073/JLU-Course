package biz.impl;

import entity.User;

import javax.ejb.Local;
import javax.ejb.LocalBean;
import java.util.List;

@Local
public interface UserBean {
    public List<User> getUser();
}