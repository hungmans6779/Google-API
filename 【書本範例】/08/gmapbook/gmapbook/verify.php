<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/

require_once("include/include.inc.php");

// make a string with all the characters that we 
// want to use as the verification code
$alphanum  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";

// generate the verication code 
$r = substr(str_shuffle($alphanum), 0, 5);

// choose one of four background images
$bgNum = rand(1, 3);

// create an image object using the chosen background
$image = imagecreatefromjpeg("background$bgNum.jpg");

$textColor = imagecolorallocate ($image, 255, 0, 0); 

// write the code on the background image
imagestring ($image, 5, 2, 3,  $r, $textColor); 

// create the hash for the verification code
// and put it in the session
$_SESSION['image_random_value'] = $r;

// send the content type header so the image is displayed properly
header("Content-type: image/jpeg");

// send the image to the browser
imagejpeg($image);

// destroy the image to free up the memory
imagedestroy($image);
?> 