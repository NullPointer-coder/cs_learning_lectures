<?php

/**
 * Jon Beck
 * add a word to the db
 */

error_reporting(E_ALL);
$regex = '/^[a-z]+$/';

$result = ['error' => 0, 'message' => ''];

if (isset($_POST) && isset($_POST['payload']))
{
  $payload = array(json_decode($_POST['payload']));

  if (isset($payload['word']) && preg_match($regex, $payload['word']) &&
      isset($payload['part']) && preg_match($regex, $payload['part']) &&
      isset($payload['defn']))
  {
    $word = $payload['word'];
    $part = $payload['part'];
    $defn = $payload['defn'];

    require('dblogin.php');
    $db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
                  $db_user, $db_pass,
                  array(PDO::ATTR_EMULATE_PREPARES => false,
                        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

    $query = $db->prepare
      ('select count(*) from word as w
        join part as p on w.part_id = p.id
        where w.word = :word and p.part = :part');
    $query->bindValue(':word', $word);
    $query->bindValue(':part', $part);
    $query->execute();
    $duplicate = $query->fetchAll(PDO::FETCH_NUM)[0][0] > 0;
    if ($duplicate)
    {
      $result['error'] = 1;
      $result['message'] = 'Duplicate';
    }
    else
    {
      $query = $db->prepare
        ('insert into word (word, definition, part_id)
          values
          (:word, :defn, (select id from part where part = :part))');

      $query->bindValue(':word', $word);
      $query->bindValue(':part', $part);
      $query->bindValue(':defn', $defn);
      $query->execute();
    }
  }
  else
  {
    $result['error'] = 1;
    $result['message'] = 'Bad params';
  }
}
?>
<?= json_encode($result) . PHP_EOL ?>
