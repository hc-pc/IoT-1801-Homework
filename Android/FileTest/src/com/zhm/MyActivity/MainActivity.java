package com.zhm.MyActivity;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Toast;
import android.widget.CompoundButton.OnCheckedChangeListener;

public class MainActivity extends Activity {
    /** Called when the activity is first created. */
	private EditText FileNameEdt = null;
	private EditText ContextEdt = null;
	private CheckBox SDStorageChk = null;
	private CheckBox AppendModeChk = null;
	private Button SaveBtn = null;
	private Button OpenBtn = null;
	private int saveMode = 0;
	private boolean IsSd = false;
	private boolean IsAppend = false;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        init();
        Listener();
    }
    
    private void init() {
    	FileNameEdt = (EditText)findViewById(R.id.FileNameEdt);
    	ContextEdt = (EditText)findViewById(R.id.ContextEdt);
    	SDStorageChk = (CheckBox)findViewById(R.id.SDStorageChk);
    	AppendModeChk = (CheckBox)findViewById(R.id.AppendModeChk);
    	SaveBtn = (Button)findViewById(R.id.SaveBtn);
    	OpenBtn = (Button)findViewById(R.id.OpenBtn);
    }
    
    private void Listener() {
    	SDStorageChk.setOnCheckedChangeListener(new OnCheckedChangeListener() {
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				// TODO Auto-generated method stub
				IsSd = isChecked;
				Toast.makeText(MainActivity.this, "isSd: " + IsSd, Toast.LENGTH_SHORT).show();
			}
		});
    	
    	AppendModeChk.setOnCheckedChangeListener(new OnCheckedChangeListener() {
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				// TODO Auto-generated method stub
				IsAppend = isChecked;
				if (isChecked) {
					saveMode = 1;
				}
				else {
					saveMode = 2;
				}
				Toast.makeText(MainActivity.this, "isAppend: " + IsAppend, Toast.LENGTH_SHORT).show();
			}
		});
    }
}