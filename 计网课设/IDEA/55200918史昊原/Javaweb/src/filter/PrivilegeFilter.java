package filter;

import util.Privilege;
import java.io.IOException;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

public class PrivilegeFilter implements Filter {
    public PrivilegeFilter() {
    }

    public void init(FilterConfig config) throws ServletException {
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest)request;
        String servletPath = req.getServletPath();
        HttpSession session = req.getSession(false);
        String dispatcherPath = null;
        if (session != null) {
            String role = (String)session.getAttribute("role");
            if ("user".equals(role)) {
                if (!Privilege.canVisited(servletPath, true)) {
                    dispatcherPath = "/home";
                }
            } else if ("admin".equals(role) && !Privilege.canVisited(servletPath, false)) {
                dispatcherPath = "/admin/home";
            }
        }

        if (dispatcherPath == null) {
            chain.doFilter(request, response);
        } else {
            req.setAttribute("mess", "出错了！！你不能访问该界面");
            req.getRequestDispatcher(dispatcherPath).forward(request, response);
        }
    }

    public void destroy() {
    }
}
