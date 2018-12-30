<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
整個介面均在此實現，因此可以較為方便的多國語言化
不過發送郵件的部分因為偷懶，沒有單獨設置，只可以發送簡體中文郵件，可自行修改
*/

require_once("include/include.inc.php");

?>
var _rowcount = 3;  //默認為留言為3行
var _maptypes = [G_NORMAL_MAP, G_SATELLITE_MAP];
<?php
	$uid = isset($_GET["uid"]) ? intval( $_GET["uid"] ) : false;
	$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
	$settings = $db->select_single_value("users", "CONCAT(uname, '|', settings)", "WHERE uid=$uid");
	$db->close();
	list($admin, $zoomlevel, $latlng, $maptype, $emailalert) = explode('|', $settings);
	if($uid && $settings){
		echo "var uid = $uid;\n";
		echo "var admin = \"$admin\";\n";
		echo "var _zoomlevel = $zoomlevel;\n";
		echo "var _home = new GLatLng($latlng);\n";
		echo "var _alert = $emailalert;\n";
		echo "var _maptype = _maptypes[$maptype];\n";
	}else{
		die();
	}
?>


//var _maptype = _maptypes[0]; //默認地圖類型 G_NORMAL_MAP或G_SATELLITE_MAP， 暫不支援G_HYBRID_MAP
//var _home = new GLatLng(30.58, 114.27);
//var _zoomlevel = 2;  //默認縮放級別

var _tabprefix = "消息";

var _postInfo = "由 <strong>#name#</strong> 於 #posttime# 發表";
var _replyInfo = "由 <strong>#admin#</strong> 於 #replytime# 回復";

var _reply = "回復";
var _delete = "刪除";
var _submit = "送出";
var _reset = "重置";

var _titleInfo = "請填寫下面所有資料";
var _titleLogin = "用戶登錄";
var _titleRegister = "用戶註冊";
var _titleForgetPassword = "密碼取回";
var _titleUpdatePassword = "修改密碼";
var _titleUpdateSettings = "更改設置"


var _nickname = "匿稱";
var _email = "EMail";
var _password = "密碼";
var _vcode = "驗證碼";
var _changevcode = "更換驗證碼";
var _vcodeTip = "如果無法看清上面的字元，請按一下圖片換一張顯示！";

var _sendPassword = "請輸入您的EMail，系統將發送隨機密碼到此郵箱";

var _mapConfig = "默認使用當前地圖的中心、類型及縮放級別(留空則使用系統值)";
var _emailAlert = "有留言時EMail通知";

var _oldPassword = "請輸入原始密碼";
var _newPassword1 = "請輸入新密碼";
var _newPassword2 = "請再次輸入新密碼";

var _hiddenMsg = "該留言已隱藏，請登錄後查看！";

var _regTip = "密碼將發送到您的郵箱，請三天內進行首次登陸，否則將刪除帳號！請儘量使用GMail、Yahoo或163郵箱進行註冊，否則可能無法收到密碼！";
var _logTip = "本系統尚在開發，請經常登陸，每天都有可能新增新特性！";

var _sysConfig = "系統設置";
var _sysPassword = "密碼管理";

//-------------------------------------

var arrLog = ["登錄", "登出"];
var arrManage = ["忘記密碼", "管理選項"];
var arrRegister = ["註冊", "說明"];

//定義按鈕位置
var $a = G_ANCHOR_BOTTOM_RIGHT;
var optSubmit = {anchor:$a, offset:{x:3, y:2}, caption:"給 [b]"+admin+"[/b] 留言", width:"162px"};
var optNextPage = {anchor:$a, offset:{x:170, y:2}, caption:"下一頁", width:"50px"};
var optPreviousPage = {anchor:$a, offset:{x:225, y:2}, caption:"上一頁", width:"50px"};
var optNextMessage = {anchor:$a, offset:{x:280, y:2}, caption:"下一記錄", width:"60px"};
var optPreviousMessage = {anchor:$a, offset:{x:345, y:2}, caption:"上一記錄", width:"60px"};
var optManage = {anchor:$a, offset:{x:410, y:2}, caption:"忘記密碼", width:"60px"};
var optLog = {anchor:$a, offset:{x:475, y:2}, caption:"登錄", width:"40px"};
var optRegister = {anchor:$a, offset:{x:520, y:2}, caption:"註冊", width:"40px"};

