<?php

session_start();

if (isset($_SESSION['user'])) {
    header('Location: capture.php');
    exit;
}

if (isset($_POST['submit'])) {
    require_once '../config/database.php';

    $stmt = $dbh->prepare('SELECT id,hash,active FROM User WHERE login LIKE :login');
    $stmt->bindParam('login', $_POST['login']);
    $stmt->execute(); 
    if ($stmt->rowCount() === 0) 
        die('Authentication error'); 
    $res = $stmt->fetch();
    $hash = $res['hash']; 
    if (password_verify($_POST['password'], $hash)) { 
        if (!$res['active'])
            die('Account not activated yet. Check your mails.');

        $_SESSION['user'] = [
            'login' => $_POST['login'],
            'id' => $res['id']
        ];
        header('Location: capture.php');
        exit;
    } else 
        die('Authentication error.');
} else { 
    include_once '../partials/header.php';
    include_once '../partials/login.html';
    include_once '../partials/footer.php';
}
