<!DOCTYPE html>
<html lang="en">
  <head>
    <title>HTML REGEX</title>
    <meta charset="utf-8" />
    <meta name="author" content="Jon Beck" />
    <link rel="stylesheet" href="checkre.css" />
  </head>

  <body>
    <h1>Regular Expressions in Form Elements</h1>
    <h2>Echoing Data Sent to This URL</h2>

    <?php if (isset($_POST) && count($_POST) > 0): ?>
      <h3>POST Data Sent to This PHP Program</h3>

      <pre>
        <?php foreach ($_POST as $parameter => $value): ?>
        $_POST[<?= $parameter ?>]: &ldquo;<?= $value ?>&rdquo;
        <?php endforeach; ?>
      </pre>
    <?php endif; ?>

    <form action="htmlre.php" method="post">
    <p>
      <label for="first">A Number With 2 Decimal Places: </label>
      <input type="text" id="first" name="first" autofocus
       placeholder="nn.nn" pattern="\d+\.\d{2}" />
    </p>

    <p>
      <label for="text">Uppercase String: </label>
      <input type="text" size="30" id="text" name="text"
       placeholder="UPPERCASE ONLY" pattern="[A-Z]+" />
    </p>

    <p>
      <input type="submit" value="Submit" />
    </p>

    </form>
  </body>
</html>
