public class Visiter {
	String name;
	int age;
	public void ticket() {
		if (age <= 18) {
			System.out.println(name + "小于十八岁，免费票。");
		}
		else {
			System.out.println(name + "大于十八岁，门票费20RMB。");
		}
	}
}
