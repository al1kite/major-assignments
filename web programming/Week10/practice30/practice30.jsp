<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import = "java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<center>
<%
String[] typeNames = {"전공필수", "전공선택", "교양", "자유선택"};
String[] titleNames = { "웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", 
"자료구조", "네트워크", "창의와감성", "사회봉사" };
String[] days = {"월", "화", "수", "목", "금"};
%>
<form method=post action="practice30.jsp">
	과목타입:<select name="lectureType"> 
	<% for(int i=0; i<typeNames.length; i++){
		out.println("<option value="+i+">"+typeNames[i]+"</option>"); 
	}
	%>
	</select> 
	
	과목명:<select name="lectureTitle"> 
	<% for(int i=0; i<titleNames.length; i++){
		out.println("<option value="+i+">"+titleNames[i]+"</option>"); 
	}
	%>
	</select> 
	
	요일:<select name="day"> 
	<% for(int i=0; i<days.length; i++){
		out.println("<option value="+i+">"+days[i]+"</option>"); 
	}
	%>
	</select> 
	
	시간:<select name="time"> 
	<% for(int i=1; i<8; i++){
		out.println("<option value="+i+">"+i+"</option>"); 
	}
	%>
	</select> 
	
	연강여부:<select name="consecutive"> 
		<% for(int i=1; i<5; i++){
		out.println("<option value="+i+">"+i+"</option>"); 
	}
	%>
	<input type="submit" value="등록">
<%
String lectureType = request.getParameter("lectureType");
String lectureTitle = request.getParameter("lectureTitle");
String day = request.getParameter("day");
String time = request.getParameter("time");
String consecutive = request.getParameter("consecutive");

ArrayList<String> timetable = (ArrayList<String>)application.getAttribute("timetable");

if(timetable == null){
	timetable = new ArrayList<String>();	
}
if(lectureType != null){
	timetable.add(typeNames[Integer.parseInt(lectureType)] + "/" + titleNames[Integer.parseInt(lectureTitle)] + "/" + days[Integer.parseInt(day)] + "/" + time + "/" + consecutive);
	application.setAttribute("timetable", timetable);	
}
if(timetable != null) {
	out.println("<br>");
	for(String timetables : timetable)
		out.println(timetables + "<br>");	
}
%>
</form>
</center>
</body>
</html>