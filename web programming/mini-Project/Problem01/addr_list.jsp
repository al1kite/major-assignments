<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.ch11.*" import="java.util.*" %>
<%request.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="am" class="jspbook.ch11.AddrManager" scope="application"/>
<%@ taglib tagdir="/WEB-INF/tags" prefix="ddwutag" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>body {font-family:"굴림"}</style>
<title>Insert title here</title>
</head>
<body>
<div align=center>
<h2>주소록(전체보기)</h2>
<hr>
<a href="addr_form.jsp">주소추가</a><p>
<table border=1 width=500>
<tr>
	<td>이름</td>
	<td>전화번호</td>
	<td>이메일</td>
	<td>성별</td>
	<td>그룹</td>
</tr>
<% List<AddrBean> ab = am.getAddrList(); 
pageContext.setAttribute("ab",ab);%>
<ddwutag:addrList list="${ab }" page=""/>
</table>
</div>
</body>
</html>