<?php
/**
 * a program to supply a list of words based on a search criterion
 * in JSON format
 * @author Jon Beck
 * @version 14 March 2022
 */

error_reporting(E_ALL);
ini_set('display_errors', '1');

define('DEFINITION_FILENAME', 'words.txt');
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

$result = [];
if (isset($_GET) &&
  isset($_GET['search']) && preg_match('/^[a-z]+$/', $_GET['search']))
{
  $search = $_GET['search'];
  $word_list = read_file_into_array(DEFINITION_FILENAME);

  foreach ($word_list as $array)
  {
    if (preg_match("/^$search.*/", $array[0]))
    {
      $result[] = $array[0] . '_' . $array[1];
    }
  }
}
?>
<?= json_encode($result) ?>
