/**
 * @Date March 14, 2023
 * @Brief This Application is to detect the spam message
 * @Author Hengyi Li, Xian Wu, Jingbo Wang
 * @Copyright 2023. Hengyi Li. All right Reserved.
 */
package com.example.readsms;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Environment;
import android.telephony.SmsMessage;
import android.widget.Toast;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Objects;
import java.util.Scanner;
public class SmsReceiver extends BroadcastReceiver
{
  /**
   * The function is called when the SMS is received. It checks the SMS PDU and
   * displays the sender's number and the message body
   * @param context The context of the application.
   * @param intent  The intent that was received.
   */
  @Override
  public void onReceive(Context context, Intent intent)
  {
    Toast.makeText(context, "SMS Received", Toast.LENGTH_LONG).show();
    if (intent.getAction().equals("android.provider.Telephony.SMS_RECEIVED"))
    {
      ArrayList<String> CompareDict = getScamFile(context);
      System.out.println(CompareDict);
      Bundle bundle = intent.getExtras();
      SmsMessage[] msg;
      String msg_from;
      if (bundle != null)
      {
        try
        {
          Object[] pdus = (Object[]) bundle.get("pdus");
          msg = new SmsMessage[pdus.length];
          for (int i = 0; i < msg.length; i++)
          {
            msg[i] = SmsMessage.createFromPdu((byte[]) pdus[i]);
            msg_from = msg[i].getOriginatingAddress();
            String msgBody = msg[i].getMessageBody();
            SplitAndDetect(context, msgBody, CompareDict);
            Toast.makeText(context,
              "From: " + msg_from + "\n" + "Body: " + msgBody,
              Toast.LENGTH_LONG).show();
          }
        } catch (Exception e)
        {
          e.printStackTrace();
        }
      }
    }

  }

  /**
   * It splits the message body into an array of strings, and then compares each
   * string to the dictionary. If it finds a match, it displays a toast message
   * @param context     The context of the application.
   * @param msgBody     The message body of the SMS
   * @param CompareDict This is the dictionary that we will be comparing the
   *                    message body to.
   */
  public void SplitAndDetect(Context context, String msgBody,
                             ArrayList<String> CompareDict)
  {
    String[] detecting = msgBody.split("[,!] ");
    for (int index = 0; index < detecting.length; index++)
    {
      detecting[index] = detecting[index].toLowerCase();
    }
    for (String s : detecting)
    {
      for (int CompareIndex = 0; CompareIndex < CompareDict.size();
           CompareIndex++)
      {
        if (Objects.equals(s, CompareDict.get(CompareIndex)))
        {
          Toast.makeText(context, "Might be a Spam Message!", Toast.LENGTH_LONG)
            .show();
        }
      }
    }
  }

  /**
   * This function reads the csv file and returns an ArrayList of Strings
   * @param context The context of the application.
   * @return An ArrayList of Strings
   */
  public ArrayList<String> getScamFile(Context context)
  {
    ArrayList<String> ScamFile = new ArrayList<String>();
    StringBuilder data = new StringBuilder();
    File file = new File(Environment.getExternalStoragePublicDirectory(
      "/Download/Spam_Scam_Dictionary.csv").getPath());
    try
    {
      Scanner myReader = new Scanner(file);
      while (myReader.hasNextLine())
      {
        data.append(myReader.nextLine());
      }
      String[] keyword = data.toString().split(", ");
      Collections.addAll(ScamFile, keyword);
      myReader.close();
    } catch (FileNotFoundException e)
    {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
    return ScamFile;
  }
}
