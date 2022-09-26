<?php
/**
 * a program to supply a list of words based on a search criterion
 * @author Jon Beck
 * @version 23 Feb 2022
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

if (isset($_GET) &&
    isset($_GET['search']) && preg_match('/^[a-z]+$/', $_GET['search']))
{
  $search = $_GET['search'];
  $word_list = read_file_into_array(DEFINITION_FILENAME);

  foreach ($word_list as $array) : ?>
    <?php if (preg_match("/^$search.*/", $array[0])) : ?>
      <?php $wordpart = $array[0] . '_' . $array[1]; ?>
      <div>
        <input type="radio" value="<?= $wordpart ?>"
               name="wordradio" id="<?= $wordpart ?>" />
      </div>
      <div>
        <label for="<?= $wordpart ?>" ><?= $array[0] ?></label>
      </div>
      <div><?= $array[1] ?></div>
    <?php endif; ?>
  <?php endforeach;
}
?>
