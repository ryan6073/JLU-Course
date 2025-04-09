package util;

public class Privilege {
    private static final String[] userServletPathes = new String[]{"/login", "/LoginController", "/LogoutController", "/home", "/change_pass", "/change_info", "/ChangePassController", "/ChangeInfoController"};
    private static final String[] adminServletPathes = new String[]{"/admin/login", "/admin/LoginController", "/admin/LogoutController", "/admin/home", "/admin/manage_user", "/admin/search", "/admin/UpdateUserController", "/admin/AllUserController", "/admin/SearchController"};

    public Privilege() {
    }

    public static boolean canVisited(String servletPath, boolean isUser) {
        if ("".equals(servletPath)) {
            return true;
        } else {
            return isUser ? contains(userServletPathes, servletPath) : contains(adminServletPathes, servletPath);
        }
    }

    private static boolean contains(String[] servletPathes, String servletPath) {
        String[] var5 = servletPathes;
        int var4 = servletPathes.length;

        for(int var3 = 0; var3 < var4; ++var3) {
            String path = var5[var3];
            if (path.equals(servletPath)) {
                return true;
            }
        }

        return false;
    }
}
