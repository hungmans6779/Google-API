<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/
require_once("phpmailer/class.phpmailer.php");

function sendbygmail($to_address, $to_name ,$subject, $body, $altbody = '', $attach = ''){
	$mail = new PHPMailer();
	$mail->IsSMTP(); // set mailer to use SMTP
	$mail->CharSet = 'utf-8';
	$mail->Encoding = 'base64';
	$mail->From = "$_MAILACCT@gmail.com";
	$mail->FromName = 'GMapbook System';
	//$mail->Sender = 'some.account@gmail.com';
	//$mail->ConfirmReadingTo = ''some.account@gmail.com'; 
	$mail->Host = 'ssl://smtp.gmail.com:465';
	//$mail->Port = ; //default is 25, gmail is 465 or 587
	$mail->SMTPAuth = true;
	$mail->Username = "$_MAILACCT@gmail.com";
	$mail->Password = $_MAILPASS;

	$mail->AddAddress($to_address, $to_name);
	$mail->WordWrap = 50;
	if (!empty($attach)) $mail->AddAttachment($attach);
	$mail->IsHTML(true);
	$mail->Subject = $subject;
	$mail->Body = $body;
	$mail->AltBody = $altbody;
	if(!$mail->Send()){
		//echo 'Mail send failed.\r\n';
		//echo 'Error message: ' . $mail->ErrorInfo . '\r\n';
		return false;
	}else{
		//echo "Send $attach to $to_name <$to_address> successed.\r\n";
		return true;
	}
}

?>