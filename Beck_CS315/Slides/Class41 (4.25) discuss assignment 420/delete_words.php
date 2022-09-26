<?php

/**
 * Jon Beck
 * delete words from the db based on a list of ids
 */

error_reporting(E_ALL);

if (isset($_POST) && isset($_POST['payload']))
{
  require('dblogin.php');
  $db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
                $db_user, $db_pass,
                array(PDO::ATTR_EMULATE_PREPARES => false,
                      PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

  $query = $db->prepare('delete from word
                         where id = :id');

  foreach (json_decode($_POST['payload']) as $id)
  {
    $query->bindValue(':id', $id);
    $query->execute();
  }
}
?>
