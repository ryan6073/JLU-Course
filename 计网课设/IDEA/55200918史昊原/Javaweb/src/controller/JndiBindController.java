package controller;

import biz.JndiBindBiz;
import biz.RemoteClient;

import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class JndiBindController extends HttpServlet {


    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp){


        String type=req.getParameter("name");
        try {

            if(type.equals("绑定")){
                Bind(req,resp);
            }
            else if(type.equals("重新绑定")){
                ReBind(req,resp);
            }
            else if(type.equals("取消绑定")){
                UnBind(req,resp);
            }
            else if(type.equals("查询")){
                SearchBind(req,resp);
            }

        } catch (NamingException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("WEB-INF/error.jsp").forward(req,resp);
    }

    private void Bind(HttpServletRequest req,HttpServletResponse resp){

        String bindname=req.getParameter("bindname");
        String bindvalue=req.getParameter("bindvalue");

        JndiBindBiz service=new JndiBindBiz();

        try {

            if(service.bind(bindname,bindvalue)){
                req.setAttribute("end","bind success!");
                req.setAttribute("bindname",bindname);
                req.setAttribute("bindvalue",bindvalue);

                req.getRequestDispatcher("WEB-INF/JNDI/response.jsp").forward(req,resp);
            }

        } catch (NamingException e) {
            e.printStackTrace();
        } catch (ServletException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void SearchBind(HttpServletRequest req,HttpServletResponse resp) throws Exception {

        String bindname=req.getParameter("bindname");

        RemoteClient service=new RemoteClient();
        String str = service.searchbind(bindname);

        req.setAttribute("end","查询结果如下：");
        req.setAttribute("bindname",bindname);
        req.setAttribute("bindvalue",str);
        req.getRequestDispatcher("WEB-INF/JNDI/response.jsp").forward(req,resp);
    }

    private void ReBind(HttpServletRequest req,HttpServletResponse resp) throws NamingException, ServletException, IOException {
        String bindname=req.getParameter("bindname");
        String bindvalue=req.getParameter("bindvalue");

        JndiBindBiz service=new JndiBindBiz();
        service.rebind(bindname,bindvalue);

        req.setAttribute("end","rebind success!");
        req.setAttribute("bindname",bindname);
        req.setAttribute("bindvalue",bindvalue);
        req.getRequestDispatcher("WEB-INF/JNDI/response.jsp").forward(req,resp);
    }

    private void UnBind(HttpServletRequest req,HttpServletResponse resp) throws NamingException, ServletException, IOException {
        String bindname=req.getParameter("bindname");
        String bindvalue=req.getParameter("bindvalue");

        JndiBindBiz service=new JndiBindBiz();
        service.unbind(bindname);

        req.setAttribute("end","unbind success!");
        req.setAttribute("bindname",bindname);
        req.setAttribute("bindvalue",bindvalue);
        req.getRequestDispatcher("WEB-INF/JNDI/response.jsp").forward(req,resp);
    }
}
