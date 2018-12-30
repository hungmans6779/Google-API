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
	echo 4;
	die();
}

if (!isset($_GET["oldpass"]) || !isset($_GET["newpass"])) {
	//echo "empty password";
	echo 1;
	die();
}
$oldpass =  $_GET["oldpass"];
$newpass =  $_GET["newpass"];


$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
if ($db->select_single_to_array('users','*',"WHERE uid='$uid' AND upass='$oldpass'")) {
	if ($db->update("users",array('upass'=>$newpass, 'upass2'=>$newpass),"WHERE uid='$uid'")>0) {
		echo 0;
	} else {
		echo 5;
		//echo "Update Failed! Entry Not Found!";
	}
} else {
	echo 3;  //invalide old password
}
$db->close();

?>
