<?php

session_start();

require_once '../config/database.php';

if (!isset($_SESSION['user']))
    die('You need to be logged in before you can like pictures.');
function delete_picture($dbh) {
    $sql = 'DELETE FROM picture WHERE userId = :userId';
    $stmt = $dbh->prepare($sql);
   // $stmt->bindParam(':id', $_GET['id']);
    $stmt->bindParam(':userId', $_SESSION['user']['id']);
    $stmt->execute();
}

delete_picture($dbh);

header('Location: gallery.php');