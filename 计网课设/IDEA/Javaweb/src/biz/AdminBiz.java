package biz;

import entity.Admin;
import util.UserPaging;

public interface AdminBiz {
    int SEARCH_BY_ID = 0;
    int SEARCH_BY_EMAIL = 1;
    int SEARCH_BY_NAME = 2;

    Admin findAdmin(String var1);

    String allowAdminLogin(String var1, String var2);

    String resetUserPassword(String var1, String var2);

    String freezeUser(String var1);

    String recoverUser(String var1);

    String deleteUser(String var1);

    UserPaging searchUser(int var1, String var2, boolean var3, int var4, int var5);

    UserPaging searchAllUser(int var1, int var2);
}
