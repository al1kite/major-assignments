<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ taglib tagdir="/WEB-INF/tags" prefix="ddwutag" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<ddwutag:printTable brd = "2" color="pink"> 회원정보 </ddwutag:printTable><br>
<ddwutag:printTable brd="0" color="yellow"> 입력한 내용 </ddwutag:printTable>
</body>
</html>