//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package controller.admin;

import services.AdminServices;
import services.AdminServicesImpi;
import util.UserPaging;
import java.io.IOException;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class AdminAllUserController extends HttpServlet {
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

        AdminServices services = new AdminServicesImpi();
        UserPaging page = services.searchAllUser(pageNum, this.pageSize);
        req.setAttribute("page", page);
        req.setAttribute("uri", "/admin/AllUserController?");
        req.getRequestDispatcher("/admin/manage_user").forward(req, resp);
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
