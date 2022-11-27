<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>greeting.jsp</title>
</head>
<body>
<strong>greeting.jsp에서 출력한 메세지입니다.</strong><br><br>
<%=request.getParameter("name") %>
<%out.println("님 환영합니다.<br>오늘은"); %>
<%=request.getParameter("year")%>/
<%=request.getParameter("month")%>/
<%=request.getParameter("date")%>
<%out.println("입니다.<br>"); %>
</body>
</html>