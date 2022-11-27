<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%  
String username = request.getParameter("username");
session.setAttribute("login", username);
%>
<%= session.getAttribute("login") %> 님 환영 합니다. <br>
1. 세션 ID : <%= session.getId() %> <br>
2. 세션 유지시간 : <%= session.getMaxInactiveInterval() %><hr>
<a href = "session_03.jsp">session_03.jsp 바로가기</a>
</body>
</html>