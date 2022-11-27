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
Integer sessiontime = Integer.valueOf(request.getParameter("sessiontime"));
application.setAttribute("login", username);
application.setAttribute("time", sessiontime);
%>
<%= application.getAttribute("login") %> 님 환영 합니다. <br>
<% session.setMaxInactiveInterval(sessiontime);%>
1. 세션 ID : <%= session.getId() %> <br>
2. 세션 지속시간 : <%= session.getMaxInactiveInterval() %>초<hr>
<% Integer count = (Integer)application.getAttribute("count");
	if (count == null){
		count = 0;
	}
	count = count + 1;
	application.setAttribute("count",count);
%>
count : <%= count %>
</body>
</html>