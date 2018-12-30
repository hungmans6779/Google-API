<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/
$uid = isset($_POST["uid"]) ? intval( $_POST["uid"] ) : false;
require_once("include/include.inc.php");

if (!$logged_in) {
	//echo "Please login first";
	echo 3;
	die();
}

$id = isset($_POST["id"]) ? intval( $_POST["id"] ) : -1;
$reply = isset($_POST["content"]) ? strval( $_POST["content"] ) : "";
if ($id>0 && strlen($reply)>0) {
	$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);

	if ($db->update("messages",array("reply"=>$reply, "replytime"=>strftime("%y-%m-%d %H:%M:%S")),"WHERE id=".$id)>0) {
		echo 0;
	} else {
		echo 1;
		//echo "Replying Failed! Entry Not Found!";
	}
	$db->close();
} else {
	echo 2;
	//echo "Replying Failed! Invalid Entry ID!";
}
?>
