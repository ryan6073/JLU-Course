package controller.user;

import model.User;
import services.UserServices;
import services.UserServicesImpi;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginController extends HttpServlet {
    public LoginController() {
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String id = req.getParameter("id");
        String pass = req.getParameter("pass");
        if (!"".equals(id) && !"".equals(pass)) {
            UserServices services = new UserServicesImpi();
            String result = services.allowUserLogin(id, pass);
            if (result != null) {
                req.setAttribute("mess", "出错了！！<br/>" + result);
                req.getRequestDispatcher("/login").forward(req, resp);
            } else {
                User user = services.findUser(id);
                HttpSession session = req.getSession(true);
                session.setAttribute("role", "user");
                session.setAttribute("self", user);
                String autoLogin = req.getParameter("recordPass");
                if (autoLogin != null && !autoLogin.equals("")) {
                    String digest = services.getAutoLoginCookieValue(id.trim());
                    if (digest != null) {
                        Cookie cookie = new Cookie("auto_login", digest);
                        int timeInSecond = Integer.parseInt(this.getServletConfig().getInitParameter("auto_login_time"));
                        cookie.setMaxAge(timeInSecond);
                        resp.addCookie(cookie);
                    }
                }

                req.getRequestDispatcher("/home").forward(req, resp);
            }
        } else {
            req.setAttribute("mess", "用户名、密码不能为空");
            req.getRequestDispatcher("/login").forward(req, resp);
        }
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
