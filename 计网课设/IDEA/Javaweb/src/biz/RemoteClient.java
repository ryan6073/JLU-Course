package biz;

import javax.naming.Context;
import javax.naming.InitialContext;
import java.util.Hashtable;

public class RemoteClient {
    public String searchbind(String bindname) throws Exception {

        Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "org.apache.naming.java.javaURLContextFactory");
        env.put(Context.PROVIDER_URL, "http://localhost:8080/");
        env.put(Context.SECURITY_PRINCIPAL, "admin");
        env.put(Context.SECURITY_CREDENTIALS, "admin");
        Context ctx = new InitialContext(env);
        //ctx.bind("MySchool","jlu");
        String str = (String) ctx.lookup("MySchool");
        System.out.println(str);
        return str;
    }
}
