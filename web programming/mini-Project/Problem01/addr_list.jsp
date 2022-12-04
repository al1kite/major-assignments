<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" %>
    <%@ page import="jspbook.ch11.*" import="java.util.*" %>
    <%request.setCharacterEncoding("UTF-8"); %>
    <jsp:useBean id="am" class="jspbook.ch11.AddrManager" scope="application"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<div align=center>
<h2>주소록</h2>
<hr>
<a href="addr_form.jsp">주소추가</a><p>
<%
	int rpp = 2; 
	int currentPage; 
	int lastIndex; 
	int startIndex;
	int allpage; 
	
	if(request.getParameter("sindex") == null){
		currentPage = 1;
	}
	else{
		currentPage = Integer.parseInt(request.getParameter("sindex"));
	}
%>
<table border=1 width=500>
<tr>
	<td>이름</td>
	<td>전화번호</td>
	<td>이메일</td>
	<td>성별</td>
</tr>
<% 
	startIndex = (currentPage - 1) * 2;
	lastIndex = startIndex + 1;
	
	List<AddrBean> ab = am.getAddrList();

	for(int i = startIndex; i <= lastIndex; i++) {
		if(i >= ab.size())
			break;
%>
	<tr>
		<td><%= ab.get(i).getUsername() %></td>
		<td><%= ab.get(i).getTel() %></td>
		<td><%= ab.get(i).getEmail() %></td>
		<td><%= ab.get(i).getSex() %></td>
	</tr>
<% } 
	
	if (ab.size() % 2 == 0)
		allpage = ab.size() / 2;
	else
		allpage = ab.size() / 2 + 1;
	
	for(int i = 1; i <= allpage; i++){
		if(i == currentPage){
			out.print(i);
		}
		else{
			out.print("<a href=\"addr_list.jsp?sindex="+ i + "\">" + i + "</a>");
		}
		if(i != allpage){
			out.print(" | ");
		}
	}
%>
</table>
</div>
</body>
</html>