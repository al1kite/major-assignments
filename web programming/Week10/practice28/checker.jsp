<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html>
<%
	request.setCharacterEncoding("UTF-8");
	String act = (String)request.getParameter("action");
	
	if(act.equals("login")) {
		String username = (String)request.getParameter("user");
		String password = (String)request.getParameter("passwd");
		if(username != null && password.equals("hatter")) {
			session.setAttribute("user", username);
		}
		response.sendRedirect("index.jsp");
	}
	else {
		session.invalidate();
		response.sendRedirect("index.jsp");
	}
%>