<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib tagdir="/WEB-INF/tags" prefix="ddwutag" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<% request.setCharacterEncoding("UTF-8");%>
</head>
<body>
<%
String username = request.getParameter("id");
session.setAttribute("login", username);
%>
<ddwutag:greeting color="pink" /><br>
<ddwutag:greeting color="green" />
</body>
</html>