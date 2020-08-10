<?php

session_start();

require_once '../config/database.php';

if (!isset($_SESSION['user']))
    die('You need to be logged in before you can comment pictures.');

function sendMailNotif($dbh)
{
    $sql = 'SELECT email FROM User INNER JOIN Picture WHERE User.id = Picture.userId AND Picture.id = :pictureId';
    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(':pictureId', $_POST['pictureId']);
    $stmt->execute();
    $res = $stmt->fetch();
    if (!$res)
        die('Error while trying to send mail to picture author.');

    $redirectUrl = array(
        'http://',
        $_SERVER['SERVER_NAME'],
        ':',
        $_SERVER['SERVER_PORT'],
        '/routes/gallery.php?picture=',
        $_POST['pictureId']
    );

    $subject = 'New comment on your picture!';

    $msg = array(
        $_SESSION['user']['login'] . " commented your picture!\n",
        "Here it is:\n\n",
        $_POST['content'] . "\n\n",
        'Check it out here: ',
        implode('', $redirectUrl)
    );

    $headers[] = "From: Camagru <no-reply@camagru.com>";

    mail($res['email'], $subject, implode('', $msg), implode($headers, "\r\n"));
}


$sqlQuery = 'INSERT INTO PictureComment (pictureId, userId, content, creationDate) VALUES (:pictureId, :userId, :content, :creationDate)';
$stmt = $dbh->prepare($sqlQuery);
$stmt->bindParam(':pictureId', $_POST['pictureId']);
$stmt->bindParam(':userId', $_SESSION['user']['id']);
$stmt->bindParam(':content', $_POST['content']);
$stmt->bindParam(':creationDate', date("Y-m-d H:i:s"));
$stmt->execute();

sendMailNotif($dbh);

header('Location: gallery.php?picture=' . $_POST['pictureId']);
