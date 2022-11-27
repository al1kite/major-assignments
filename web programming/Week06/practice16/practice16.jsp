<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %> 
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>practice16.jsp</title>
<%! 
		Calendar cal;
%>
<% 
		cal = Calendar.getInstance();
%>
</head>
<body>
<div align = "center">
<h2>include 액션 연습</h2>
<hr>
			<% 
				int year = cal.get(Calendar.YEAR);
				int month = cal.get(Calendar.MONTH)+1;
				int date = cal.get(Calendar.DATE);
			%>
<jsp:include page="greeting.jsp">
	<jsp:param name="name" value="Dongduck University"/>
	<jsp:param name="year" value="<%=year%>"/> 
	<jsp:param name="month" value="<%=month%>"/> 
	<jsp:param name="date" value="<%=date%>"/> 
	
</jsp:include>
</div>

</body>
</html>