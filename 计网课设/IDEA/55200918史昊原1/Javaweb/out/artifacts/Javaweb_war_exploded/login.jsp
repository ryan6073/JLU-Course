<%--
  Created by IntelliJ IDEA.
  User: shy
  Date: 2023-03-01
  Time: 15:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录界面</title>
</head>
<body style="background-color:#FAEAEA">
<form action="LogoServlet" method="post">
    <label for="username">用户名</label>
    <input type="text" name="username" id="username">
    <label for="password">密码</label>
    <input type="text" name="password" id="password">


    <input type="submit" value="提交">
</form>
</body>
