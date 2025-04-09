package controller.admin;

import biz.AdminBiz;
import biz.AdminBizImpi;
import util.UserPaging;
import java.io.IOException;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class AdminSearchController extends HttpServlet {
    private int pageSize;

    public AdminSearchController() {
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
        String searchText = req.getParameter("searchText");
        if ("".equals(searchText)) {
            req.setAttribute("mess", "请输入搜索内容");
            req.getRequestDispatcher("/admin/search").forward(req, resp);
        } else {
            String searchByStr = req.getParameter("searchBy");
            byte searchBy;
            if ("id".equals(searchByStr)) {
                searchBy = 0;
            } else if ("email".equals(searchByStr)) {
                searchBy = 1;
            } else {
                if (!"name".equals(searchByStr)) {
                    req.setAttribute("mess", "出错了，请重试！！！");
                    req.getRequestDispatcher("/admin/search").forward(req, resp);
                    return;
                }

                searchBy = 2;
            }

            String fuzzySearch = req.getParameter("fuzzySearch");
            boolean isFuzzySearch = fuzzySearch != null && !"".equals(fuzzySearch);
            String pageNumStr = req.getParameter("pageNum");
            int pageNum = 1;

            try {
                if (!"".equals(pageNumStr)) {
                    pageNum = Integer.parseInt(pageNumStr);
                }
            } catch (Exception var13) {
            }

            StringBuilder uri = new StringBuilder();
            uri.append("/admin/SearchController?");
            uri.append("searchText=" + searchText);
            uri.append("&searchBy=" + searchByStr);
            if (isFuzzySearch) {
                uri.append("&fuzzySearch=every_thing_is_ok");
            }

            AdminBiz services = new AdminBizImpi();
            UserPaging page = services.searchUser(searchBy, searchText, isFuzzySearch, pageNum, this.pageSize);
            req.setAttribute("uri", uri.toString());
            req.setAttribute("page", page);
            req.getRequestDispatcher("/admin/manage_user").forward(req, resp);
        }
    }

    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }
}
