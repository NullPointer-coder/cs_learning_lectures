<?php

if (isset($_COOKIE['username']))
{
  setcookie( 'username', '', time() - 3600 );
  setcookie( 'fullname', '', time() - 3600 );
}

header('Location: home.php');
?>
