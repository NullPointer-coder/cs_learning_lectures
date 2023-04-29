/**
 * @Date March 14, 2023
 * @Brief This Application is to detect the spam message
 * @Author Hengyi Li, Xian Wu, Jingbo Wang
 * @Copyright 2023. Hengyi Li. All right Reserved.
 */
package com.example.readsms;
import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

public class MainActivity extends AppCompatActivity
{
  private static final int PERMISSION_STATUS = 0; // This is the request code
  Context mContext;

  /**
   * It grants the app the right to send SMS messages.
   * @param savedInstanceState This is a bundle object that contains the
   *                           activity's previously saved state. If the
   *                           activity has never existed before, the value of
   *                           the Bundle object is null.
   */
  @Override
  protected void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    mContext = this.getApplicationContext();
    String[] permissions = {Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE, android.Manifest.permission.RECEIVE_SMS};
    if (!hasPermissions(mContext, permissions))
    {
      System.out.println("here");
      ActivityCompat.requestPermissions(this, permissions, PERMISSION_STATUS);
    }

  }

  /**
   * If the permission is not granted, return false. Otherwise, return true
   * @param context     The context of the activity or fragment.
   * @param permissions The permissions you want to check for.
   * @return A boolean value.
   */
  public boolean hasPermissions(Context context, String[] permissions)
  {
    for (String permission : permissions)
    {
      if (ContextCompat.checkSelfPermission(context,
        permission) != PackageManager.PERMISSION_GRANTED)
      {
        return false;
      }
    }
    return true;
  }


  /**
   * If the user grants the permission, then the app will continue to run. If
   * the user denies the permission, then the app will close
   * @param requestCode  This is the request code that was passed to
   *                     requestPermissions()
   * @param permissions  The array of permissions that were requested.
   * @param grantResults An array of the results of the permission requests.
   */
  @Override
  public void onRequestPermissionsResult(int requestCode,
                                         @NonNull String[] permissions,
                                         @NonNull int[] grantResults)
  {
    super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    System.out.println(requestCode);
    if (requestCode == PERMISSION_STATUS)
    {
      if (grantResults[0] == PackageManager.PERMISSION_GRANTED)
      {
        Toast.makeText(this, "Permission Granted", Toast.LENGTH_LONG).show();
      }
      else
      {
        Toast.makeText(this, "Permission Not Granted!", Toast.LENGTH_LONG)
          .show();
        this.finish();
      }
    }
  }
}