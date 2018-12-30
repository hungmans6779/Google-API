<?php

//引用config.php
require_once 'config.php';

//輸出Header，告知瀏覽器文件類型為XML，編碼為UTF-8
header("Content-type: text/xml; charset=utf-8");

echo '<?xml version="1.0" encoding="utf-8"?>';


//獲取頁數，如未定義或非法定義則使用默認頁
$page = isset($_GET["page"]) ? intval( $_GET["page"] ) : 0;

//每頁條目數，如未定義或非法定義則默認為100條數據
$pagesize = isset($_GET["pagesize"]) ? intval( $_GET["pagesize"] ) : 500;

//當數據不合法時抱錯
if($page*$pagesize<0)
{
  die('<err>Ilegal Input</err>');
}
//當數據合法時輸出數據
else
{
  //計算記錄偏移量
  $offset = $pagesize*$page;
  
  //連接數據庫 
  mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
  
  //選擇數據庫，若失敗則報錯停止執行
  mysql_select_db(DB_NAME) or die('<err>Unable to select database</err>');
  
  //拼接SQL語句
  $sql = "SELECT * FROM `guestinfo` ORDER BY `time` DESC LIMIT $offset, $pagesize";
  
  //執行SQL語句，並返回數據
  $result = mysql_query($sql);
  
  //取出的數據條數
  $num=mysql_numrows($result);
  
  //關閉數據庫
  mysql_close();
  
  //輸出XML格式的數據
  echo '<mm>';
  $i=0;
  while($i < $num)
  {
     //獲取每個字段的信息
  	 $ip=trim (long2ip(mysql_result($result,$i,"ip")));
  	 $time=trim (mysql_result($result,$i,"time"));
  	 $lat=trim (mysql_result($result,$i,"lat"));
  	 $lng=trim (mysql_result($result,$i,"lng"));
  	 $city=trim (mysql_result($result,$i,"city"));
  	 $region=trim (mysql_result($result,$i,"region"));
  	 $country=trim (mysql_result($result,$i,"country"));
  	 //$ua=trim (mysql_result($result,$i,"ua"));
  	 
  	 //輸出每個節點的內容
     echo '<m ip="' . $ip . '" t="' . $time . '" lat="' . $lat . '"'
     	 . ' lng="' . $lng . '" p="' . $city . '" r="' . $region . '"'
         . ' c="' . $country . '" />';
     
     $i++;
  }
  echo '</mm>';

}

?>
