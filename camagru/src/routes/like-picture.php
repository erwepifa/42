<?php

session_start();

require_once '../config/database.php';

if (!isset($_SESSION['user']))
    die('You need to be logged in before you can like pictures.');


function like($dbh) {
    $sql = 'INSERT INTO PictureLike (userId, pictureId, creationDate) VALUES (:userId, :pictureId, :creationDate)';
    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(':userId', $_SESSION['user']['id']);
    $stmt->bindParam(':pictureId', $_GET['id']);
    $stmt->bindParam(':creationDate', date("Y-m-d H:i:s"));
    $stmt->execute();
}

function unlike($dbh) {
    $sql = 'DELETE FROM PictureLike WHERE pictureId = :id AND userId = :userId';
    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(':id', $_GET['id']);
    $stmt->bindParam(':userId', $_SESSION['user']['id']);
    $stmt->execute();
}

switch ($_GET['action']) {
    case 'like':
        like($dbh);
        break;
    case 'unlike':
        unlike($dbh);
        break;
    default:
        die('Action ' . $_GET['action'] . ' not supported.');
}

header('Location: gallery.php?picture=' . $_GET['id']);
