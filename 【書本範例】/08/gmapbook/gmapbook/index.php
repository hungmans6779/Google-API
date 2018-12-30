<?php
/*
+--------------------------------------------------------+
| GMapbook - A Guestbook base on Google Map API          |
| Support :  http://blog.codexpress.cn                   |
| Author  :  kukukuan (kukukuan@163.com)                 |
| Copyright (c) 2006                                     |
|--------------------------------------------------------+
*/
	$uid = isset($_GET["uid"]) ? intval( $_GET["uid"] ) : 1;
//	if(!$uid) die();
?>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="keywords" content="Google Maps API, AJAX, 留言本,地圖留言本" />
<meta name="Description" content="GMapbook是國內首個基於Google Maps API的多使用者留言本系統。該系統除了具備普通留言本的基本功能外，還可以自動定位來訪者的地理位置。除此之外，本系統對官方的Google Maps API做了全面漢化，使中文用戶使用更順暢。新功能不斷添加中！！！" />
<title>GMapbook留言本</title>
<style type="text/css">
body,html,#mapDiv {
	margin:0px;
	width: 100%;
	height: 100%;
}
input {
	color:#0099FF;
}
textarea {
	background-color:#FFFFFF;
	font:12px bold;
	overflow:auto;
	word-break:break-all;
	color:#0099FF;
	width:100%
}
.formtitle {
	font:14px bold;
	color:#0099FF;
}
.formcontent {
	color:#0099FF;
	font:12px bold;
}
.rinfo {
	font:12px small-caps;
	color:#0099FF;
	text-align:right;
}
</style>
<script src="http://j.maxmind.com/app/geoip.js" type="text/javascript"></script>
<script src="api.zh-cn.js" type="text/javascript"></script>
<script src="ui.php?uid=<?php echo $uid; ?>" type="text/javascript"></script>
<script src="gmapbook.zh-cn.js" type="text/javascript"></script>

<script type="text/javascript">
//<![CDATA[
	window.onunload = GUnload;
	window.onresize = resizeMap;
//]]>
</script>

<body style="text-align:center;overflow:hidden;" onload="init()">
<div id="mapDiv">
	<p>GMapbook載入中...</p>
	<p>如果長時間無法完成載入，請檢查你的流覽器是否支持Javascript。如果載入Google地圖失敗且流覽器報錯，請確定您可以訪問<a href="http://local.live.com">local.live.com</a>.</p>

</div>
</body>
</html>
