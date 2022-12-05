<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="jspbook.ch11.*" import="java.util.*" %>
    <%@ taglib tagdir="/WEB-INF/tags" prefix="ddwutag" %>
<jsp:useBean id="am" class="jspbook.ch11.AddrManager" scope="application"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>body {font-family:"굴림"}</style>
<title>주소록(그룹보기)</title>
</head>
<body>
	<div align=center>
		<h2>주소록(그룹보기)</h2>
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
			<%
			List<AddrBean> group = new ArrayList<AddrBean>(); 
			for(AddrBean ab : am.getAddrList()) 
				if(ab.getGroup().equals("가족")) 	
					group.add(ab);
			for(AddrBean ab : am.getAddrList()) 
				if(ab.getGroup().equals("친구")) 	
					group.add(ab);
			for(AddrBean ab : am.getAddrList()) 
				if(ab.getGroup().equals("직장")) 	
					group.add(ab);
			
			pageContext.setAttribute("group",group);
			%>
			<ddwutag:addrList list="${group }" page = "_group"/>
		</table>
	</div>
</body>
</html>