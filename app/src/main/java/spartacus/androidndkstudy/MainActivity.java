/*
 * @author Thomas Radloff  bostontrader@gmail.com https://bostontrader.github.io/androidNDKStudy
*/
package spartacus.androidndkstudy;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

    public native String stringFromC();
    public native String stringFromCpp();
    public native long longFromC();
    public native long longFromCpp();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnSubmit = (Button) this.findViewById(R.id.btnDoit);
        btnSubmit.setOnClickListener(
            new View.OnClickListener() {

                @Override
                public void onClick(View arg0) {
                    System.loadLibrary("hello-tommy");
                    ((EditText) findViewById(R.id.stringFromC)).setText(stringFromC());
                    ((EditText) findViewById(R.id.stringFromCpp)).setText(stringFromCpp());
                    ((EditText) findViewById(R.id.longFromC)).setText(Long.toString(longFromC()));
                    ((EditText) findViewById(R.id.longFromCpp)).setText(Long.toString(longFromCpp()));
                }
            }
        );
    }
}
