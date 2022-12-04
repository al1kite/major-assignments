<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="jspbook.ch11.*" import="java.util.*" %>
    <jsp:useBean id="am" class="jspbook.ch11.AddrManager" scope="application"/>
<jsp:useBean id="afa" class="jspbook.ch11.AddrManager"/>
<jsp:useBean id="afr" class="jspbook.ch11.AddrManager"/>
<jsp:useBean id="ajob" class="jspbook.ch11.AddrManager"/>
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
		<a href="addr_form.html">주소추가</a><P>
		<table border=1 width=500>
			<tr>
				<td>이름</td>
				<td>전화번호</td>
				<td>이메일</td>
				<td>성별</td>
				<td>그룹</td>
			</tr>
			<%
				for(AddrBean ab : am.getAddrList()) {
					if(ab.getGroup().equals("가족")) 	
						afa.add(ab);
					else if(ab.getGroup().equals("친구"))
						afr.add(ab);
					else
						ajob.add(ab);
				}
			
				for(AddrBean ab : afa.getAddrList()) {
			%>
				<tr>
				<td><%=ab.getUsername() %></td>
				<td><%=ab.getTel() %></td> 
				<td><%=ab.getEmail() %></td>
				<td><%=ab.getSex()%></td>
				<td><%=ab.getGroup() %></td>
				</tr>
			<%
				}
				
				for(AddrBean ab : afr.getAddrList()) {
			%>
				<tr>
				<td><%=ab.getUsername() %></td>
				<td><%=ab.getTel() %></td> 
				<td><%=ab.getEmail() %></td>
				<td><%=ab.getSex()%></td>
				<td><%=ab.getGroup() %></td>
				</tr>
			<% 
}
				
				for(AddrBean ab : ajob.getAddrList()) {
			%>
				<tr>
				<td><%=ab.getUsername() %></td>
				<td><%=ab.getTel() %></td> 
				<td><%=ab.getEmail() %></td>
				<td><%=ab.getSex()%></td>
				<td><%=ab.getGroup() %></td>
				</tr>
			<%
				}
			%>
				
		</table>
	</div>
</body>
</html>