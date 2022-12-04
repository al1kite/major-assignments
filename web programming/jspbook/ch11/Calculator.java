package jspbook.ch11;

public class Calculator {
	private int op1;
	private int op2;
	private String operator;

	public int getOp1() {
		return this.op1;
	}

	public void setOp1(int op1) {
		this.op1 = op1;
	}

	public int getOp2() {
		return this.op2;
	}

	public void setOp2(int op2) {
		this.op2 = op2;
	}

	public String getOperator() {
		return this.operator;
	}

	public void setOperator(String operator) {
		this.operator = operator;
	}

	public int calc(int a, int b, String op) {
		if (op.equals("+")) {
			return this.add(a, b);
		} else if (op.equals("-")) {
			return this.sub(a, b);
		} else if (op.equals("*")){
			return this.mult(a, b); 
		} else {
			return this.div(a, b);
		}
	}

	private int add(int a, int b) {
		return a + b;
	}

	private int sub(int a, int b) {
		return a - b;
	}

	private int mult(int a, int b) {
		return a * b;
	}

	private int div(int a, int b) {
		return a / b;
	}
}
