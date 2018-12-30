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

session_unset();
if (session_destroy()) {
	echo 0;
} else {
	echo 1;
//	echo "Unable to logout!";
}
?>
