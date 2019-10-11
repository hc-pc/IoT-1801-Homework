package com.zhm.MyActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends Activity {
	private int imageList[] = new int[]{R.drawable.a, R.drawable.c, R.drawable.d, R.drawable.e, R.drawable.f};
	private int i = 0;
	private ImageView image;
	private Button changeBtn;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        image = (ImageView)findViewById(R.id.image);
        changeBtn = (Button)findViewById(R.id.changeBtn);
        
        changeBtn.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				// TODO Auto-generated method stub

				image.setImageResource(imageList[i]);
				i++;
				i = i % 5;
			}
		});
    }
}