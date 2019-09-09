package com.zhm.MyActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
	private TextView displayText;
	private EditText inputText;
	private Button displayBtn;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        displayText = (TextView)findViewById(R.id.displayText);
        inputText = (EditText)findViewById(R.id.inputEdit);
        displayBtn = (Button)findViewById(R.id.displayBtn);
        
        displayBtn.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				// TODO Auto-generated method stub
				displayText.setText(inputText.getText().toString());
			}
		});
    }
}