//信息
var errLogin = ["登錄成功！","不正確的用戶名或密碼！", "電郵、密碼及驗證碼均不能為空！","電郵地址無效！請檢查！", "驗證碼錯誤！"];
var errLogout = ["登出成功！","暫時無法登出！"];
var errDelete = ["刪除成功！","刪除失敗！可能是該留言已不存在！","刪除失敗！可能是該留言已刪除！","您尚未登陸，請先登錄！"];
var errPost = ["送出成功！","你的地裡位置不正確！\n將無法在此留言！","姓名、電郵、驗證碼及內容均不能為空！","電郵地址無效！請檢查！","驗證碼錯誤！","未知錯誤！","未知用戶！"];
var errReply = ["回復成功！","回復失敗！可能是該留言已不存在！","回復失敗！可能是該留言已刪除！","您尚未登陸，請先登錄！"];
var errLoading = ["現在沒有任何留言！","已經是最後一頁了！","已經是第一頁了！","已經是最後一條記錄了！","已經是第一條記錄了！"];
var errSetPassword = ["密碼已發送，請注意查收！", "該郵箱帳戶已存在，註冊失敗！", "該郵箱帳戶不存在，重置密碼失敗！","資料庫更新失敗！","郵件發送失敗！","非法訪問！","電郵地址無效！請檢查！", "驗證碼錯誤！", "所有資訊均不能為空！"];
var errUpdatePassword = ["密碼已更新！", "密碼不能為空，請修正！", "兩次新密碼輸入不一致，請修正！", "舊密碼輸入錯誤，請修正！","您尚未登陸，請先登錄！","資料庫更新失敗！"];
var errUpdateSettings = ["設置已更新！","資料庫更新失敗！","您尚未登陸，請先登錄！"];
var operations = ["載入中...","送出中...","登錄中...","登出中...","刪除中...","發送中...", "正在跳轉到您的頁面..."];

var strNotImplement= "Not Implemented";
var strHelp= strNotImplement;


//GInfoWindow的HTML字串
var strHead = "<table width=\"98%\" align=\"left\"><tbody>";
var strTail = "</tbody></table>";
var strContent = "<tr><td height=\"50\"><textarea name=\"taContent\" rows=\"#rowcount#\" readonly=\"readonly\">#content#</textarea></td></tr><tr><td class=\"rinfo\">"+ _postInfo +"</td></tr>";
var strReply = "<tr><td height=\"50\"><textarea name=\"taReply\" rows=\""+_rowcount+"\" readonly=\"readonly\">#reply#</textarea></td></tr>  <tr><td class=\"rinfo\">"+ _replyInfo +"</td></tr>";
var strReply2 = "<tr><td height=\"50\"><textarea name=\"taReply\" rows=\""+_rowcount+"\">#reply#</textarea></td></tr>  <tr><td class=\"rinfo\">"+ _replyInfo +"</td></tr><tr><td class=\"rinfo\"><input type=\"button\" value=\""+ _reply +"\" onclick=\"reply(#id#, taReply.value)\" />&nbsp;<input type=\"button\" value=\""+_delete+"\" onclick=\"deleteIt(#id#)\" /></td></tr>";
var strGuestInfo = "<tr><td class=\"rinfo\">IP: <a href=\"http://ws.arin.net/cgi-bin/whois.pl?queryinput=#ip#\" target=\"_blank\">#ip#</a>&nbsp;&nbsp;EMail:<a href=\"mailto:#email#\" target=\"_blank\">#email#</a></td></tr>";

