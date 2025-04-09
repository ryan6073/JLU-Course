package controller.user;

import entity.User;
import biz.UserBiz;
import biz.UserBizImpi;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ChangePassController extends HttpServlet {
    public ChangePassController() {
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String oldPass = req.getParameter("oldPass");
        String newPass1 = req.getParameter("newPass1");
        String newPass2 = req.getParameter("newPass2");
        if (!"".equals(oldPass) && !"".equals(newPass1) && !"".equals(newPass2)) {
            if (!newPass1.equals(newPass2)) {
                req.setAttribute("mess", "新密码、确认密码必须相同");
                req.getRequestDispatcher("/change_pass").forward(req, resp);
            } else if (oldPass.equals(newPass1)) {
                req.setAttribute("mess", "当前密码与新密码相同，修改失败");
                req.getRequestDispatcher("/change_pass").forward(req, resp);
            } else {
                User user = (User)req.getSession(false).getAttribute("self");
                UserBiz services = new UserBizImpi();
                String result = services.changeUserPassword(user.getId(), oldPass, newPass1);
                if (result != null) {
                    req.setAttribute("mess", result);
                    req.getRequestDispatcher("/change_pass").forward(req, resp);
                } else {
                    req.setAttribute("mess", "修改密码成功");
                    req.getRequestDispatcher("/home").forward(req, resp);
                }
            }
        } else {
            req.setAttribute("mess", "当前密码、新密码、确认密码不能为空");
            req.getRequestDispatcher("/change_pass").forward(req, resp);
        }
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
