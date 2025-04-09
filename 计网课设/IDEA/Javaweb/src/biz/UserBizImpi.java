package biz;

import dao.UserDao;
import dao.UserDaoImpi;
import entity.User;
import util.DigestUtils;
import util.ValidateUserInfo;
import java.util.Random;

public class UserBizImpi implements UserBiz {
    private static final int saltLength = 16;
    private UserDao userDao = new UserDaoImpi();

    public UserBizImpi() {
    }

    public User findUser(String id) {
        return this.userDao.findById(id);
    }

    public String allowUserLogin(String id, String pass) {
        User user = this.userDao.findById(id);
        if (user == null) {
            return "用户不存在";
        } else if (user.isFreeze()) {
            return "该账户已被冻结，请联系管理员";
        } else {
            String passDigest = DigestUtils.sha256Digest(user.getSalt() + pass);
            return user.getPass().equals(passDigest) ? null : "用户名或密码错误";
        }
    }

    public String getAutoLoginCookieValue(String id) {
        User user = this.findUser(id);
        if (user != null && !user.isFreeze()) {
            String digest = DigestUtils.sha256Digest(user.getSalt() + id);
            return digest == null ? null : digest + "@" + id;
        } else {
            return null;
        }
    }

    public String allowAutoLogin(String cookieValue) {
        if (cookieValue == null) {
            return null;
        } else {
            String[] mess = cookieValue.split("@");
            if (mess.length != 2) {
                return null;
            } else {
                String id = mess[1];
                String newCookieValue = this.getAutoLoginCookieValue(id);
                return newCookieValue != null && newCookieValue.equals(cookieValue) ? id : null;
            }
        }
    }

    public String changeUserPassword(String id, String oldPass, String newPass) {
        User user = this.findUser(id);
        if (user == null) {
            return "用户不存在";
        } else {
            String passDigest = DigestUtils.sha256Digest(user.getSalt() + oldPass);
            if (!passDigest.equals(user.getPass())) {
                return "当前密码不正确";
            } else {
                String mess = ValidateUserInfo.validatePassword(newPass);
                if (mess != null) {
                    return mess;
                } else {
                    String salt = this.randomString(16);
                    String newPassDigest = DigestUtils.sha256Digest(salt + newPass);
                    user.setSalt(salt);
                    user.setPass(newPassDigest);
                    return this.userDao.update(user) ? null : "出错了";
                }
            }
        }
    }

    public String changeUserInfo(String id, String newName, String newEmail, String newIntro) {
        User user = this.userDao.findById(id);
        if (user == null) {
            return "用户不存在";
        } else {
            String temp;
            if ((temp = ValidateUserInfo.validateEmail(newEmail)) != null) {
                return temp;
            } else if (!user.getEmail().equals(newEmail) && this.userDao.emailExist(newEmail)) {
                return "该邮箱已被注册";
            } else if ((temp = ValidateUserInfo.validateName(newName)) != null) {
                return temp;
            } else if ((temp = ValidateUserInfo.validateIntro(newIntro)) != null) {
                return temp;
            } else {
                user.setName(newName);
                user.setEmail(newEmail);
                user.setIntro(newIntro);
                return this.userDao.update(user) ? null : "出错了！！！";
            }
        }
    }

    public String signup(String id, String pass, String name, String email, String sex, String intro) {
        String mess = ValidateUserInfo.validate(id, pass, name, email, sex, intro);
        if (mess != null) {
            return mess;
        } else if (this.userDao.idExist(id)) {
            return "用户名" + id + "已经被注册";
        } else if (this.userDao.emailExist(email)) {
            return "邮箱" + email + "已经被注册";
        } else {
            String salt = this.randomString(16);
            String passDigest = DigestUtils.sha256Digest(salt + pass);
            User user = new User(id, salt, passDigest, false, name, email, sex, intro);
            return this.userDao.add(user) ? null : "添加出错了";
        }
    }

    private String randomString(int n) {
        String base = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()_+=<>/,./;'[]{}|\\\\";
        int length = base.length();
        char[] buff = new char[n];
        Random r = new Random();

        for(int i = 0; i < n; ++i) {
            buff[i] = base.charAt(r.nextInt(length));
        }

        return new String(buff);
    }
}
