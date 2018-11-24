//由于Java语言的特殊性，这里只写核心代码

import java.Math
import java.util.Scanner

public class /*文件名*/ {

	public static void main() {
		int a, b;
		a = (int)(1 + Math.random() * 10);
		b = (int)(1 + Math.random() * 10);
		Scanner scanner = new Scanner(System.in);

		hello();
		add(a, b);
		addprint(a, b);
		factorial()
		while (true) {
			yearJudge(scanner().nextInt);
		}
	}
	
	public static void hello() {
		System.out.println("Hello_World");
	}

	public static int add(int a, int b) {
		return a + b;
	}

	public static int add(int a, int b) {
		System.out.println(a + b);
	}

	public static int factorial() {
		int i;
		int toReturn;
		for (i = 1; i <= 5; i++) {
			toReturn = toReturn * i;
		}
		return toReturn;
	}

	public static int yearJudge(int year) {
		if (year % 4 == 0 && year % 100 != 0) {
			System.out.println(year + "是闰年");
		}
		else if (year % 400 == 0) {
			System.out.println(year + "是闰年");
		}
		else {
			System.out.println(year + "不是闰年");
		}
	}

}
