<%--
  Created by IntelliJ IDEA.
  User: shy
  Date: 2023-03-16
  Time: 19:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Response</title>
</head>
<body>
<h2>操作结果：</h2><h2><%=request.getAttribute("end")%></h2>
<h2>bind_name：</h2><h2><%=request.getAttribute("bindname")%></h2>
<h2>bind_value：</h2><h2><%=request.getAttribute("bindvalue")%></h2>
<a href="javascript:history.back(-1)">返回</a>
</body>
</html>
