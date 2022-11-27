<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %> 
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>practice17.jsp</title>
<%! 
		Calendar cal;
%>
<% 
		cal = Calendar.getInstance();
%>
</head>
<body>
			<% 
				int year = cal.get(Calendar.YEAR);
				int month = cal.get(Calendar.MONTH)+1;
				int date = cal.get(Calendar.DATE);
			%>
<jsp:forward page="greeting.jsp">
	<jsp:param name="name" value="Dongduck University"/>
	<jsp:param name="year" value="<%=year%>"/> 
	<jsp:param name="month" value="<%=month%>"/> 
	<jsp:param name="date" value="<%=date%>"/> 
</jsp:forward>

</body>
</html>