var strSubmit = "<div id=\"Post\"><form><table width=\"300\"><tbody><tr><td colspan=\"4\" align=\"left\" class=\"formtitle\">"+_titleInfo+"</td></tr><tr><td width=\"30%\" class=\"formcontent\" colspan=\"2\" ><label>"+_nickname+" <input name=\"gname\" type=\"text\" size=\"12\" value=\"#guestname#\" maxlength=\"20\" style=\"width:60px\" /></label></td><td style=\"color:#0099FF; font:12px bold;\" colspan=\"2\" align=\"right\"><label>"+_email+" <input name=\"email\" type=\"text\" size=\"20\" maxlength=\"50\" value=\"#guestemail#\" style=\"width:145px\" /></label></td></tr><tr><td colspan=\"4\"><textarea name=\"content\" cols=\"30\" rows=\"5\" style=\"font:12px bold;overflow:auto;width:100%;color:#0099FF;\"></textarea></td></tr><tr><td valign=\"middle\"><img id=\"imgPost\" name=\"imgPost\" src=\"#verify#\" alt=\""+_vcode+"\" width=\"50\" height=\"20\" border=\"0\" title=\""+_vcodeTip+"\" style=\"cursor:pointer\" onclick=\"changeImg(this)\" /></td><td style=\"color:#0099FF; font:14px bold;\"><label><input name=\"code\" type=\"text\" size=\"5\" maxlength=\"5\" style=\"width:40px\" /></label></td><td><input type=\"button\" onclick=\"changeImg(imgPost);\" value=\""+_changevcode+"\" /></td><td style=\"color:#0099FF; font:12px bold;\"><label><input name=\"show\" type=\"checkbox\" checked />公開留言</label></td></tr><tr><td colspan=\"4\" align=\"center\"><input name=\"Submit\" type=\"button\" value=\""+_submit+"\" onclick=\"post(gname.value, email.value, code.value, content.value, show.checked)\"/>&nbsp;&nbsp;<input name=\"Reset\" type=\"reset\" id=\"Reset\" value=\""+_reset+"\" /></td></tr><!--tr><td colspan=\"4\" align=\"left\" style=\"color:#0099FF; font:16px bold\"><label><input name=\"chb\" type=\"checkbox\" onclick=\"if (this.checked) {document.getElementById('ManualLocating').style.display = 'block'} else {document.getElementById('ManualLocating').style.display = 'none'}\">You can click here to locate manually</label><span id=\"ManualLocating\" style=\"display:none\"><label>City name:<input name=\"CityName\" type=\"text\" size=\"12\" title=\"Type city name here!\" style=\"color:#0099FF; font:12px;width:140px\" /></label><input name=\"LocateMe\" type=\"button\" value=\"Locate\" onclick=\"locate(CityName.value)\" /></span></td></tr--></tbody></table></form></div>";

var strLogin = "<div><form><table width=\"250\" border=\"0\"><tbody><tr><td colspan=\"4\" class=\"formtitle\"><strong>"+_titleLogin+"</strong></td></tr><tr><td colspan=\"4\" class=\"formcontent\">"+_titleInfo+"</td></tr><tr class=\"formcontent\"><td width=\"50\" colspan=\"1\">"+_email+"</td><td colspan=\"3\"><input type=\"text\" style=\"width:100%\" maxlength=\"50\" name=\"email\" /></td></tr><tr class=\"formcontent\"><td>"+_password+"</td><td  colspan=\"3\"><input type=\"password\" style=\"width:100%\" name=\"upass\" /></td></tr><tr class=\"formcontent\"><td>"+_vcode+"</td><td align=\"left\"><input type=\"text\" maxlength=\"5\" style=\"width:40px\" name=\"code\" /></td><td valign=\"middle\"><img id=\"imgLogin\" name=\"imgLogin\" src=\"#verify#\" alt=\""+_vcode+"\" width=\"50\" height=\"20\" border=\"0\" title=\""+_vcodeTip+"\" style=\"cursor:pointer\" onclick=\"changeImg(this)\" /></td><td align=\"right\"><input type=\"button\" onclick=\"changeImg(imgLogin); \" value=\""+_changevcode+"\" /></td></tr><tr class=\"formcontent\"><td colspan=\"4\" align=\"center\"><input type=\"button\" name=\"submit\" onclick=\"login(email.value, upass.value, code.value); \" value=\""+_submit+"\" />&nbsp;<input name=\"reset\" type=\"reset\" id=\"reset\" value=\""+_reset+"\" /></td></tr><tr><td colspan=\"4\" style=\"font:12px small-caps; color:#0099FF;\">"+_logTip+"</td></tr></tbody></table></form></div>";
var strRegister = "<div><form><table width=\"250\" border=\"0\"><tbody><tr><td colspan=\"4\" class=\"formtitle\"><strong>"+_titleRegister+"</strong></td></tr><tr><td colspan=\"4\" class=\"formcontent\">"+_titleInfo+"</td></tr><tr class=\"formcontent\"><td width=\"50\" colspan=\"1\">"+_email+"</td><td colspan=\"3\"><input type=\"text\" style=\"width:100%\" maxlength=\"50\" name=\"email\" /></td></tr><tr class=\"formcontent\"><td>"+_nickname+"</td><td  colspan=\"3\"><input type=\"text\" style=\"width:100%\" name=\"uname\" maxlength=\"20\" /></td></tr><tr class=\"formcontent\"><td>"+_vcode+"</td><td align=\"left\"><input type=\"text\" maxlength=\"5\" style=\"width:40px\" name=\"code\" /></td><td valign=\"middle\"><img id=\"imgRegister\" name=\"imgRegister\" src=\"#verify#\" alt=\""+_vcode+"\" width=\"50\" height=\"20\" border=\"0\" title=\""+_vcodeTip+"\" style=\"cursor:pointer\" onclick=\"changeImg(this)\" /></td><td align=\"right\"><input type=\"button\" onclick=\"changeImg(imgRegister); \" value=\""+_changevcode+"\" /></td></tr><tr class=\"formcontent\"><td colspan=\"4\" align=\"center\"><input type=\"button\" name=\"submit\" onclick=\"setPassword(true, email.value, uname.value, code.value); \" value=\""+_submit+"\" />&nbsp;<input name=\"reset\" type=\"reset\" id=\"reset\" value=\""+_reset+"\" /></td></tr><tr><td colspan=\"4\" style=\"font:12px small-caps; color:#0099FF;\">"+_regTip+"</td></tr></tbody></table></form></div>";
var strForgetPassword = "<div><form><table width=\"250\" border=\"0\"><tbody><tr><td colspan=\"4\" class=\"formtitle\"><strong>"+_titleForgetPassword+"</strong></td></tr><tr><td colspan=\"4\" class=\"formcontent\">"+_sendPassword+"</td></tr><tr class=\"formcontent\"><td width=\"50\" colspan=\"1\">"+_email+"</td><td colspan=\"3\"><input type=\"text\" style=\"width:100%\" maxlength=\"50\" name=\"email\" /></td></tr><tr class=\"formcontent\"><td>"+_vcode+"</td><td align=\"left\"><input type=\"text\" maxlength=\"5\" style=\"width:40px\" name=\"code\" /></td><td valign=\"middle\"><img id=\"imgLost\" name=\"imgLost\" src=\"#verify#\" alt=\""+_vcode+"\" width=\"50\" height=\"20\" border=\"0\" title=\""+_vcodeTip+"\" style=\"cursor:pointer\" onclick=\"changeImg(this)\" /></td><td align=\"right\"><input type=\"button\" onclick=\"changeImg(imgLost);\" value=\""+_changevcode+"\" /></td></tr><tr class=\"formcontent\"><td colspan=\"4\" align=\"center\"><input type=\"button\" name=\"submit\" onclick=\"setPassword(false, email.value, '', code.value); \" value=\""+_submit+"\" />&nbsp;<input name=\"reset\" type=\"reset\" id=\"reset\" value=\""+_reset+"\" /></td></tr></tbody></table></form></div>";

