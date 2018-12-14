//由于Java语言的特殊性，这里只写核心代码

public class Players{

	private int sum = 11;
	private int created = 0;

	public int Player() {
		return sum;
	}

	public void create() {
		if (created < 12) {
			System.out.println("创建了一个对象。");
			created++;
		}
		else {
			System.out.println("对不起，已经创建了 11 个对象，不可以再创建了。");
		}
	}

}