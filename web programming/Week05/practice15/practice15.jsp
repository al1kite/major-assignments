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
		cal.set(1919, Calendar.MARCH, 1); 
%>
</head>
<body>
			<% 
				int year = cal.get(Calendar.YEAR);
				int month = cal.get(Calendar.MONTH)+1;
				int date = cal.get(Calendar.DATE);
				int day = cal.get(Calendar.DAY_OF_WEEK);
				
				int start = cal.getMinimum(Calendar.DATE);
				int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH); 
				  
				int startDay = cal.get(Calendar.DAY_OF_WEEK); 
				int Birthdate = cal.get(Calendar.DATE);

			%>
			<h2><%= year +"년 " + month + "월"%></h2>
			<hr>
			<% int cnt = startDay - 1; 
			for(int i = 0; i< startDay; i++)
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