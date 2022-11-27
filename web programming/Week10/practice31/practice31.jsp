<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%!
	int[][] lectureType ={
		{0, 1, 1, 0, 1}, 
		{1, 0, 0, 0, 2}, 
		{0, 0, 2, 0, 4}, 
		{2, 3, 0, 3, 0},
		{0 ,0, 0, 2, 0}, 
		{0, 0, 0, 0, 0} 
	};
	
	int[][] consecutive = {
		{1, 2, 1, 1, 1}, 
		{2, 0, 1, 1, 1}, 
		{0, 1, 1, 1, 4}, 
		{2, 1, 1, 1, 0}, 
		{0, 1, 1, 2, 0}, 
		{1, 1, 1, 0, 0}
	};
	
	int[][] lectureTitle = {
		{-1, 4, 5, -1, 5}, 
		{3, -1, -1, -1, 1}, 
		{-1, -1, 1, -1, 7}, 
		{0, 6, -1, 6, -1}, 
		{-1, -1, -1, 2, -1}, 
		{-1, -1, -1, -1, -1}
	};
	
	String[] titleNames = {
	"웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", 
	"자료구조", "네트워크", "창의와감성", "사회봉사"
	}; 
%>
<html>
<head>
<meta charset="UTF-8">
<title>Practice31</title>
  <style>
        body {
            display: flex;
			align-items: center;
			justify-content: center;
        }
        table, th, td {
          border:1px solid #000000;
          border-collapse: collapse;
        }
        th,td,caption { padding:10px 5px;}
        th {font-size: 20px;
        text-align: center;}
        td {font-size: 13px;
            text-align: center;}
        .type1 {
            background-color: #f5e198;
        }
        
        .type2 {
            background-color: #bcccfa; 
        }
        
        .type3 {
            background-color: #bdbdbd;
        }
    </style>
</head>
<body>
<div align=center><h3>강의 시간표</h3>
   <table>
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
		out.println("<td>" + (i + 1) + "</td>");
		for(int j = 0; j < 5; j++) {
			if(consecutive[i][j] == 0)
				continue;
			else if(lectureTitle[i][j] == -1) {
				out.println("<td></td>");
			}
			else {
				out.println("<td rowspan='" + consecutive[i][j] + "' class='type" + lectureType[i][j] + "'>" + titleNames[lectureTitle[i][j]]);
				out.println("</td>");
			}
		}
		out.println("</tr>");
	}
%> 
        </table>
        </div>
</body>
</html>