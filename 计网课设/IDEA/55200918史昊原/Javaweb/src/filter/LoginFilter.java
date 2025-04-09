package filter;

import entity.User;
import biz.UserBiz;
import biz.UserBizImpi;
import java.io.IOException;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginFilter implements Filter {
    public static final String[] unLoginServletPathes = new String[]{"/login", "/LoginController", "/admin/login", "/admin/LoginController", "/signup", "/SignupController"};

    public LoginFilter() {
    }

    public void init(FilterConfig config) throws ServletException {
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest)request;
        HttpServletResponse resp = (HttpServletResponse)response;
        HttpSession session = req.getSession(false);
        String servletPath = req.getServletPath();
        if (session == null || !"user".equals(session.getAttribute("role")) && !"admin".equals(session.getAttribute("role"))) {
            Cookie[] cookies = req.getCookies();
            Cookie cookie = null;
            int var11;
            int var12;
            if (cookies != null) {
                Cookie[] var13 = cookies;
                var12 = cookies.length;

                for(var11 = 0; var11 < var12; ++var11) {
                    Cookie c = var13[var11];
                    if ("auto_login".equals(c.getName())) {
                        cookie = c;
                        break;
                    }
                }
            }

            if (cookie != null) {
                UserBiz services = new UserBizImpi();
                String id = services.allowAutoLogin(cookie.getValue());
                if (id != null) {
                    User user = services.findUser(id);
                    session = req.getSession(true);
                    session.setAttribute("role", "user");
                    session.setAttribute("self", user);
                    chain.doFilter(request, response);
                    return;
                }

                cookie.setMaxAge(0);
                resp.addCookie(cookie);
            }

            String[] var18;
            var12 = (var18 = unLoginServletPathes).length;

            for(var11 = 0; var11 < var12; ++var11) {
                String path = var18[var11];
                if (path.equals(servletPath)) {
                    chain.doFilter(request, response);
                    return;
                }
            }

            resp.sendRedirect(request.getServletContext().getContextPath() + "/login");
        } else {
            chain.doFilter(request, response);
        }
    }

    public void destroy() {
    }
}
