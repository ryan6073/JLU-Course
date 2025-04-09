<%--
  Created by IntelliJ IDEA.
  User: shy
  Date: 2023-03-01
  Time: 16:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册</title>
</head>
<body>
<form action="AddServlet" method="post">
    <label for="username">用户名</label>
    <input type="text" name="username" id="username">
    <label for="password">密码</label>
    <input type="text" name="password" id="password">


    <input type="submit" value="提交">
</form>
</body>

