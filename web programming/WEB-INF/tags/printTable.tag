<%@ tag language="java" pageEncoding="UTF-8" body-content="scriptless"%>
<%@ attribute name="color" %>
<%@ attribute name="brd" %>
<%request.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="Login" class="jspbook.pr38.LoginBean" scope="application"/>
<jsp:setProperty name="Login" property="*"/>
<center>
<h1><jsp:doBody /></h1>
<table border=1 cellspacing="${brd }" cellpadding= "5" bgcolor="${color}">
<tr>
<td>이름</td>
<td>${param.id }</td>
</tr>
<tr>
<td>전화번호</td>
<td>${param.pw }</td>
</tr>
<tr>
<td>이메일</td>
<td>${param.email }</td>
</tr>
<tr>
<td>성별</td>
<td>
${param.gender }
</td>
</tr>
<tr>
<td>생일</td>
<td>
${param.birth }
</td>
</tr>
<tr>
<td colspan="2">
<%
	out.println(Login.getId()+"씨는 ");
	if(Login.getGender().equals(1)){
		out.print("남성이고, ");
	}
	else{
		out.print("여성이고, ");
	}

	if(Login.isGrownUp()){
		out.print("성인입니다.");
	}
	else{
		out.print("성인이 아닙니다.");
	}
%>
</td>
</tr>
</table>
</center>