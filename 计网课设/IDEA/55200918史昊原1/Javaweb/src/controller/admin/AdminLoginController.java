package controller.admin;

import model.Admin;
import services.AdminServices;
import services.AdminServicesImpi;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class AdminLoginController extends HttpServlet {
    public AdminLoginController() {
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String id = req.getParameter("id");
        String pass = req.getParameter("pass");
        if (!"".equals(id) && !"".equals(pass)) {
            AdminServices services = new AdminServicesImpi();
            String result = services.allowAdminLogin(id, pass);
            if (result == null) {
                HttpSession session = req.getSession(true);
                session.setAttribute("role", "admin");
                Admin admin = services.findAdmin(id);
                session.setAttribute("self", admin);
                req.getRequestDispatcher("/admin/home").forward(req, resp);
            } else {
                req.setAttribute("mess", "用户名或密码错误");
                req.getRequestDispatcher("/admin/login").forward(req, resp);
            }
        } else {
            req.setAttribute("mess", "用户名、密码不能为空");
            req.getRequestDispatcher("/admin/login").forward(req, resp);
        }
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
