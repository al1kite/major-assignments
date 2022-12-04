<%@ tag language="java" pageEncoding="UTF-8" body-content="scriptless"%>	
<h1><jsp:doBody /></h1>
<%
int sum;
out.println("<table border = '3'>");
	out.println("<tr>"); 
	for(int i=2; i<6; i++){
		out.println("<td style = 'padding:20px;'>"); 
			for(int j=1; j<10; j++){
				sum = i * j;
				out.println(" "+i+"*"+j+"="+sum+" <br>");
			}
		out.println("</td>"); 
	}
	out.println("</tr>"); 
	out.println("<tr>"); 
	for(int i=6; i<10; i++){
		out.println("<td style = 'padding:20px;'>"); 
			for(int j=1; j<10; j++){
				sum = i * j;
				out.println(" "+i+"*"+j+"="+sum+" <br>"); 
			}
			out.println("</td>"); 
	}
	out.println("</tr>"); 
out.println("</table>"); 
%>