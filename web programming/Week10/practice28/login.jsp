<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<form name="frm" method="POST" action="checker.jsp">
<% 
	String username = (String)session.getAttribute("user");
	if(username == null) {
		out.println("아이디 : <input type=text name=user><p>");
		out.println("패스워드 : <input type=password name=passwd><p>");
		out.println("<input type=hidden name=action value=login>");
		out.println("<input type=submit value=로그인>");
	} 
	else { 
		out.println(username + "님 환영합니다.<p>");
		out.println("<input type=hidden name=action value=logout>");
		out.println("<input type=submit value=logout>");
	}
%>
</form>
</body>