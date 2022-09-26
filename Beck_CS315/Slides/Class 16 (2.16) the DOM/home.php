<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

$loggedin = isset($_COOKIE['username']) && isset($_COOKIE['fullname']);
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta name="author" content="Jon Beck" />
    <link rel="icon" href="/favicon.ico" type="image/x-icon" />
    <link rel="stylesheet" href="cookies.css" />
    <title>Cookie Demo</title>
  </head>

  <body>
    <header><h1>ACME Website</h1></header>

    <aside>
      <p>
        <?php if ($loggedin): ?>
          <a href="logout.php">Logout</a>
        <?php else: ?>
          <a href="login.php">Login</a>
        <?php endif; ?>
      </p>
    </aside>

    <section>
      <h2>
        <?php if ($loggedin): ?>
          You Can Edit
        <?php else: ?>
          Here is
        <?php endif; ?>
        Our Public Data
      </h2>

      <?php $data = array('Foo', 'Bar', 'Bim', 'Bam'); ?>
      <ul>
        <?php foreach($data as $item): ?>
          <li>
            <?php if ($loggedin): ?>
              <a href="<?= $item ?>.php"><?= $item ?></a>
            <?php else: ?>
              <?= $item ?>
            <?php endif; ?>
          </li>
        <?php endforeach; ?>
      </ul>

    </section>
  </body>
</html>
