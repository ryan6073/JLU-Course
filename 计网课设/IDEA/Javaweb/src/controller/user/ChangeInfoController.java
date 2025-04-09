package controller.user;

import entity.User;
import biz.UserBiz;
import biz.UserBizImpi;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ChangeInfoController extends HttpServlet {
    public ChangeInfoController() {
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        User user = (User)req.getSession().getAttribute("self");
        String name = req.getParameter("name");
        String email = req.getParameter("email");
        String intro = req.getParameter("intro");
        if (user.getName().equals(name) && user.getEmail().equals(email) && user.getIntro().equals(intro)) {
            req.setAttribute("mess", "未进行任何修改");
            req.getRequestDispatcher("/home").forward(req, resp);
        } else {
            UserBiz services = new UserBizImpi();
            String result = services.changeUserInfo(user.getId(), name, email, intro);
            if (result == null) {
                user = services.findUser(user.getId());
                req.getSession().setAttribute("self", user);
                req.setAttribute("mess", "修改成功");
                req.getRequestDispatcher("/home").forward(req, resp);
            } else {
                req.setAttribute("mess", "修改失败!!" + result);
                req.getRequestDispatcher("/change_info").forward(req, resp);
            }
        }
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
