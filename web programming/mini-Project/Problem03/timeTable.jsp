<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*"%>
<%@ page import = "jspbook.pr39.*" %>
<jsp:useBean id="Lecture" class="jspbook.pr39.LectureBean" scope="request" />
<jsp:useBean id="LectureM" class="jspbook.pr39.LectureManager" scope="session" />
<jsp:setProperty name="Lecture" property="*"/>
<%
	int[][] lectureType = LectureM.getTypeMatrix();
	int[][] consecutive = LectureM.getSpanMatrix();
	int[][] lectureTitle = LectureM.getTitleMatrix();
	
	String[] titleNames = {
	"웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", 
	"자료구조", "네트워크", "창의와감성", "사회봉사"
	}; 
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice31</title>
  <style>
	body{
	font-family:"굴림";
	display:flex;
	justify-content:center;
	align-items:center;
	}
	td, th {
	width:90px;
	height:50px;
    text-align:center;
    }
    table, th, td {
    border:1px solid #000000;
    border-collapse: collapse;
    }        
    th {font-size: 20px;}     
    td {font-size: 13.5px;}
    .color0 {
    background-color: #f5e198;
    }   
    .color1 {
    background-color: #bcccfa; 
    }       
    .color2 { 
    background-color: #bdbdbd;
    }
    </style>
</head>
<body>
<div align=center>
<h3>강의 시간표</h3>
   <table >
        <thead>
            <tr>
                <th>2학년</th>
                <th>월</th>
                <th>화</th>
                <th>수</th>
                <th>목</th>
                <th>금</th>
            </tr>
        </thead> 
<%
	for(int i = 0; i < 6 ; i++) {
		out.println("<tr>");
		out.println("<th>" + (i + 1) + "</th>");
		for(int j = 0; j < 5; j++) {
			if (consecutive[i][j] == 0)
				continue;
			else if(lectureTitle[i][j] == -1) 
				out.println("<td> &nbsp </td>");
			else {
				out.print("<td rowspan='" + consecutive[i][j] + "' class='color" + lectureType[i][j] + "'>");
				out.print(titleNames[lectureTitle[i][j]]);
				out.print("</td>");
			}
		}
		out.println("</tr>");
	}
%> 
	</table>
</div>
</body>
</html>