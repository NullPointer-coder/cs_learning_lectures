<?php
/**
 * a program to accept POST data
 * in JSON format
 * @author Jon Beck
 * @version 21 March 2022
 */

error_reporting(E_ALL);
ini_set('display_errors', '1');

define('FILE', 'json_results.txt');

if (isset($_POST) && isset($_POST['payload']))
{
  $json_data = json_decode($_POST['payload']);
  $file = fopen(FILE, 'a');

  foreach ($json_data as $key => $value)
  {
    fwrite($file, "$key: $value\n");
  }
  fclose($file);
}
?>
