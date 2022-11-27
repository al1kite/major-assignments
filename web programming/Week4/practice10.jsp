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
	String yoil[] = {"일", "월", "화", "수", "목", "금", "토"};
	%>
	<style>
	        td {
            text-align:center;
        }
        .red{color:red;}
        .blue{color:blue;}
	</style>
	
<body>
	<table border = "3">
		<tr>
			<td class="red">
				<% out.write(yoil[0]);%> 
			</td>
			<%
				for(int i =1; i<6; i++){
			%>
			<td>
				<% out.write(yoil[i]);%> 
			</td>
			<% 
				}
			%>
			<td class="blue">
				<% out.write(yoil[6]);%> 
			</td>
		</tr>
		<%
			for(int i=0; i<4; i++){

		%>
		<tr>
			<% 
				for(int j=0; j<7; j++){
			%>
				<td>
					<% out.write("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"); %> 		
				</td>
				<% 
				}
				%>
		</tr>
			<% 
				}
			%>
	</table>

</body>
</html>