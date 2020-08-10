<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="../assets/style.css">
    <link href="https://fonts.googleapis.com/css?family=Raleway" rel="stylesheet">
    <title>Camagru</title>
</head>

<body>

<div class="content">
    <header>
        <div class="logo"><a href="home.php">Camagru</a></div>
        <div flex space-between style="flex: 1; margin-left: 50px">
            <nav>
                <ul class="horizontal-list">
                    <li><a href="gallery.php">Gallery</a></li>

                    <?php
                    if (isset($_SESSION['user']))
                        print '<li><a href="capture.php">Capture</a></li>'
                    ?>
                </ul>
            </nav>
            <div>
                <?php

                if (isset($_SESSION['user']))
                    print '<a href="logout.php">Logout</a>';
                else
                    print '<a href="register.php">Register</a>'
                        . '<a href="login.php">Login</a>';

                ?>
            </div>
        </div>
    </header>

    <main>
