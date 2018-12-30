<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)             |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/

//用戶ID
$uid = isset($_GET["uid"]) ? intval( $_GET["uid"] ) : false;

require_once("include/include.inc.php");

//按地理位置添加節點，若一個地點有多條留言，則在該地點添加多條資訊，便於GInfoWindowTabs使用
function appendItem($xml, $parent, $sequence, $id, $name, $email, $content, $reply, $ip, $longitude, $latitude, $posttime, $replytime, $display) {
	global $logged_in;
	// 如果未登錄
	if (!$logged_in) {
		// 遮罩留言ID，禁止對其回復
		$id = "";
		// 遮罩留言者Email，防止濫用
		$email = "";
		// 遮罩留言者IP，防止濫用
		$ip = "";

		// 如果設定為隱藏，遮罩留言內容
		if(!$display) $content = '#hidden#';
	}

	// 判斷當前地點是否已經被添加
	$locations = $parent->getElementsByTagName("location");
	foreach ($locations as $location) {
		if (($location->getAttribute("longitude")==$longitude) && ($location->getAttribute("latitude")==$latitude)) {
			$item = $location;
			break;
		}
	}

	// 如果未被添加，則創建新的節點
	if (!($item)) {
		$item = $xml->createElement("location");
		$item = $parent->appendChild($item);

		$node_longitude = $xml->createAttribute("longitude");
		$node_longitude = $item->appendChild($node_longitude);
		$node_longitude->appendChild($xml->createTextNode($longitude));

		$node_latitude = $xml->createAttribute("latitude");
		$node_latitude = $item->appendChild($node_latitude);
		$node_latitude->appendChild($xml->createTextNode($latitude));
	}

	// 在地點的節點下創建留言節點
	$entry = $xml->createElement("entry");
	$entry = $item->appendChild($entry);

	// 添加留言節點順序的屬性，在切換當前顯示的留言的時候使用
	$node_sequence = $xml->createAttribute("sequence");
	$node_sequence = $entry->appendChild($node_sequence);
	$node_sequence->appendChild($xml->createTextNode($sequence));

	// 留言的ID，如果回復則需要使用ID對記錄進行更新
	$node_id = $xml->createAttribute("id");
	$node_id = $entry->appendChild($node_id);
	$node_id->appendChild($xml->createTextNode($id));

	// 留言者姓名
	$node_name = $xml->createAttribute("name");
	$node_name = $entry->appendChild($node_name);
	$node_name->appendChild($xml->createTextNode($name));

	// 留言者Email
	$node_email = $xml->createAttribute("email");
	$node_email = $entry->appendChild($node_email);
	$node_email->appendChild($xml->createTextNode($email));

	// 留言者IP
	$node_ip = $xml->createAttribute("ip");
	$node_ip = $entry->appendChild($node_ip);
	$node_ip->appendChild($xml->createTextNode($ip));

	// 留言發佈時間
	$node_posttime = $xml->createAttribute("posttime");
	$node_posttime = $entry->appendChild($node_posttime);
	$node_posttime->appendChild($xml->createTextNode($posttime));

	// 留言回復時間
	$node_replytime = $xml->createAttribute("replytime");
	$node_replytime = $entry->appendChild($node_replytime);
	$node_replytime->appendChild($xml->createTextNode($replytime));

	// 留言內容
	$node_content = $xml->createElement("content");
	$node_content = $entry->appendChild($node_content);
	$node_content->appendChild($xml->createCDATASection($content));

	// 留言回復內容
	$node_reply = $xml->createElement("reply");
	$node_reply = $entry->appendChild($node_reply);
	$node_reply->appendChild($xml->createCDATASection($reply));
}

// 使用DOMDocument， 需要PHP 5.0以上版本
$doc = new DOMDocument();
$doc->formatOutput = true;
$root = $doc->createElement("entries");
$root = $doc->appendChild($root);


// 實現分頁
//頁數
$page = isset($_GET["page"]) ? intval( $_GET["page"] ) : 1;
//每頁條目數
$pagesize = isset($_GET["pagesize"]) ? intval( $_GET["pagesize"] ) : 10;


if ($page*$pagesize>0) {
	//計算記錄偏移量
	$offset = $pagesize*($page - 1);
	$db = &new mysqldb($_DBNAME, $_DBHOST, $_DBUSER, $_DBPASS);
	//$gmbadmin = $db->select_single_value("users", "uname", "WHERE uid=$uid");

	// 查詢語句
	$where_str = "WHERE uid=$uid ORDER BY posttime DESC LIMIT $offset, $pagesize";
	// 將取出的資料生成陣列，方便使用
	$entries = $db->select_to_array("messages","*",$where_str);
	$db->close();

	// 若存在資料，則進行添加生成XML
	if ($entries){
		$i = 0;
		foreach ($entries as $entry) {
			appendItem($doc, $root, $i, $entry["id"], $entry["name"], $entry["email"], $entry["content"], $entry["reply"], long2ip($entry["ip"]), $entry["longitude"], $entry["latitude"], $entry["posttime"], $entry["replytime"], $entry["display"]);
			$i++;
		}
	}
}

// 添加是否登錄的屬性
$node_logged_in = $doc->createAttribute("logged_in");
$node_logged_in = $root->appendChild($node_logged_in);
$node_logged_in->appendChild($doc->createTextNode($logged_in));

// 添加使用者資訊的屬性
$node_user_info = $doc->createAttribute("user_info");
$node_user_info = $root->appendChild($node_user_info);
$node_user_info->appendChild($doc->createTextNode($_SESSION[$sid]));


// Date in the past
header("Expires: Mon, 26 Jul 1997 05:00:00 GMT");

// always modified
header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");

// HTTP/1.1
header("Cache-Control: no-store, no-cache, must-revalidate");
header("Cache-Control: post-check=0, pre-check=0", false);

// HTTP/1.0
header("Pragma: no-cache");
header("Content-type: text/xml; charset=utf-8");

// 輸出XML
echo $doc->saveXML();

?>
