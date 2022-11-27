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
		cal.set(2008, Calendar.FEBRUARY, 1); 
%>
</head>
<body>
			<% 
				int year = cal.get(Calendar.YEAR);
				int month = cal.get(Calendar.MONTH)+1;
				int date = cal.get(Calendar.DATE);
				int day = cal.get(Calendar.DAY_OF_WEEK);
				String print_date = "오류";
				
				if (day == 2)
					print_date = "월";
				else if (day == 3)
					print_date = "화";
				else if (day == 4)
					print_date = "수";
				else if (day == 5)
					print_date = "목";
				else if (day == 6)
					print_date = "금";
				else if (day == 7)
					print_date = "토";
				else if (day == 1)
					print_date = "일";
				
				
				int start = cal.getMinimum(Calendar.DATE);
				int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH); 
				
				cal.set(2001, Calendar.JUNE, 2);  
				int startDay = cal.get(Calendar.DAY_OF_WEEK); 
				String birthDate = "오류";

				if (startDay == 2)
					birthDate = "월";
				else if (startDay == 3)
					birthDate = "화";
				else if (startDay == 4)
					birthDate = "수";
				else if (startDay == 5)
					birthDate = "목";
				else if (startDay == 6)
					birthDate = "금";
				else if (startDay == 7)
					birthDate = "토";
				else if (startDay == 1)
					birthDate = "일";

			%>
			<%= year + "년 " + month + "월 " + date +"일 " + print_date + "요일" +"입니다.<br><br>" %>
			<%= "이번 달은 "+ start + "일부터 시작하여 " + end + "일에 끝납니다.<br><br>" %> 
			<%="내 생일 2001년 6월 2일은 " +birthDate+"요일 입니다<br>"%>
</body>
</html>