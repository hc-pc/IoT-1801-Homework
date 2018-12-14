//由于Java语言的特殊性，这里只写核心代码

public class Vehicle {
	String brand;
	String color;
	double speed;

	public void Vehicle(String setBrand, String setColor) {
		brand = setBrand;
		color = setColor;
		speed = 0;
	}

	public void getBrand() {
		return brand;
	}
	public void getColor() {
		return color;
	}
	public void getSpeed() {
		return speed;
	}

	public void run() {
		System.out.println("汽车行驶中...");
	}

}

class car extends Vehicle{
	int loader;

	public void Vehicle(String setBrand, String setColor, int setLoader) {
		brand = setBrand;
		color = setColor;
		loader = setLoader;
		speed = 0;
	}

	public void run() {
		System.out.println("轿车行驶中...");
	}
}