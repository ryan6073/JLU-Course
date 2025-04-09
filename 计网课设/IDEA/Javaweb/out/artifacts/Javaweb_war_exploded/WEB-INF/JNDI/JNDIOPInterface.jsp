<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8" session="false"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
    <title>JNDI本地操作页面</title>
    <%@ include file="/WEB-INF/style.jsp" %>
</head>

<h3>JNDI</h3>

<form action="Bind" method="post">
    <div class="elem">
        绑定名字：<br/><input type="bindname" name="bindname" ><br/>
    </div>
    <div class="elem">
        绑定值：<br/><input type="bindvalue" name="bindvalue"><br/>
    </div>
    <div class="elem">
        <input type="submit" name="name" value="绑定" />
    </div>
    <div class="elem">
        <input type="submit" name="name" value="查询" />
    </div>
    <div class="elem">
        <input type="submit" name="name" value="重新绑定" />
    </div>
    <div class="elem">
        <input type="submit" name="name" value="取消绑定" />
    </div>
</form>

</html>


