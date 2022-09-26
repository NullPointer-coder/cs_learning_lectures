<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta name="author" content="Owen" />
    <title>Report an Abduction</title>
    <link rel="stylesheet" href="reportform.css" />
  </head>

  <body>
    <h1>Aliens Abducted Me</h1>
    <h2>Report an Abduction</h2>

    <?php
    /* define('RESULTS_FILE', '/home/jbeck/crs/211/315/c09phpform/results.txt'); */
    define('RESULTS_FILE', 'results.txt');
    $name = $_POST['firstname'] . ' ' . $_POST['lastname'];
    $when_it_happened = $_POST['whenithappened'];
    $how_long = $_POST['howlong'];
    $how_many = $_POST['howmany'];
    $eye_color = $_POST['eyecolor'];
    $what_they_did = $_POST['whattheydid'];
    $fang_spotted = $_POST['spotted'];
    $email = $_POST['email'];
    $other = $_POST['other'];
    $msg = "$name was abducted on $when_it_happened and was gone for $how_long days.
Number of aliens: $how_many
Eye color: $eye_color
They did: $what_they_did
Fang spotted: $fang_spotted
Other comments: $other
----------------------------------------------------
";

    file_put_contents(RESULTS_FILE, $msg, LOCK_EX | FILE_APPEND)
    ?>
    <p>
      Thanks for submitting the form.
    </p>

    <p>
      You were abducted on <?= $when_it_happened ?>
      and were gone for <?= $how_long ?> days.
    </p>

    <p>
      There were <?= $how_many ?> aliens and their eye color was
      <?= $eye_color ?>.
    </p>

    <p>
      They <?= $what_they_did ?>
    </p>

    <p>
      Was Fang there? <?= $fang_spotted ?>
    </p>

    <p>
      Other comments: <?= $other ?>
    </p>

  </body>
</html>
