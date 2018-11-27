//由于Java语言的特殊性，这里只写核心代码


import java.util.Scanner;

public class mainclass {
	public static void main(String[] args) {

		Visiter visiter = new Visiter();
		Scanner scanner = new Scanner(System.in);

		for (; ;) {

			visiter.name = scanner.next();
			visiter.age = scanner.nextInt();
			visiter.ticket();

		}

	}
}
