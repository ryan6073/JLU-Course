package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ErrorHandler extends HttpServlet {
    public ErrorHandler() {
    }

    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Throwable throwable = (Throwable)req.getAttribute("javax.servlet.error.exception");
        Integer statusCode = (Integer)req.getAttribute("javax.servlet.error.status_code");
        String requestUri = (String)req.getAttribute("javax.servlet.error.request_uri");
        StringBuilder sb = new StringBuilder();
        sb.append("出错了！！！");
        sb.append("<br/>");
        sb.append("Exception: " + throwable.getMessage());
        sb.append("<br/>");
        sb.append("StatusCode: " + (statusCode == null ? "Unknow" : statusCode));
        sb.append("<br/>");
        sb.append("RequestUri: " + (requestUri == null ? "Unknow" : requestUri));
        req.setAttribute("mess", sb.toString());
        req.getRequestDispatcher("/error").forward(req, resp);
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
