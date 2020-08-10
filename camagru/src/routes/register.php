<?php

session_start();

if (isset($_SESSION['user'])) {
    header('Location: capture.php');
    exit;
}

if (isset($_POST['submit'])) {
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
    if (strcmp($_POST['password'], $_POST['password_confirm']) === 0) {
        $check = checkPassword($_POST['password']);

        if ($check == 1)
            die('Password max length (64) exceeded.');
        if ($check == 2)
            die('Password must contain between 6 and 64 characters with letters and numbers .');

        try {
            $stmt = $dbh->prepare('INSERT INTO User (login, hash, email, confirmationCode) VALUES (:login, :hash, :email, :confirmationCode)');
            $hash = password_hash($_POST['password'], PASSWORD_BCRYPT);

            $confirmationCode = hash('sha256', random_bytes(32));
            $stmt->bindParam(':login', $_POST['login']);
            $stmt->bindParam(':hash', $hash);
            $stmt->bindParam(':email', $_POST['email']);
            $stmt->bindValue(':confirmationCode', $confirmationCode);

            $stmt->execute();

            $msg = array(
                "Welcome to Camagru\n\n",
                "To confirm your registration, please visit this link: ",
                'http://', $_SERVER['SERVER_NAME'], ':', $_SERVER['SERVER_PORT'],
                '/routes/confirm-registration.php?code=' . $confirmationCode
            );

            $headers[] = "From: Camagru <no-reply@camagru.com>";

            mail($_POST['email'], 'Welcome', implode("", $msg), implode("\r\n", $headers));

            header('Location: capture.php');
            exit;
        } catch (Exception $e) {
            die('Couldn\'t create new user: ' . $e->getMessage());
        }
    } else
        die('Password mismatch');
} else {
    include_once '../partials/header.php';
    include_once '../partials/register.html';
    include_once '../partials/footer.php';
}

