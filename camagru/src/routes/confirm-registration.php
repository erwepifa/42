<?php

require_once '../config/database.php';

if (!isset($_GET['code'])) {
    header('refresh:5; url=login.php');
    die('Cannot activate account associated with code ' . $_GET['code']);
}

function activateUser($dbh, $code) {
    try {
        $sql = 'UPDATE User SET active = true WHERE confirmationCode = :code';
        $stmt = $dbh->prepare($sql);
        $stmt->bindParam(':code', $code);
        $stmt->execute();
        if (!$stmt->rowCount())
            die('Nothing done, invalid code or user account already activated.');
    } catch (PDOException $e) {
        die('Error while activating user: ' . $e->getMessage());
    }
}

activateUser($dbh, $_GET['code']);
header('refresh:5; url=login.php');
echo 'Account activated. Redirecting to login page in 5 seconds';
