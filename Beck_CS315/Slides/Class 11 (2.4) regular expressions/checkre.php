<!DOCTYPE html>
<html lang="en">
  <head>
    <title>RE Checker</title>
    <meta charset="utf-8" />
    <meta name="author" content="Jon Beck" />
    <link rel="stylesheet" href="checkre.css" />
  </head>

  <body>
    <h1>Check Your Regular Expression</h1>

    <p>
      The delimiter used is &ldquo;+&rdquo;, so don&rsquo;t use a + in
      the pattern.
    </p>

    <?php
      if (count($_POST) > 0)
      {
        $re = $_POST['re'] ?? '';
        $text = $_POST['text'] ?? '';

        if (preg_match("+$re+", $text)): ?>
          <p id="match"><?= $re ?> matches <?= $text ?></p>
        <?php else: ?>
          <p id="nomatch"><?= $re ?> does not match <?= $text ?></p>
        <?php endif;
      }
    ?>

    <form action="checkre.php" method="post">
    <div id="container">
      <div>
        <label for="re">RE: </label>
      </div>
      <div class="input_box">
        <input type="text" size="30" id="re" name="re" required autofocus />
      </div>
      <div>
        <label for="text">String: </label>
      </div>
      <div class="input_box">
        <input type="text" size="30" id="text" name="text" />
      </div>
      <div id="submit_row">
        <input type="submit" value="Submit" />
      </div>
    </div>
    </form>
  </body>
</html>
