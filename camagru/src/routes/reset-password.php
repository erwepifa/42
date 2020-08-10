<?php

require_once '../config/database.php';

function checkPassword($password) {
    // Use two positive lookaheads : https://stackoverflow.com/a/40099300
    $pattern = '/^(?=.*[A-Za-z])(?=.*\d).{6,64}$/';

    if (strlen($_POST['password']) > 64)
        return 1;
    if (!preg_match($pattern, $_POST['password']))
        return 2;
    return 0;
}

function resetPassword($dbh, $email) {
    $code = hash('sha256', random_bytes(32));
    $sql = 'UPDATE User SET resetPassword = :resetPassword WHERE User.email = :email';
    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(':resetPassword', $code);
    $stmt->bindParam(':email', $email);
    $stmt->execute();

    $msg = array(
        "A password reset was requested.\n\n",
        "You can create your new password here: ",
        'http://', $_SERVER['SERVER_NAME'], ':', $_SERVER['SERVER_PORT'],
        '/routes/reset-password.php?code=' . $code . "\n\n",
        "If you didn't request a new password, just ignore this message."
    );

    $headers[] = "From: Camagru <no-reply@camagru.com>";

    mail($email, 'Reset your password', implode("", $msg), implode("\r\n", $headers));
}

function modifyPassword($dbh, $code, $password) {
    $hash = password_hash($password, PASSWORD_BCRYPT);
    $sql = 'UPDATE User SET hash = :hash, resetPassword = null WHERE resetPassword = :code';
    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(':hash', $hash);
    $stmt->bindParam(':code', $code);
    $stmt->execute();

    if (!$stmt->rowCount()) {
        header('refresh:5; url=login.php');
        die('Error. Redirecting to login page in 5 seconds');
    }

}

if (isset($_GET['code'])) {
    include_once '../partials/header.php';
    include_once '../partials/new-password.php';
    include_once '../partials/footer.php';
}

// Actual password modification
else if (isset($_POST['code'])) {
    if (strcmp($_POST['password'], $_POST['password_confirm']) === 0) {
        $check = checkPassword($_POST['password']);

        if ($check == 1)
            die('Password max length (64) exceeded.');
        if ($check == 2)
            die('Password must contain between 6 and 64 characters with letters and numbers .');

        modifyPassword($dbh, $_POST['code'], $_POST['password']);
        header('refresh:5; url=login.php');
        print('Password successfully changed. Redirecting to login page in 5 seconds.');
    } else {
        die('Password and confirmation don\'t match');
    }
}

// Password reset action
else if (isset($_POST['email'])) {
    try {
        resetPassword($dbh, $_POST['email']);
        header('refresh:5; url=login.php');
        print('Check your mails to create a new password. Redirecting to login page in 5 seconds.');
    } catch (Exception $e) {
        die("Couldn't reset password. " . $e->getMessage());
    }
}

else {
    include_once '../partials/header.php';
    include_once '../partials/reset-password.php';
    include_once '../partials/footer.php';
}
