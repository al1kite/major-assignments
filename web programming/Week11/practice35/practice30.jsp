<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*"%>
    <%@ page import = "jspbook.pr35.LectureBean" %>
<% request.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="Lecture" class="jspbook.pr35.LectureBean" scope="page" />
<jsp:setProperty name="Lecture" property="*"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<center>
<form method=post action=practice30.jsp>
	과목타입:<select name=type> 
	<%
 	for (int i = 0; i < LectureBean.typeNames.length; i++) {
 			out.println("<option value="+i+" name=type>"+LectureBean.typeNames[i]+"</option>"); 
 		}
 	%>
	</select> 
	
	과목명:<select name=title> 
	<%
 	for(int i=0; i<LectureBean.titleNames.length; i++){
 			out.println("<option value="+i+">"+LectureBean.titleNames[i]+"</option>"); 
 		}
 	%>
	</select> 

	요일:<select name=day> 
	<%
 	for(int i=0; i<LectureBean.dayNames.length; i++){
 			out.println("<option value="+i+">"+LectureBean.dayNames[i]+"</option>"); 
 		}
 	%>
	</select> 
	
	시간:<select name=time> 
	<%
 	for(int i=1; i<8; i++){
 			out.println("<option value="+i+">"+i+"</option>"); 
 		}
 	%>
	</select> 
	
	연강여부:<select name=consecutive> 
		<%
 		for(int i=1; i<5; i++){
 				out.println("<option value="+i+">"+i+"</option>"); 
 			}
 		%>
	<input type="submit" value="등록">
</form>
<%
	if (Lecture.getType() != -1) {
		Lecture.add(Lecture);
		
	}
%>
<%
if (Lecture.getType() != -1) {
		for (LectureBean lb : Lecture.getLectureList()) {
	out.println(LectureBean.typeNames[lb.getType()] + "/");
	out.println(LectureBean.titleNames[lb.getTitle()] + "/");
	out.println(LectureBean.dayNames[lb.getDay()] + "/");
	out.println(lb.getTime() + "/");
	out.println(lb.getConsecutive() + "<br>");
		}
	}
%>
</center>
</body>
</html>