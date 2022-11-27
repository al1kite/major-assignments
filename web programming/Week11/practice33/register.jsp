<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*"%>
    <jsp:useBean id="Login" class="jspbook.pr33.LoginBean" scope="page"/>
<jsp:setProperty name="Login" property="*"/>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<div align="center">
<h2>등록내용</h2>
이름 :<jsp:getProperty property="id" name="Login"/><br>
패스워드:${Login.pw } <br>
이메일:${Login.email }<br>
성별:<jsp:getProperty property="gender" name="Login"/><br>
생일:<jsp:getProperty property="birth" name="Login"/><br>
<hr>
<jsp:getProperty property="id" name="Login"/>씨는
<%
	if(Login.getGender().equals(1)){
		out.print("남성이고, ");
	}
	else{
		out.print("여성이고, ");
	}

	if(Login.isGrownUp()){
		out.print("성인입니다.");
	}
	else{
		out.print("성인이 아닙니다.");
	}
%>
</div>
</body>
</html>