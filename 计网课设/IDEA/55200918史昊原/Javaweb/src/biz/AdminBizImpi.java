package biz;

import dao.AdminDao;
import dao.AdminDaoImpi;
import dao.UserDao;
import dao.UserDao.Type;
import dao.UserDaoImpi;
import entity.Admin;
import entity.User;
import util.DigestUtils;
import util.UserPaging;
import java.util.ArrayList;
import java.util.List;

public class AdminBizImpi implements AdminBiz {
    private AdminDao adminDao = new AdminDaoImpi();
    private UserDao userDao = new UserDaoImpi();

    public AdminBizImpi() {
    }

    public Admin findAdmin(String id) {
        return this.adminDao.findById(id);
    }

    public String allowAdminLogin(String id, String pass) {
        Admin admin = this.findAdmin(id);
        if (admin == null) {
            return "该用户不存在";
        } else {
            return admin.getPass().equals(pass) ? null : "密码错误";
        }
    }

    public String resetUserPassword(String id, String newPass) {
        User user = this.userDao.findById(id);
        if (user == null) {
            return "用户不存在";
        } else {
            String digest = DigestUtils.sha256Digest(user.getSalt() + newPass);
            user.setPass(digest);
            return digest != null && this.userDao.update(user) ? null : "重置密码失败，请重试";
        }
    }

    public String freezeUser(String id) {
        User user = this.userDao.findById(id);
        if (user == null) {
            return "用户不存在";
        } else if (user.isFreeze()) {
            return "该用户已经被冻结，未执行任何操作";
        } else {
            user.setFreeze(true);
            return this.userDao.update(user) ? null : "冻结用户失败，请重试";
        }
    }

    public String recoverUser(String id) {
        User user = this.userDao.findById(id);
        if (user == null) {
            return "用户不存在";
        } else if (!user.isFreeze()) {
            return "该用户未被冻结，未执行任何操作";
        } else {
            user.setFreeze(false);
            return this.userDao.update(user) ? null : "恢复用户失败，请重试";
        }
    }

    public String deleteUser(String id) {
        return this.userDao.delete(id) ? null : "删除用户失败，请重试";
    }

    public UserPaging searchUser(int searchBy, String searchText, boolean isFuzzySearch, int pageNum, int pageSize) {
        if (pageSize < 1) {
            throw new RuntimeException("分页大小为" + pageSize + "，至少应为1");
        } else {
            Type type = Type.ID;
            if (searchBy == 0) {
                type = Type.ID;
            } else if (searchBy == 2) {
                type = Type.NAME;
            } else if (searchBy == 1) {
                type = Type.EMAIL;
            }

            int totalRecord = this.userDao.findCount(searchText, type, isFuzzySearch);
            if (totalRecord == 0) {
                return new UserPaging(0, 0, pageSize, -1, new ArrayList());
            } else {
                int totalPage = totalRecord / pageSize;
                if (totalRecord % pageSize != 0) {
                    ++totalPage;
                }

                if (pageNum < 1 || pageNum > totalPage) {
                    pageNum = 1;
                }

                int offset = (pageNum - 1) * pageSize;
                List<User> data = null;
                data = this.userDao.findRange(searchText, type, isFuzzySearch, offset, pageSize);
                return new UserPaging(totalRecord, totalPage, pageSize, pageNum, data);
            }
        }
    }

    public UserPaging searchAllUser(int pageNum, int pageSize) {
        return this.searchUser(0, "", true, pageNum, pageSize);
    }
}
