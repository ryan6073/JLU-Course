package listener;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

public class OnlineUserCount implements HttpSessionListener {
    public OnlineUserCount() {
    }

    public void sessionCreated(HttpSessionEvent event) {
        ServletContext context = event.getSession().getServletContext();
        Object count = context.getAttribute("onlineCount");
        if (count == null) {
            context.setAttribute("onlineCount", 1);
        } else {
            context.setAttribute("onlineCount", (Integer)count + 1);
        }

    }

    public void sessionDestroyed(HttpSessionEvent event) {
        ServletContext context = event.getSession().getServletContext();
        Object count = context.getAttribute("onlineCount");
        if (count == null) {
            context.setAttribute("onlineCount", 1);
        } else {
            int newCount = (Integer)count - 1 > 0 ? (Integer)count - 1 : 1;
            context.setAttribute("onlineCount", newCount);
        }

    }
}
