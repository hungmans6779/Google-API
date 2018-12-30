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

function randompassword(){
	$alphanum  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	return substr(str_shuffle($alphanum), 0, 8);
}


$success = false;

$code = isset($_GET["code"]) ? strval( $_GET["code"] ) : "";
if ( !$_SESSION['image_random_value'] || ($_SESSION['image_random_value']!==$code) ) {
	//echo "Your Verification Code is INVALID!";
	$_SESSION['image_random_value'] = false;
	echo 7;
	die();
}
if (isset($_GET['type']) && isset($_GET['email'])) {
	$password = randompassword();
	$currentdate = strftime('%Y年%m月%d日');
	$email = urldecode($_GET['email']);
	if (!eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$", $email) ) {
		//echo "Your Email address is INVALID!\nPlease verify it again!";
		echo 6;
		die();
	}
	if (($_GET['type'] == 'resuwen') && isset($_GET['uname'])){
		$uname = urldecode($_GET['uname']);
		$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
		if ($db->select_single_to_array('users','*',"WHERE email='$email'")) {
			$db->close();
			echo 1; //User Exists!
			die();
		} else {
			if ($uid = $db->insert('users', array( 'uname'=>$uname, 'upass'=>md5('happy new year!'), 'upass2'=>md5($password), 'email'=>$email, 'regtime'=>strftime('%y-%m-%d %H:%M:%S') ))) {
				$db->close();
			} else {
				$db->close();
				//echo "DB ERROR!";
				echo 3;
				die();
			}
		}
		$emailtitle = 'GMapbook新用戶註冊';
		$emailbody = "<p>尊敬的$uname</p><p style='text-indent:20px'>您好！歡迎使用GMapbook留言本。您的留言本位於<a href='http://gmapbook.gmap2.net/?uid=$uid' target='_blank'>http://gmapbook.gmap2.net/?uid=$uid</a>。從現在開始，您就可以使用該連結訪問留言本了。您可以在網頁中使用該連結，或者和我一樣利用iframe直接將該留言本嵌入網頁（見這裡<a href='http://blog.gmap2.net/' target='_blank'>http://blog.gmap2.net/</a>）。</p><p style='text-indent:20px'>不過，目前您的留言本尚處於<strong>未啟動狀態</strong>。請您在<strong>3日內</strong>用你的帳號和隨機密碼<strong>$password</strong>登陸<a href='http://gmapbook.gmap2.net/?uid=$uid' target='_blank'>http://gmapbook.gmap2.net/?uid=$uid</a>啟動帳號，否則您的帳號將被刪除。</p><p>&nbsp;</p><p><strong>您的使用者資訊</strong></p><p>EMail帳號： $email</p><p>用戶昵稱： $uname</p><p>隨機密碼： $password</p><p>留言本地址（登陸入口）： <a href='http://gmapbook.gmap2.net/?uid=$uid' target='_blank'>http://gmapbook.gmap2.net/?uid=$uid</a></p><p>使用幫助： <a href='http://gmapbook.gmap2.net/help.html' target='_blank'>http://gmapbook.gmap2.net/help.html</a></p><p>&nbsp;</p><p style='text-align:right'>GMapbook留言本系統</p><p style='text-align:right'>$currentdate</p>";
	} elseif ($_GET['type']== 'drowssaptsol') {
		$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
		$userinfo = $db->select_single_to_array('users','*',"WHERE email='$email'");
		if (!$userinfo) {
			$db->close();
			echo 2; //User Exists!
			die();
		} else {
			$uid = $userinfo['uid'];
			$uname = $userinfo['uname'];
			if ($db->update('users',array('upass2'=>md5($password)),"WHERE email='$email'")) {
				$db->close();
			} else {
				$db->close();
				echo 3;
				die();
			}
		}
		$emailtitle = 'GMapbook密碼重置';
		$emailbody = "<p>尊敬的$uname</p><p style='text-indent:20px'>您好！您收到本郵件是因為有人在<a href='http://gmapbook.gmap2.net' target='_blank'>http://gmapbook.gmap2.net</a>申請取回密碼。</p><p style='text-indent:20px'>如果該申請並非您發送，請忽略本郵件，並使用<strong>原密碼</strong>登陸。如果您忘記密碼，請使用以下資訊登陸。</p><p>&nbsp;</p><p><strong>您的使用者資訊</strong></p><p>EMail帳號： $email</p><p>用戶昵稱： $uname</p><p>隨機密碼： $password</p><p>留言本地址（登陸入口）： <a href='http://gmapbook.gmap2.net/?uid=$uid' target='_blank'>http://gmapbook.gmap2.net/?uid=$uid</a></p><p>使用幫助： <a href='http://gmapbook.gmap2.net/help.html' target='_blank'>http://gmapbook.gmap2.net/help.html</a></p><p>&nbsp;</p><p style='text-align:right'>GMapbook留言本系統</p><p style='text-align:right'>$currentdate</p>";
	} else {
		echo 5; //Illegal request!
		die();
	}

	if (sendbygmail($email, $uname, $emailtitle, $emailbody, '')) {
		echo 0;  //success
	} else {
		echo 4;  //email sending fail
	}

} else {
	echo 5;  //Illegal request!
}
?>
