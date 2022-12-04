<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %> 
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="java.time.LocalDate" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<%!
	String yoil[] = {"일", "월", "화", "수", "목", "금", "토"};
%>
<style>
	body{
	font-family:"굴림";
	display:flex;
	justify-content:center;
	align-items:center;
	}
	td{
	padding: 10px;
	width:70px;
	height:20px;
    text-align:center;
    }	
    .line {  border:1px solid #000000;
     border-collapse: collapse;}
     .color1{color:red;}
     .color7{color:blue;}
</style>
<title>Insert title here</title>
</head>
<body>
<form>
<% 
		Calendar cal = Calendar.getInstance();
		LocalDate todaysDate = LocalDate.now();
			
		String sYear = request.getParameter("YEAR");
		String sMonth = request.getParameter("MONTH");
		
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH)+1;
				
		if(sYear != null && sMonth != null){
			year = Integer.parseInt(sYear);
			month = Integer.parseInt(sMonth);
		}
		cal.set(year, month-1, 1); 

		int date = cal.get(Calendar.DATE);
		int day = cal.get(Calendar.DAY_OF_WEEK);
				
		int start = cal.getMinimum(Calendar.DATE);
		int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH); 
				  
		int startDay = cal.get(Calendar.DAY_OF_WEEK); 
		
		out.println("<table width='650'><tr><td style='text-align:left'>");
		out.print("<a href = \"calendar.jsp?YEAR=" + (year-1)+ "&MONTH=" + month + "\">" + "◀</a> " );
		out.print(year + "년 ");
		out.print("<a href = \"calendar.jsp?YEAR=" + (year+1) + "&MONTH=" + month + "\">" +  "▶</a></td>" );
		
		if(month > 1){
			out.print("<td><a href = \"calendar.jsp?YEAR=" + year + "&MONTH=" + (month-1) + "\">" +  "◀</a> " );
		}else { out.print("<td>◀ "); } 
			out.print(month + "월 ");
		if(month < 12){
			out.print("<a href = \"calendar.jsp?YEAR=" + year + "&MONTH=" + (month+1) + "\">" +  "▶</a></td>" );
		} else { out.print(" ▶</td>"); }
				
%>
<td style="text-align:right"><% out.println(todaysDate);%></td></tr>
</table>

<table border = "3" class="line" >
<tr>
	<td class="color1"><% out.write(yoil[0]);%></td>
<%
	for(int i =1; i<6; i++){
%>
	<td><% out.write(yoil[i]);%></td>
<% 
	}
%>
	<td class="color7"><% out.write(yoil[6]);%> </td>
</tr>
<% 
	int cnt = 1; 
	for(int i=0; cnt <= end; i++){

%>
<tr>
	<% 
			for(int j=1; j<8; j++){ 
				if (i * 7 + j < startDay  || cnt > end)
					out.println("<td></td>");
				else {
						out.println("<td class='color"+j+"'>");
						out.println((int)cnt++);
						out.println("</td>");
				}
	}%>
</tr>
<% 
}
%>
</table>
</form>
</body>
</html>