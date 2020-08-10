<?php ;

require_once '../config/database.php';

$sqlQuery = 'SELECT Picture.*, User.login as userLogin FROM Picture ';
$sqlQuery .= 'INNER JOIN User On User.id = Picture.userId WHERE Picture.id = :id';
$stmt = $dbh->prepare($sqlQuery);
$stmt->bindParam(':id', $_GET['picture']);
$stmt->execute();
$img = $stmt->fetch();

if (empty($img)) {
    echo '<script> window.location = "gallery.php"; </script>';
    die();
}

$sqlQuery = 'SELECT PictureComment.*,User.login as userLogin FROM PictureComment ';
$sqlQuery .= 'INNER JOIN User on User.id = PictureComment.userId WHERE PictureComment.pictureId = :pictureId';
$stmt = $dbh->prepare($sqlQuery);
$stmt->bindParam(':pictureId', $_GET['picture']);
$stmt->execute();
$res = $stmt->fetchAll();

function commentItemHtml($comment)
{
    $html = [
        '<div class="comment">',
        '  <div class="comment-header">',
        '    <div class="comment-user">' . htmlspecialchars($comment['userLogin']) . '</div>',
        '    <div class="comment-date">' . htmlspecialchars($comment['creationDate']) . '</div>',
        '  </div>',
        '  <div class="comment-content">' . htmlspecialchars($comment['content']) . '  </div>',
        '</div>',
    ];
    return implode($html, '');
}

function likeItemHtml($like)
{
    $html = [
        '<div>',
        htmlspecialchars($like['userLogin']),
        '</div>'
    ];
    return implode($html, '');
}

$comments = [];

foreach ($res as $comment) {
    array_push($comments, commentItemHtml($comment));
}

$sqlQuery = 'SELECT PictureLike.*,User.login as userLogin FROM PictureLike ';
$sqlQuery .= 'INNER JOIN User on User.id = PictureLike.userId WHERE PictureLike.pictureId = :pictureId';
$stmt = $dbh->prepare($sqlQuery);
$stmt->bindParam(':pictureId', $_GET['picture']);
$stmt->execute();
$res = $stmt->fetchAll();

$likes = [];
$userLike = null;
foreach ($res as $like) {
    if ($like['userId'] == $_SESSION['user']['id'])
        $userLike = true;
    array_push($likes, likeItemHtml($like));
}

if ($userLike) {
    $unlikeHtml = '<a href="like-picture.php?id=' . $_GET['picture'] . '&action=unlike">Unlike</a></span>';
    array_push($likes, $unlikeHtml);
} else {
    $likeHtml = '<a href="like-picture.php?id=' . $_GET['picture'] . '&action=like">Like it!</a></span>';
    array_push($likes, $likeHtml);
}

?>

<div flex flex-col class="gallery-detail">
    <div style="justify-content: space-between" flex>
        <div flex="1" flex-center-content>
            <img src="<?php echo htmlspecialchars('../uploads/' . $img['userId'] . '/' . $img['filename']) ?>">
        </div>

        <div flex="3" flex-col class="padding-h gallery-image-infos" style="align-self: flex-start">
            <div>
                <span class="label">Created by</span>: <?php echo htmlspecialchars($img['userLogin']) ?>
            </div>
            <div>
                <span class="label">Created on</span>: <?php echo htmlspecialchars($img['creationDate']) ?>
            </div>
            <div>
                <span class="label">Filename</span>: <?php echo htmlspecialchars($img['filename']) ?>
            </div>
        </div>

        <?php
        if ($_SESSION['user']['id'] === $img['userId'])
            echo '
    <form method="POST" action="delete-picture.php">
    <input type="hidden" value="' . $img['id'] . '" name="pictureId">
    <div><button type="submit" style="background: #dd514e">Delete image</button></div>
    </form>
';
        echo '';
        ?>
    </div>


    <div class="gallery-capabilities">
        <div class="header">Likes</div>
        <div class="capabilities-likes">
            <?php echo implode($likes, ''); ?>
        </div>
    </div>

    <div class="gallery-capabilities">
        <div class="header">Comments</div>
        <div class="capabilities-comments">
            <?php echo implode($comments, ''); ?>
        </div>
        <form action="comment-picture.php" method="POST">
            <input name="pictureId" type="text" hidden value="<?php echo $img['id'] ?>">
            <label for="comment">Your comment</label>
            <textarea name="content" id="comment-content"></textarea>
            <button type="submit">Submit</button>
        </form>
    </div>
</div>