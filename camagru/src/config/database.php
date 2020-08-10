<?php

$DB_DSN = 'mysql:host=127.0.0.1;dbname=camagru';
$DB_USER = 'root';
$DB_PASSWORD = 'voiture';
try {
    $dbh = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
} catch (PDOException $e) {
    echo htmlspecialchars('Error while connecting: ' . $e->getMessage());
    die('SQL Error');
}