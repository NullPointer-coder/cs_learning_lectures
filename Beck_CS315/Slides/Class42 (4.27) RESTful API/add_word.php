<?php
ini_set('display_errors', '1');
error_reporting(E_ALL);

$response = ['error' => 0,
             'message' => '',
             'payload' => ''];

$word_part_regex = '#/api/([a-z]+)_([a-z]+)$#';

if (preg_match($word_part_regex, $_SERVER['REQUEST_URI'], $match))
{
  require('dblogin.php');
  $db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
                $db_user, $db_pass,
                array(PDO::ATTR_EMULATE_PREPARES => false,
                      PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

  $query = $db->prepare('delete from word
                         where word = :word and
                         part_id = (select id from part where part = :part)');
  $query->bindValue(':word', $match[1]);
  $query->bindValue(':part', $match[2]);
  $return_value = $query->execute();
}
else
{
  $response['error'] = 2;
  $response['message'] = 'Ill-formed Request';
}
?>
<?= json_encode($response) . PHP_EOL ?>
