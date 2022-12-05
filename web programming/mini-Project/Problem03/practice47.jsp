<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*"%>
<%@ page import = "jspbook.pr39.*" %>
<% request.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="Lecture" class="jspbook.pr39.LectureBean" scope="request" />
<jsp:useBean id="LectureM" class="jspbook.pr39.LectureManager" scope="session" />
<jsp:setProperty name="Lecture" property="*"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<center>
<form method=post action=practice47.jsp>
	과목타입:<select name=type> 
	<%
 	for (int i = 0; i < LectureBean.typeNames.length; i++) {
 			out.println("<option value="+i+">"+LectureBean.typeNames[i]+"</option>"); 
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
<hr>
<%
int lecture = 0;
if (Lecture.getType() != -1) {
	if(LectureM.getTitleMatrix()[Lecture.getTime()-1][Lecture.getDay()] != -1)
		lecture = 1;
	else {
		for(int i=0; i < Lecture.getConsecutive(); i++)
			if(LectureM.getSpanMatrix()[Lecture.getTime()-1+i][Lecture.getDay()] != 1)
				lecture = 1;
	}
	if (lecture == 1){
		out.println("<script>alert('해당 시간에는 다른 강의가 있습니다. 다시 선택해주세요.')</script>");
	
	} else {
		LectureM.add(Lecture);
		LectureM.buildMatrix();
	}
%>
	<jsp:include page="timeTable.jsp" />
<br>
<hr>
<br>
<% 
		for (LectureBean lb : LectureM.getLectureList()) {
	out.println(LectureBean.typeNames[lb.getType()] + "/");
	out.println(LectureBean.titleNames[lb.getTitle()] + "/");
	out.println(LectureBean.dayNames[lb.getDay()] + "/");
	out.println(lb.getTime() + "/");
	out.println(lb.getConsecutive() + "<br>");
		}
	}
%>
<%
	LectureM.printMatrix(LectureM.getTypeMatrix());
	LectureM.printMatrix(LectureM.getTitleMatrix());
	LectureM.printMatrix(LectureM.getSpanMatrix());
%>
</center>
</body>
</html>