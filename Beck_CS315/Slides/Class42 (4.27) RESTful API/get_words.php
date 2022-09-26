<?php
ini_set('display_errors', '1');
error_reporting(E_ALL);

$word_regex = '#/api/([a-z]+)$#';
$no_word_regex = '#/api/$#';

$response = ['error' => 0,
             'message' => '',
             'payload' => ''];

if (preg_match($no_word_regex, $_SERVER['REQUEST_URI']))
{
  require('dblogin.php');
  $db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
                $db_user, $db_pass,
                array(PDO::ATTR_EMULATE_PREPARES => false,
                      PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

  $query = $db->prepare('select w.word, p.part, w.definition
                         from word as w
                         join part as p on w.part_id = p.id
                         order by word, part');
  $query->execute();
  $result = $query->fetchAll(PDO::FETCH_ASSOC);
  echo json_encode($result) . PHP_EOL;
}
elseif (preg_match($word_regex, $_SERVER['REQUEST_URI'], $match))
{
  require('dblogin.php');
  $db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
                $db_user, $db_pass,
                array(PDO::ATTR_EMULATE_PREPARES => false,
                      PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

  $query = $db->prepare('select w.id, w.word, p.part, w.definition
                         from word as w
                         join part as p on w.part_id = p.id
                         where w.word regexp :prefix
                         order by word, part');
  $query->bindValue(':prefix', '^' . $match[1] . '.*');
  $query->execute();
  $result = $query->fetchAll(PDO::FETCH_ASSOC);
  if (count($result) > 0)
  {
    $response['payload'] = $result;
  }
  else
  {
    $response['error'] = 1;
    $response['message'] = 'Word Not Found';
  }
}
else
{
  $response['error'] = 2;
  $response['message'] = 'Ill-formed Request';
}
?>
<?= json_encode($response) . PHP_EOL ?>
