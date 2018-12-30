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
require_once("include/functions.php");

$code = isset($_GET["code"]) ? strval( $_GET["code"] ) : "";
if ( !$_SESSION['image_random_value'] || ($_SESSION['image_random_value']!==$code) ) {
	//echo "Your Verification Code is INVALID!";
	$_SESSION['image_random_value'] = false;
	echo 4;
	//die();
}

if (isset($_GET['uid']) && isset($_GET['email'])) {
	$uid = $_GET['uid'];
	$email = $_GET['email'];
	$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
	$passwd = strtoupper($_GET['passwd']);
	$userinfo = $db->select_single_to_array('users','*',"WHERE email='$email'");
	//echo "$uid, $uname, $password, ".$_GET['passwd'];
	if ($userinfo['upass'] == $passwd) {
		$sid = 'gmb_'.$userinfo['uid'];
		session_register($sid);
		$_SESSION[$sid] = $userinfo['uname'].'|'.$userinfo['email'];
		$db->update("users",array("lastlogin"=>strftime("%y-%m-%d %H:%M:%S"), 'activated'=>true),"WHERE uid='$uid' AND email='$email'");
		if ($userinfo['uid'] != $uid) {
			echo 'u|'.$userinfo['uid'];
			$db->close();
			die();
		}
		echo 0;
	} elseif ($userinfo['upass2'] == $passwd) {
		$sid = 'gmb_'.$userinfo['uid'];
		session_register($sid);
		//$_SESSION[$sid] = true;
		$_SESSION[$sid] = $userinfo['uname'].'|'.$userinfo['email'];
		$db->update("users",array('lastlogin'=>strftime("%y-%m-%d %H:%M:%S"), 'upass'=>$userinfo['upass2'], 'activated'=>true),"WHERE uid='$uid' AND email='$email'");
		echo 0;
		
		if(!$userinfo['lastlogin']){
			$currentdate = strftime('%Y年%m月%d日');
			$emailtitle = 'GMapbook账户已激活';
			$emailbody = "<p>尊敬的" . $userinfo['uname'] . "</p><p style='text-indent:20px'>您好！您的GMapbook账户已激活，请访问 <a href='http://gmapbook.gmap2.net/?uid=$uid' target='_blank'>http://gmapbook.gmap2.net/?uid=$uid</a> 查看留言。</p><p>&nbsp;</p><p>&nbsp;</p><p style='text-align:right'>GMapbook留言本系统</p><p style='text-align:right'>$currentdate</p>";
			sendbygmail($userinfo['email'], $userinfo['uname'], $emailtitle, $emailbody, '');
		}
		if ($userinfo['uid'] != $uid) {
			echo 'u|'.$userinfo['uid'];
			$db->close();
			die();
		}
	} else {
		echo 1;
	}
	$db->close();
} else {
	if ($logged_in) {
		echo 0;
	} else { 
		echo 1;
	}
}
?>
