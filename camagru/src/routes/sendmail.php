<?php

$headers = array();
$headers[] = "From: Camagru <no-reply@camagru.com>";
mail('erwan94@protonmail.com', 'Welcome', 'welcome to camagru', implode($headers, "\r\n"));

$app->get('login', render(login.html));