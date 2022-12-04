package jspbook.pr38;

public class LoginBean {
	private String id;
	private String pw;
	private Integer gender;
	private String email;
	private String birth;

	public String getId() {
		return this.id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getPw() {
		return this.pw;
	}

	public void setPw(String pw) {
		this.pw = pw;
	}

	public Integer getGender() {
		return this.gender;
	}

	public void setGender(Integer gender) {
		this.gender = gender;
	}

	public String getEmail() {
		return this.email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getBirth() {
		return this.birth;
	}

	public void setBirth(String birth) {
		this.birth = birth;
	}

	public boolean isGrownUp() {
		String[] dArray = this.birth.split("-");
		return (2020 - Integer.parseInt(dArray[0])) >= 20;
	}
}