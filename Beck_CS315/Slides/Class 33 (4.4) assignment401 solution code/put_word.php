<?php
/**
 * a program to accept POST data
 * in JSON format
 * @author Jon Beck
 * @version 21 March 2022
 */

error_reporting(E_ALL);

define('FILENAME', 'words.txt');
define('LOGFILE', 'log.txt');

/**
 * write a string to the log file
 * @param s the string to write
 */
function logger($s)
{
  $file = fopen(LOGFILE, 'a');
  fwrite($file, $s . PHP_EOL);
  fclose($file);
}

/**
 * read a file of tab-separated lines into an array of arrays
 * @param $filename the name of the file to read
 * @return an array of arrays with the contents of the file
 */
function read_file_into_array($filename)
{
  $file = fopen($filename, 'r');
  $array = array();
  while (($line = fgets($file)) !== false)
  {
    $array[] = explode("\t", rtrim($line));
  }
  return $array;
}

/**
 * convert an array of 3-element arrays into tab-separated
 * strings and output the result to a file
 * @param $filename the name of the file to write
 * @param $array the array of arrays
 */
function put_a_file($filename, $array)
{
  $file = fopen($filename, 'w');
  foreach ($array as $row)
  {
    fwrite($file, implode("\t", $row) . PHP_EOL);
  }
  fclose($file);
}

/**
 * add a three-element array to an array, in alphabetic order
 * by concatenation of the first two elements
 * @param $words the original array, passed by reference
 * @param $word the first element to add
 * @param $part the second element to add
 * @param $definition the third element to add
 * @return true if the add was successful; false otherwise
 */
function add_an_entry(&$words, $word, $part, $definition)
{
  $word_and_part = $word . $part;
  if (strcmp($word_and_part, end($words)[0] . end($words)[1]) > 0)
  {
    $words[] = [$word, $part, $definition];
    return true;
  }

  if (strcmp($word_and_part, $words[0][0] . $words[0][1]) < 0)
  {
    array_unshift($words, [$word, $part, $definition]);
    return true;
  }

  $spot_to_insert = 0;
  while ($spot_to_insert < count($words) &&
         strcmp($word_and_part,
                $words[$spot_to_insert][0] . $words[$spot_to_insert][1]) > 0)
  {
    $spot_to_insert++;
  }

  if (strcmp($word, $words[$spot_to_insert][0]) == 0 &&
      strcmp($part, $words[$spot_to_insert][1]) == 0)
  {
    return false; // duplicate
  }

  for ($index = count($words) - 1; $index >= $spot_to_insert; $index--)
  {
    $words[$index + 1] = $words[$index];
  }

  $words[$spot_to_insert] = [$word, $part, $definition];
  return true;
}

logger("started");
$word_ok = false;
$part_ok = false;
$defn_ok = false;
if (isset($_POST) && isset($_POST['payload']))
{
  $data = json_decode($_POST['payload']);
  if (isset($data[0]) && preg_match('/^[a-z]+$/', $data[0]))
  {
    $word = $data[0];
    $word_ok = true;
  }

  if (isset($data[1]) && preg_match('/^[a-z]+$/', $data[1]))
  {
    $part = $data[1];
    $part_ok = true;
  }

  if (isset($data[2]))
  {
    $defn = htmlentities($data[2]);
    $defn_ok = true;
  }
}
logger(print_r($data, $return = true));

if ($word_ok && $part_ok && $defn_ok)
{
  $wordlist = read_file_into_array(FILENAME);
  add_an_entry($wordlist, $word, $part, $defn);
  put_a_file(FILENAME, $wordlist);
}
?>
