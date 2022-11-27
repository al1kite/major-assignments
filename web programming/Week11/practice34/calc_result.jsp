<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.ch11.*" import="java.util.*"%>
<% request.setCharacterEncoding("UTF-8"); %>

<jsp:useBean id="calc" class="jspbook.ch11.Calculator" scope="page" />
<jsp:setProperty name="calc" property="*" />
 
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
    <title>계산기</title>
</head>
<body>
        <table>
            <thead>
                <td colspan="2" class="text"><strong><em>CalCuLaTor</em></strong></td>
            </thead>
            <tbody>    
                <td><img src="./cal.jpg" class="imageAlign" width="100%"></td>
                <td class="leftright">
				<jsp:getProperty name="calc" property="op1" /><p>
				<jsp:getProperty name="calc" property="operator" /><p>
				<jsp:getProperty name="calc" property="op2" /><p>
				=<p>
				<%= calc.calc(calc.getOp1(), calc.getOp2(), calc.getOperator()) %>
				</td>
			</tbody>
            <tfoot>
                <td colspan="2" class="updown"><br></td>
            </tfoot>
        </table>
</body>