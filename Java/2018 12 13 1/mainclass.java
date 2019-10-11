//由于Java语言的特殊性，这里只写核心代码

public class mainclass {
	public static void main(String[] args) {
		int i;
		Player player = new Player();
		for (i = 1; i < 21; i++) {
			System.out.print(i + "：");
			player.create();
		}
	}
}