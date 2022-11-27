<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="java.util.*" %> 
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<%!
	String yoil[] = {"일", "월", "화", "수", "목", "금", "토"};
	%>
		<style>
	body {font-family:"굴림"}
	        td {
            text-align:center;
            padding: 10px;
        }
        .red{color:red;}
        .blue{color:blue;}
        .line {  border:1px solid #000000;
          		border-collapse: collapse;}
	</style>
<%! 
		Calendar cal;
%>
<% 
		cal = Calendar.getInstance();
%>
<title>Insert title here</title>
</head>
<body>
			<% 
				Calendar today; 
				int year = cal.get(Calendar.YEAR);
				int month = cal.get(Calendar.MONTH)+1;
				int date = cal.get(Calendar.DATE);
				int day = cal.get(Calendar.DAY_OF_WEEK);
				
				int start = cal.getMinimum(Calendar.DATE);
				int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH); 
				
				//cal.set(2022, Calendar.OCTOBER, 1); 
				cal.set(year, month-1, 1); 
				  
				int startDay = cal.get(Calendar.DAY_OF_WEEK); 
			%>
						<div align="right"><%= year +"-" + month + "-" + date%></div>
			<table border = "3" class="line">
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
				int cnt = 1; 
			%>
					<%
					
			for(int i=0; cnt < end; i++){

		%>
		<tr>
			<% 
				for(int j=1; j<8; j++){ %>

						<% if (0 < i* 7 + j && i * 7 + j < startDay || cnt > end){
							out.println("<td>");
							out.write(" &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
							out.println("</td>");}
						else {
						 
						 	if(j == 1){
						 		out.println("<td class='red'>");
						 		out.write("&nbsp;&nbsp;&nbsp;");
							 	out.println((int)cnt++);
								out.write("&nbsp;&nbsp;&nbsp;");
								out.println("</td>");
							}
						 	else if (j==7){
							 	out.println("<td class='blue'>");
								out.write("&nbsp;&nbsp;&nbsp;");
								out.println((int)cnt++);
								out.write("&nbsp;&nbsp;&nbsp;");
								out.println("</td>");
						 	}
							else{
								out.println("<td>");
								out.write("&nbsp;&nbsp;&nbsp;");
						 		out.println((int)cnt++);
								out.write("&nbsp;&nbsp;&nbsp;");
								out.println("</td>");
							}
						}
					}%>
		</tr>
			<% 
				}
			%>

		</table>
		

</body>
</html>