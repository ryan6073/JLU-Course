package util;

import javax.annotation.Resource;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import javax.sql.DataSource;


@WebListener
public class WebContextListener implements ServletContextListener {
    /*
     * 使用Resource注解成员变量，通过名字查找server.xml中配置的数据源并注入进来
     * lookup：指定目录处的名称，此属性是固定的
     * name：指定数据源的名称，即数据源处配置的name属性
     */
    @Resource(lookup="java:/comp/env", name="jdbc/JNDI")

    /*将找到的数据源保存在此变量中，javax.sql.DataSource*/
    private DataSource dataSource;

    @Override
    public void contextDestroyed(ServletContextEvent event) {

    }

    @Override
    public void contextInitialized(ServletContextEvent event) {
        /*测试数据源*/

        /*将数据源注入连接管理*/
        ConnectionManager.setDadaSource(dataSource);
    }
}