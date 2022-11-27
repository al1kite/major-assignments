<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" isErrorPage="true"%>
<%@ page import="java.util.*" %>
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
<meta "charset="UTF-8">
<title>Insert title here</title>
    <meta charset="UTF-8">
    <style>
    body {font-family:"굴림"}
        div, table {
            display: flex;
            align-items: center;
			justify-content: center; 
        }
        td {font-size: 20px;
        text-align: center;
        background-color: #f5dbbd;
        padding: 10px 300px;
    }
    th{
        font-size: 20px;
        background-color: #faefd8;
    }
        .blank {
            background-color: #fdfea7;
        }
    </style>
	<%! 
		Calendar cal;
	%>
	<% 
		cal = Calendar.getInstance();
	%>
    <title>notice</title> 
</head>
<body>
    <br><br>
        <form>
            <table name = "frm1">
                <tr>
                    <td><strong>오류가 발생했습니다.</strong></td>
                </tr>
                <tr>
                    <th>
                        <br><br><br><br>
                        <input type=image src="./flower.gif" class="imageAlign" width="180px">
                        <br><br>
                        오류 발생 시간: 
                        <% 
						int year = cal.get(Calendar.YEAR);
						int month = cal.get(Calendar.MONTH)+1;
						int date = cal.get(Calendar.DATE);
						int hour = cal.get(Calendar.HOUR);
						int minute = cal.get(Calendar.MINUTE);
						int second = cal.get(Calendar.SECOND);
						int day = cal.get(Calendar.DAY_OF_WEEK);
						%>
						<%= year + " 년" + month + "월" + date + "일" + hour +"시" + minute + "분" + second + "초 입니다.<br>" %>
                        최대한 빨리 조치하겠습니다.
                        <br><br><br><br>
                    </th>
                </tr>
            </table>
        </form>
</body>
</html>