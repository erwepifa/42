<?php

require_once '../config/database.php';

function galleryImgHtml($img)
{
    $html = [
        '<div class="gallery-image" id="' . $img['id'] . '">',
        '<a class="gallery-detail-link" href="gallery.php?picture=' . $img['id'] . '"></a>',
        '<img src="../uploads/' . $img['userId'] . '/' . $img['filename'] . '">',
        '<div class="gallery-image-infos padding-h">',
        '<div>',
        '<span class="label">Filename:</span>',
        $img['filename'],
        '</div>',
        '<div>',
        '<span class="label">Creation:</span>',

        $img['creationDate'],
        '</div>',
        '<div>',
        '<span class="label">Owned by:</span>',

        $img['login'],
        $img[userId] === $_SESSION['user'][id] ? ' (me)' : '',
        '</div>',
        '<div flex="1"></div>',
        '<div class="capabilities">',
        '<div class="likes">',

        $img['likeCount'],
        ' likes',
        '</div>',
        '<div class="comments">',

        $img['commentCount'],
        ' comments',
        '</div>',
        '</div>',
        '</div>',
        '</div>'
    ];
    return implode('', $html);
}

$pageRowsLimit = 5;
$pageNum = isset($_GET['page']) ? $_GET['page'] : 0;

$sqlQuery = '';
$sqlQuery .= 'SELECT SQL_CALC_FOUND_ROWS Picture.*, User.login,';
$sqlQuery .= '(SELECT COUNT(*) FROM PictureLike WHERE PictureLike.pictureId = Picture.id) AS likeCount,';
$sqlQuery .= '(SELECT COUNT(*) FROM PictureComment WHERE PictureComment.pictureId = Picture.id) AS commentCount ';
$sqlQuery .= 'FROM Picture INNER JOIN User ON User.id = Picture.userId';


$offset = $pageNum * $pageRowsLimit;
$stmt = $dbh->prepare($sqlQuery);
$stmt->bindParam(':offset', $offset, PDO::PARAM_INT);
$stmt->bindParam(':pageRowsLimit', $pageRowsLimit, PDO::PARAM_INT);
$stmt->execute();
$res = $stmt->fetchAll();

$foundRowsStmt = $dbh->query('SELECT FOUND_ROWS()');
$foundRows = $foundRowsStmt->fetch()['FOUND_ROWS()'];

$images = [];

foreach ($res as $img) {
    array_push($images, galleryImgHtml($img));
}

$images = implode('', $images);

$pagination = '<div>';

if ($pageNum)
    $pagination .= '<a href="?page=' . ($pageNum - 1) . '">Previous page</a>';

if (floor($foundRows / $pageRowsLimit) > $pageNum)
    $pagination .= '<a href="?page=' . ($pageNum + 1) . '">Next page</a>';
$pagination .= '</div>';

?>

<div flex flex-col>
    <?php echo $images; ?>
</div>

<?php echo $pagination; ?>

<script src="../assets/gallery.js"></script>
