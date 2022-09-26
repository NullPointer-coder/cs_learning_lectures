<?php
/**
 * a program to supply the words in a file in JSON format
 * @author Jon Beck
 * @version 2 April 2022
 */

error_reporting(E_ALL);

define('FILENAME', 'words.txt');

$file = fopen(FILENAME, 'r');
$result = [];
while (($line = fgets($file)) !== false)
{
  $result[] = explode("\t", rtrim($line));
}
?>
<?= json_encode($result) ?>
