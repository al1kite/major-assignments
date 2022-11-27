<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<center>
<h1>주소록</h1>
<br>
<hr>
<%  
request.setCharacterEncoding("UTF-8");
String value = request.getParameter("user_id")+","+request.getParameter("phone_num");
ArrayList<String> addrbook = (ArrayList<String>)application.getAttribute("addr");

if(addrbook == null){
	addrbook = new ArrayList<String>();
}
addrbook.add(value);
application.setAttribute("addr",addrbook);
out.println("<center><ol>");
for(String addrbooks: addrbook){
	out.println("<li>"+addrbooks+"<br>"+"</li>");
}
out.println("</ol></center>");
%>
</center>
</body>
</html>