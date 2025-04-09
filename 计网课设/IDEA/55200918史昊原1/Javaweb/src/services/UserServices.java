package services;

import model.User;

public interface UserServices {
    User findUser(String var1);

    String allowUserLogin(String var1, String var2);

    String getAutoLoginCookieValue(String var1);

    String allowAutoLogin(String var1);

    String changeUserPassword(String var1, String var2, String var3);

    String changeUserInfo(String var1, String var2, String var3, String var4);

    String signup(String var1, String var2, String var3, String var4, String var5, String var6);
}
