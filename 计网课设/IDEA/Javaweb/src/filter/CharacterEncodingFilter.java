package filter;

import wrapper.MyCharacterEncodingRequest;
import java.io.IOException;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;

public class CharacterEncodingFilter implements Filter {
    private static String defaultCharset = "UTF-8";

    public CharacterEncodingFilter() {
    }

    public void init(FilterConfig config) throws ServletException {
        String charset = config.getInitParameter("charset");
        if (!"".equals(charset)) {
            defaultCharset = charset;
        }

    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        request.setCharacterEncoding(defaultCharset);
        response.setCharacterEncoding(defaultCharset);
        response.setContentType("text/html;charset=" + defaultCharset);
        MyCharacterEncodingRequest myRequest = new MyCharacterEncodingRequest((HttpServletRequest)request);
        chain.doFilter(myRequest, response);
    }

    public void destroy() {
    }
}