var strUpdateSettings = "<div><form><table width=\"300\" border=\"0\"><tbody><tr><td colspan=\"2\" class=\"formtitle\"><strong>"+_titleUpdateSettings+"</strong></td></tr><tr class=\"formcontent\"><td width=\"250\">"+_mapConfig+"</td><td width=\"50\"><input type=\"checkbox\" name=\"mapconfig\" /></td></tr><tr class=\"formcontent\"><td>"+_emailAlert+"</td><td><input type=\"checkbox\" name=\"emailalert\" "+ (_alert?"checked":"") +"/></td></tr><tr class=\"formcontent\"><td colspan=\"2\" align=\"center\"><input type=\"button\" name=\"submit\" onclick=\"updateSettings(mapconfig.checked, emailalert.checked); \" value=\""+_submit+"\" />&nbsp;<input name=\"reset\" type=\"reset\" id=\"reset\" value=\""+_reset+"\" /></td></tr></tbody></table></form></div>";
var strUpdatePassword = "<div><form><table width=\"300\" border=\"0\"><tbody><tr><td colspan=\"2\" class=\"formtitle\"><strong>"+_titleUpdatePassword+"</strong></td></tr><tr class=\"formcontent\"><td width=\"150\">"+_oldPassword+"</td><td width=\"150\"><input type=\"password\" style=\"width:100%\" name=\"oldpass\" /></td></tr><tr class=\"formcontent\"><td>"+_newPassword1+"</td><td><input type=\"password\" style=\"width:100%\" name=\"newpass\" /></td></tr><tr class=\"formcontent\"><td>"+_newPassword2+"</td><td><input type=\"password\" style=\"width:100%\" name=\"newpass2\" /></td></tr><tr class=\"formcontent\"><td colspan=\"4\" align=\"center\"><input type=\"button\" name=\"submit\" onclick=\"updatePassword(oldpass.value, newpass.value, newpass2.value); \" value=\""+_submit+"\" />&nbsp;<input name=\"reset\" type=\"reset\" id=\"reset\" value=\""+_reset+"\" /></td></tr></tbody></table></form></div>";

var tabManage = [new GInfoWindowTab(_sysConfig, strUpdateSettings),
                 new GInfoWindowTab(_sysPassword, strUpdatePassword)];





