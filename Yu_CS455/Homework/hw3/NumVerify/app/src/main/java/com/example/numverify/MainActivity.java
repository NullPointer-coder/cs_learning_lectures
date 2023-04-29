package com.example.numverify;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
public class MainActivity extends AppCompatActivity {
    // Set endpoint and your access key, you need to get access key for API first.
    // Please go to https://numverify.com/
    public String access_key = "a8gJIUDl3uR8dyOhAj1YDeWgUxP2Ezpj";
    // Input the number you want to query
    public String phone_number = "+18165419947";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView mStatusTextView = (TextView) findViewById(R.id.status_text);

        // Instantiate the RequestQueue.
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="https://api.apilayer.com/number_verification/validate" +
          "?number="+ phone_number + "&apikey=" + access_key;


        // Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        if (response!= null) {
                            // mStatusTextView.setText("Response is: " + response.substring(0, 500));
                            mStatusTextView.setText("Response is: " + response);
                        } else {
                            mStatusTextView.setText("There is nothing in the response");
                        }
                    }
                }, new Response.ErrorListener() {
                        @Override
                        public void onErrorResponse(VolleyError error) {
                            // mStatusTextView.setText("That didn't work!");
                            mStatusTextView.setText(error.toString());
                        }
                   });
        // Add the request to the RequestQueue.
        queue.add(stringRequest);
    }
}