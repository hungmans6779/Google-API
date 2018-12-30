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
require_once("include/functions.php");

function getClientIP() {
	if ($HTTP_SERVER_VARS["HTTP_X_FORWARDED_FOR"]) return $HTTP_SERVER_VARS["HTTP_X_FORWARDED_FOR"];
	elseif ($HTTP_SERVER_VARS["HTTP_CLIENT_IP"]) return $HTTP_SERVER_VARS["HTTP_CLIENT_IP"];
	elseif ($HTTP_SERVER_VARS["REMOTE_ADDR"]) return $HTTP_SERVER_VARS["REMOTE_ADDR"];
	elseif (getenv("HTTP_X_FORWARDED_FOR")) return getenv("HTTP_X_FORWARDED_FOR");
	elseif (getenv("HTTP_CLIENT_IP")) return getenv("HTTP_CLIENT_IP");
	elseif (getenv("REMOTE_ADDR")) return getenv("REMOTE_ADDR");
	else return "255.255.255.255";
}


$name = isset($_POST["name"]) ? strval( $_POST["name"] ) : "";
$email = isset($_POST["email"]) ? strval( $_POST["email"] ) : "";
$code = isset($_POST["code"]) ? strval( $_POST["code"] ) : "";
$content = isset($_POST["content"]) ? strval( $_POST["content"] ) : "";
$longitude = isset($_POST["longitude"]) ?  doubleval( $_POST["longitude"] ) : 1000;
$latitude = isset($_POST["latitude"]) ?  doubleval( $_POST["latitude"] ) : 1000;
$display = isset($_POST["display"]) ? intval($_POST["display"]) : 1;

$notify = isset($_POST["notify"]);

if (!$uid){
	echo 6;
	//echo "No Such User!";
	die();
}
if (!((-180<=$longitude) && ($longitude<=180))  || !((-90<=$latitude) && ($latitude<=90)) ) {
	echo 1;
	//echo "Your location is incorrect!\nYou can't leave a message here!";
	die();
}
if (($name=="") || ($email=="") || ($code=="") || ($content=="") ) {
	//echo "Name, Email, Verification Code and Content shouldn't be empty!";
	echo 2;
	die();
}

if ( !eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$",$email) ) {
	//echo "Your Email address is INVALID!\nPlease verify it again!";
	echo 3;
	die();
}

//if ( !$_SESSION['image_random_value'] || ($_SESSION['image_random_value']!==$code) ) {
//	//echo "Your Verification Code is INVALID!";
//	$_SESSION['image_random_value'] = false;
//	echo 4;
//	die();
//}
//
$ip = ip2long(getClientIP());
$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
if ($db->insert('messages', array('uid'=>$uid, 'name'=>$name, 'email'=>$email, 'content'=>$content, 'longitude'=>$longitude, 'latitude'=>$latitude, 'ip'=>$ip, 'posttime'=>strftime('%y-%m-%d %H:%M:%S'), 'display'=>$display ))) {
	echo 0;
	$settings = $db->select_single_value('users', "CONCAT(uname, '|', email, '|', settings)", "WHERE uid=$uid");
	list($uname, $adminemail, $zoomlevel, $latlng, $maptype, $emailalert) = explode('|', $settings);
	if($emailalert){
		$currentdate = strftime('%Y年%m月%d日');
		$emailtitle = 'GMapbook留言提醒';
		$emailbody = "<p>尊敬的$uname</p><p style='text-indent:20px'>您好！用戶名為$name (<a href='mailto:$email'>$email</a>) 的訪客在您的GMapbook上留言。要查看該留言，請訪問 <a href='http://gmapbook.gmap2.net/?uid=$uid' target='_blank'>http://gmapbook.gmap2.net/?uid=$uid</a>。</p><p>&nbsp;</p><p>&nbsp;</p><p style='text-align:right'>GMapbook留言本系統</p><p style='text-align:right'>$currentdate</p>";
		sendbygmail($adminemail, $uname, $emailtitle, $emailbody, '');
	}
} else {
//echo "Unknown ERROR!";
	echo 5;
}
$db->close();

?>
