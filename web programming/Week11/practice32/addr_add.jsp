<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.ch11.*"%>
    <%request.setCharacterEncoding("UTF-8"); %>
    <jsp:useBean id="addr" class="jspbook.ch11.AddrBean"/>
    <jsp:setProperty name="addr" property="*"/>
    <jsp:useBean id="am" class="jspbook.ch11.AddrManager" scope="application"/> 
  	<% am.add(addr); 
  	request.setCharacterEncoding("UTF-8");%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<div align="center">
<h2>등록내용</h2>
이름 : <jsp:getProperty property="username" name="addr"/><p>
전화번호 : <%=addr.getTel() %><p>
이메일 : <%=addr.getEmail() %><p>
성별 : <%=addr.getSex() %>
<hr>
<a href="addr_list.jsp">목록보기</a>
</div>
</body>
</html>