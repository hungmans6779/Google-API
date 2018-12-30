<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/
$uid = isset($_GET['uid']) ? intval( $_GET['uid'] ) : 0;
require_once('include/include.inc.php');

if (!$logged_in) {
	//echo "Please login first";
	echo 2;
	die();
}

$config = isset($_GET['cfg']) ? strval( $_GET['cfg'] ) : '';
if (strlen($config)>0) {
	$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
	if ($db->update('users',array('settings'=>$config),"WHERE uid=$uid")>0) {
		echo 0;
	} else {
		echo 1;
		//echo "Replying Failed! Entry Not Found!";
	}
	$db->close();
}
?>
