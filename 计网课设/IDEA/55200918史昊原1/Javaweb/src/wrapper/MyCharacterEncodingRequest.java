package wrapper;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletRequestWrapper;

public class MyCharacterEncodingRequest extends HttpServletRequestWrapper {
    private HttpServletRequest request;

    public MyCharacterEncodingRequest(HttpServletRequest request) {
        super(request);
        this.request = request;
    }

    public String getParameter(String name) {
        try {
            String value = this.request.getParameter(name);
            if (value == null) {
                return null;
            } else if (!this.request.getMethod().equalsIgnoreCase("GET")) {
                return value.trim();
            } else {
                value = new String(value.getBytes("iso-8859-1"), this.request.getCharacterEncoding());
                return value.trim();
            }
        } catch (Exception var3) {
            throw new RuntimeException(var3);
        }
    }
}
