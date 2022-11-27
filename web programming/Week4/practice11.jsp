<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
		
	<%! 
		int sum;
	%>
	
<body>
	<table border = "3">
	<tr>
		<%
			for(int i=2; i<6; i++){

		%>
		<td>
			<% 
				for(int j=1; j<10; j++){
					sum = i * j;
			%>
					<%= i+ "*" + j + " = " + sum+"<br>"%>
				<% 
				}
				%>
		</td>
			<% 
				}
			%>
	</tr>
		<tr>
		<%
			for(int i=6; i<10; i++){

		%>
		<td>
			<% 
				for(int j=1; j<10; j++){
					sum = i * j;
			%>
					<%= i+ " * " + j + " = " + sum +"<br>"%>
				<% 
				}
				%>
		</td>
			<% 
				}
			%>
	</tr>
	</table>

</body>
</html>