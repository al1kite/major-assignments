package jspbook.pr33;

import java.util.ArrayList;
import java.util.List;

public class LectureManager {
	ArrayList<LectureBean> lectureList = new ArrayList<LectureBean>();

	public void add(LectureBean LTbean) {
		lectureList.add(LTbean);
	}

	public List<LectureBean> getLectureList() {
		return lectureList;
	}

}
