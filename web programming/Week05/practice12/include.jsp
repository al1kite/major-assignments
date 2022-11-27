<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <style>
    body {font-family:"굴림"}
        body {
            display: flex;
			align-items: center;
			justify-content: center;
        }
        th,td,caption { padding:10px 5px;}
        th {font-size: 20px;
        text-align: center;}
        td {font-size: 13px;
            text-align: center;}
            .padd{ padding-right:25px; }
    </style>
</head>
<body>
<div align="center">
<h2>include 지시어 연습</h2>
<hr>
<table>
	<tr>
	<td><%@include file="calendar.jsp" %></td>
	<td class="padd"><%@include file="news.jsp" %></td>
	</tr>
</table>
</div>
</body>
</html>
</table>
</body>
</html>