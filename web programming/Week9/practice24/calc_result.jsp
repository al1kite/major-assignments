<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <style>
        form {
            display: flex;
			align-items: center;
			justify-content: center; 
        }
        table, th, td {
          border:1px solid #f1eef1; 
        }
        thead {
            text-align: center;
        }
        td.leftright {
        	text-align: center;
            padding-left: 60px;
            padding-right: 60px;
        }
        td.updown{
            padding: 15px;
            background-color: #7bcaf9;
        }
        td.text{
            font-size: 30px;
            background-color: #7bcaf9;
        }
        input.imageAlign { vertical-align:middle; }
        </style>
    <title>이클래스 로그인</title>
</head>
<body>
<%  
int op1 = Integer.valueOf(request.getParameter("operand1"));
int op2 = Integer.valueOf(request.getParameter("operand2"));
String opr = request.getParameter("operator");
int sum = 0;

if (opr.equals("+"))
	sum = op1 + op2;
else if (opr.equals("-"))
	sum = op1 - op2;
else if (opr.equals("*"))
	sum = op1 * op2;
else if (opr.equals("/"))
	sum = op1 / op2;
	
%>
        <table>
            <thead>
                <td colspan="2" class="text"><strong><em>CalCuLaTor</em></strong></td>
            </thead>
            <tbody>    
                <td><img src="./cal.jpg" class="imageAlign" width="100%"></td>
                <td class="leftright">
							<input type="text" value="<%=op1%>" disabled/><br>
							<%=request.getParameter("operator") %><br>
							<input type="text" value="<%=op2%>" disabled/><br>
							<input type=submit value="=" disabled/><br>
							<input type="text" value="<%=sum%>" disabled/><br>
				</td> 
            </tbody>
            <tfoot>
                <td colspan="2" class="updown"><br></td>
            </tfoot>
        </table>
</body>
</html>