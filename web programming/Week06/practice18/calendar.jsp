<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="java.util.*" %> 
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
<style>
body {font-family:"굴림"}
</style>
<meta charset="UTF-8">
<title>Insert title here</title>
<%! 
		Calendar cal;
%>
<% 
		cal = Calendar.getInstance();
%>
</head>
<body>
			<% 
				int year = Integer.valueOf(request.getParameter("year"));
				int month = Integer.valueOf(request.getParameter("month"));
				cal.set(year, month-1, 1); 
				
				int start = cal.getMinimum(Calendar.DATE);
				int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH); 
				  
				int startDay = cal.get(Calendar.DAY_OF_WEEK); 

			%>
			<h2><%= year +"년 " + month + "월"%></h2>
			<hr>
			<% int cnt = startDay - 1; 
			for(int i = 0; i<= startDay; i++)
					out.write(" &nbsp;"); 
			%>
			<% for(int i = start; i <= end; i++){
				out.println(i+" ");
				cnt++;
				if(cnt%7 == 0)
					out.write("<br>");
				}
			%>
</body>
</html>