//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package controller.admin;

import biz.AdminBiz;
import biz.AdminBizImpi;
import biz.impl.UserBean;
import util.UserPaging;
import java.io.IOException;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.ejb.EJB;

public class AdminAllUserController extends HttpServlet {
    @EJB
    UserBean bean;
    private int pageSize;

    public AdminAllUserController() {
    }

    public void init(ServletConfig config) throws ServletException {
        super.init(config);
        String pageSizeStr = config.getInitParameter("pageSize");
        this.pageSize = Integer.parseInt(pageSizeStr);
        if (this.pageSize < 1) {
            throw new RuntimeException("分页大小pageSize不能小于1");
        }
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String pageNumStr = req.getParameter("pageNum");
        int pageNum = 1;

        try {
            if (!"".equals(pageNumStr)) {
                pageNum = Integer.parseInt(pageNumStr);
            }
        } catch (Exception var7) {
        }
//
        //获取全部用户并跳转
        //req.getSession().setAttribute("userList",bean.getUser());
        //req.getRequestDispatcher("").forward(req,resp);
//
        AdminBiz services = new AdminBizImpi();
        UserPaging page = services.searchAllUser(pageNum, this.pageSize);
        req.setAttribute("page", page);
        req.setAttribute("uri", "/admin/AllUserController?");
        req.getRequestDispatcher("/admin/manage_user").forward(req, resp);
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
