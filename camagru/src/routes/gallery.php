<?php

session_start();
require_once '../config/database.php';

include_once '../partials/header.php';

if (isset($_GET['picture'])) {
    include_once '../partials/gallery-detail.php';
} else {
    include_once '../partials/gallery.php';
}

include_once '../partials/footer.php';
