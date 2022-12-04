package jspbook.pr39;

import java.util.*;

public class LectureManager {
	Scanner scanner = new Scanner(System.in);
	ArrayList<LectureBean> lectureList = new ArrayList<LectureBean>();
	private static final int times = 6;
	private static final int days = 5;
	private static  int i = 0, j = 0; 
	
	private int[][] typeMatrix = new int[times][days];
	private int[][] titleMatrix = new int[times][days];
	private int[][] spanMatrix = new int[times][days];
	
	public LectureManager() {
		for (int i = 0; i < times; i++) {
			for (int j = 0; j < days; j++) {
				this.typeMatrix[i][j] = 0;
				this.titleMatrix[i][j] = -1;
				this.spanMatrix[i][j] = 1;
			}
		}

	}
	public int[][] getTypeMatrix() {
		return this.typeMatrix;
	}

	public void setTypeMatrix(int[][] typeMatrix) {
		this.typeMatrix = typeMatrix;
	}

	public int[][] getTitleMatrix() {
		return this.titleMatrix;
	}

	public void setTitleMatrix(int[][] titleMatrix) {
		this.titleMatrix = titleMatrix;
	}

	public int[][] getSpanMatrix() {
		return this.spanMatrix;
	}

	public void setSpanMatrix(int[][] spanMatrix) {
		this.spanMatrix = spanMatrix;
	}

	public void add(LectureBean LTbean) {
		lectureList.add(LTbean);
	}

	public List<LectureBean> getLectureList() {
		return lectureList;
	}
	
	public void buildMatrix() {
		for (LectureBean lb : getLectureList()) {
			this.typeMatrix[lb.getTime()-1][lb.getDay()] = lb.getType();
			this.titleMatrix[lb.getTime()-1][lb.getDay()] = lb.getTitle();
			if(lb.getConsecutive() > 1) {
				this.spanMatrix[lb.getTime()-1][lb.getDay()] = lb.getConsecutive();
				for(i=1; i < lb.getConsecutive(); i++) {
					this.spanMatrix[lb.getTime()-1 + i][lb.getDay()] = 0;
				}
				
			}
		}
	
	}
	public static void printMatrix(int[][] matrix) {
		for (i=0; i<times; i++) {
			for(j=0; j<days; j++) 
				System.out.print(matrix[i][j]);
			 System.out.println();
		}
	}

}
