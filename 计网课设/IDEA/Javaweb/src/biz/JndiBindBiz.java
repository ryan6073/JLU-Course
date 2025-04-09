package biz;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class JndiBindBiz {

    public boolean bind(String bindname,String bindvalue) throws NamingException {

        Context ctx = new InitialContext();
        ctx.bind(bindname,bindvalue);
        return true;

    }
    public void rebind(String bindname,String bindvalue) throws NamingException {
        Context ctx = new InitialContext();
        ctx.rebind(bindname,bindvalue);
    }
    public void unbind(String bindname) throws NamingException {
        Context ctx = new InitialContext();
        ctx.unbind(bindname);
    }
}

