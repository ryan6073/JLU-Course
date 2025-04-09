package controller.user;

import biz.UserBiz;
import biz.UserBizImpi;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class SignupController extends HttpServlet {
    public SignupController() {
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String id = req.getParameter("id");
        String pass1 = req.getParameter("pass1");
        String pass2 = req.getParameter("pass2");
        String name = req.getParameter("name");
        String email = req.getParameter("email");
        String sex = req.getParameter("sex");
        String intro = req.getParameter("intro");
        String error = "";
        if ("".equals(id)) {
            error = error + "用户名为空；";
        }

        if (pass1 == null || pass2 == null || !pass1.equals(pass2)) {
            error = error + "密码为空或不匹配；";
        }

        if ("".equals(name)) {
            error = error + "昵称为空；";
        }

        if ("".equals(email)) {
            error = error + "邮箱为空；";
        }

        if ("".equals(intro)) {
            error = error + "简介为空；";
        }

        if ("male".equals(sex)) {
            sex = "男";
        } else if ("female".equals(sex)) {
            sex = "女";
        } else {
            sex = "保密";
        }

        if (!"".equals(error)) {
            req.setAttribute("mess", "出错了！！<br/>" + error);
            req.getRequestDispatcher("/signup").forward(req, resp);
        } else {
            UserBiz services = new UserBizImpi();
            String result = services.signup(id, pass1, name, email, sex, intro);
            if (result == null) {
                req.setAttribute("mess", "注册成功，登录一下吧!");
                req.getRequestDispatcher("/login").forward(req, resp);
            } else {
                req.setAttribute("mess", "出错了！！<br/>" + result);
                req.getRequestDispatcher("/signup").forward(req, resp);
            }
        }
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
