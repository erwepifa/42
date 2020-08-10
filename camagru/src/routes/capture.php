<?php

session_start();

ini_set('memory_limit','256M');

require_once '../config/database.php';

if (!isset($_SESSION['user'])) {
    header('Location: login.php');
    exit;
}

$uploadsDir = '../uploads/' . $_SESSION['user']['id'] . '/';

function loadImage($file) {
    $size = getimagesize($file);
    switch ($size["mime"]) {
        case "image/jpeg":
            $img = imagecreatefromjpeg($file);
            break;
        case "image/gif":
            $img = imagecreatefromgif($file);
            break;
        case "image/png":
            $img = imagecreatefrompng($file);
            break;
        default:
            break;
    }
    return [
        'data' => $img,
        'size' => $size
    ];
}

function genImgHtml($img) {
    $html = [
        '<div class="thumbnail">',
        '<a href="gallery.php?picture=' . $img['id'] . '">',
        '<img class="thumbnail" src="../uploads/' . $_SESSION['user']['id'] . '/' . $img['filename'] . '" alt="thumbnail">',
        '</a>',
        '<h3>' . $img['creationDate'] . '</h3>',
        '</div>'
    ];
    return implode('', $html);
}

if (isset($_POST['submit'])) {
    $bg = $_FILES['background'];
    $overlay = $_FILES['overlay'];

    if (!isset($bg) || $bg['error'])
        die('Need a background image or the one you provided is too big (max 2MB)');

    $bgImg = loadImage($bg['tmp_name']);
    if (!$overlay['error']) {
        $overlayImg = loadImage($overlay['tmp_name']);
    } else if (strlen($_POST['overlay_path'])) {
        $path = explode('/', $_POST['overlay_path']);
        $filename = end($path);

        $overlayImg = loadImage('../assets/' . $filename);
    } else {
        die ('Need an overlay image or the one you provided is too big (max 2MB).');
    }

    imagecopyresampled($bgImg['data'], $overlayImg['data'], $_POST['overlay_x'], $_POST['overlay_y'], 0, 0, $overlayImg['size'][0], $overlayImg['size'][1], $overlayImg['size'][0], $overlayImg['size'][1]);

    if (!file_exists($uploadsDir))
        mkdir($uploadsDir, 0777, true);

    $filename = hash('md5', $bg['name'] . $overlay['name'] . time()) . '.jpg';

    imagejpeg($bgImg['data'], $uploadsDir . $filename);

    imagedestroy($bgImg['data']);

    $stmt = $dbh->prepare('INSERT INTO Picture (filename, userId,  creationDate) VALUES (:filename, :userId, :creationDate)');
    $stmt->bindParam(':filename', $filename);
    $stmt->bindParam(':userId', $_SESSION['user']['id']);

    $date = date("Y-m-d H:i:s");
    $stmt->bindParam(':creationDate', $date);

    $stmt->execute();
}
else {
    $stmt = $dbh->prepare('SELECT Picture.id, filename, creationDate FROM Picture INNER JOIN User ON User.id = Picture.userId WHERE User.id LIKE :userId ORDER BY Picture.creationDate DESC LIMIT 5');
    $stmt->bindParam(':userId', $_SESSION['user']['id']);

    $stmt->execute();

    $res = $stmt->fetchAll();

    include_once '../partials/header.php';

//    $history = '<img src="../uploads/' . $_SESSION['user']['id'] . '/' . $res[0]['filename'] . '">';
    $history = [];
    foreach ($res as $img) {
        array_push($history, genImgHtml($img));
    }
    $history = implode('', $history);

    include_once '../partials/capture.php';

    include_once '../partials/footer.php';
}

