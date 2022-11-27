<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
	<style>
		body {font-family:"굴림"}
	</style>
</head>
<body>
<%
	String task1 = request.getParameter("TASK1");
	if (task1 == "")
		task1 = "일정 없음";
	String task2 = request.getParameter("TASK2");
%>
<div align="center">
<h1>오늘의 공지사항</h1>
<hr>
</div>
<table>
	<ul align="left">
		<ol><%out.write(task1);%></ol>
		<ol><%out.write(task2);%></ol>
	</ul>
</table>
</body>
</html>