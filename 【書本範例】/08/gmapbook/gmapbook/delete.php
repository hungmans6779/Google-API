<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/

//用户ID
$uid = isset($_GET["uid"]) ? intval( $_GET["uid"] ) : 0;

require_once("include/include.inc.php");

if (!$logged_in) {
	//echo "Please login first!";
	echo 3;
	die();
}

$id = isset($_GET["id"]) ? intval( $_GET["id"] ) : -1;

if ($id>0) {
	$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
	if ($db->delete("messages","WHERE id=$id AND uid=$uid")>0) {
		echo 0;
	} else {
		echo 1;
		//echo "Deleting Failed! Entry Not Found!";
	}
	$db->close();
} else {
	echo 2;
	//echo "Deleting Failed! Invalid Entry ID!";
}
?>
