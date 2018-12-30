<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/

error_reporting(0);

require_once("class.mysqldb.php");
require_once("class.securesession.php");
require_once("config.inc.php");

session_start();

$ss = new SecureSession();
$ss->check_browser = true;
$ss->check_ip_blocks = 2;
$ss->secure_word = 'koobpamg_';
$ss->regenerate_id = true;
$ss->Open();


if($uid) $sid = 'gmb_'.$uid;
$logged_in = ($ss->Check() && session_is_registered($sid) && $_SESSION[$sid]);


// Date in the past
header("Expires: Mon, 26 Jul 1997 05:00:00 GMT");

// always modified
header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");

// HTTP/1.1
header("Cache-Control: no-store, no-cache, must-revalidate");
header("Cache-Control: post-check=0, pre-check=0", false);

// HTTP/1.0
header("Pragma: no-cache");

?>
