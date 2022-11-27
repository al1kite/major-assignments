<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="java.util.*" %> 
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<%! 
		Calendar cal;
%>
<% 
		cal = Calendar.getInstance();
%>
    <style>
    body {font-family:"굴림"}
        body {
            display: flex;
			align-items: center;
			justify-content: center;
        }
        th,td,caption { padding:10px 5px;}
        th {font-size: 20px;
        text-align: center;}
        td {font-size: 13px;
            text-align: center;}
            .padd{ padding-right:25px; }
    </style>
</head>
<body>
			<% 
				int year = cal.get(Calendar.YEAR);
				int month = cal.get(Calendar.MONTH)+1;
				int date = cal.get(Calendar.DATE);
			%>
<div align="center">
<h2>include 지시어 연습</h2>
<hr>
<table>
	<tr>
	<td><jsp:include page="calendar.jsp">
	<jsp:param name="year" value="<%=year%>"/> 
	<jsp:param name="month" value="<%=month%>"/>
	</jsp:include> </td>
	<td class="padd"><jsp:include page="news.jsp">
	<jsp:param name="TASK1" value=""/> 
	<jsp:param name="TASK2" value="Homework"/>
	</jsp:include>
	</td>
	</tr>
</table>
</div>
</body>
</html>