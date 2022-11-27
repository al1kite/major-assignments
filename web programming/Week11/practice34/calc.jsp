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
    <title>계산기</title>
</head>
<body>
<form method=post action="calc_result.jsp">
        <table>
            <thead>
                <td colspan="2" class="text"><strong><em>CalCuLaTor</em></strong></td>
            </thead>
            <tbody>    
                <td><img src="./cal.jpg" class="imageAlign" width="100%"></td>
                <td class="leftright">
							<input type="text" name=op1><br>
							<select name=operator>
                        		<option value="+" selected>+</option>
                        		<option value="-">-</option>
                        		<option value="*">*</option>
                        		<option value="/">/</option>
                        	</select><br>
							<input type="text" name=op2><br>
							<input type=submit value="="><br>
							<input type="text" disabled/><br>
				</td> 
            </tbody>
            <tfoot>
                <td colspan="2" class="updown"><br></td>
            </tfoot>
        </table>
</form>
</body>
</html>