package com.zhm.MyActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity {
	private Button searchBtn = null;
	private EditText nameText = null;
	private DatePicker birthdayDtp = null;
	private TextView starName = null;
	private ImageView showImg = null;
	private int starMsg[] = new int[]{
			R.string.aquarius,
			R.string.pisces,
			R.string.aries,
			R.string.taurus,
			R.string.gemini,
			R.string.cancer,
			R.string.leo,
			R.string.virgo,
			R.string.libra,
			R.string.scorpio,
			R.string.sagittarius,
			R.string.capricornus
	};
	private int starImg[] = new int[]{
			R.drawable.aquarius,
			R.drawable.pisces,
			R.drawable.aries,
			R.drawable.taurus,
			R.drawable.gemini,
			R.drawable.cancer,
			R.drawable.leo,
			R.drawable.virgo,
			R.drawable.libra,
			R.drawable.scorpio,
			R.drawable.sagittarius,
			R.drawable.capricornus
	};
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        showImg = (ImageView)findViewById(R.id.showImg);
        starName = (TextView)findViewById(R.id.starNameTxt);
        birthdayDtp = (DatePicker)findViewById(R.id.birthdayDtp);
        searchBtn = (Button)findViewById(R.id.searchBtn);
        nameText = (EditText)findViewById(R.id.nameEdt);
        
        searchBtn.setOnClickListener(new OnClickListener() {	
			public void onClick(View v) {
				// TODO Auto-generated method stub
				int index = searchStar(birthdayDtp.getMonth(), birthdayDtp.getDayOfMonth());
				String info = MainActivity.this.getString(starMsg[index]);
				starName.setText(nameText.getText() + "\r\n" + info);
				showImg.setImageResource(starImg[index]);
			}
		});
    }
    public int searchStar(int month, int day) {
    	int list[] = new int[] {20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22};
    	if (day < list[month]) {
    		return (month + 12 - 1) % 12;
    	}
    	else {
    		return month;
    	}
    }
}