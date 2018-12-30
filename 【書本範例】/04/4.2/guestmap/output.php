<?php
   //數據XML的URL，直接將output.php接收到的參數傳送給data.php
   $data_url = 'data.php?' . $_SERVER["QUERY_STRING"];
   
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8"/>
<title>Google Maps JavaScript API Example</title>
<style type="text/css">
body, html, #map{
    margin:0px;
    width: 100%;
    height: 100%;
}
</style>

<!--導入Google Maps API庫文件。注意將本代碼中的API Key替換為前文申請到的API Key-->
<script src="http://maps.google.com/maps?file=api&amp;v=2&amp;key=ABQIAAAA1j86tnUDFv8OAtC8dZVtKRT2yXp_ZAY8_ufC3CFXhHIE1NvwkxSzmwrQ90SNUILzGRpsBiaa860gfQ" type="text/javascript"></script>
<script type="text/javascript">
//<![CDATA[

    //全局GMap
    var map;
    
    //自定義icon
    var myIcon= new GIcon();
    myIcon.image = "http://labs.google.com/ridefinder/images/mm_20_yellow.png";
    myIcon.shadow = "http://labs.google.com/ridefinder/images/mm_20_shadow.png";
    myIcon.iconSize = new GSize(12, 20);
    myIcon.shadowSize = new GSize(22, 20);
    myIcon.iconAnchor = new GPoint(6, 20);
    myIcon.infoWindowAnchor = new GPoint(5, 1);
    
    //地標數組
    var markers_array = new Array();
    
    //創建地標並監聽點擊事件
    function createMarker(point,html,icon)
    {
      //創建地標
      var marker = new GMarker(point, {icon:icon});
      //以下部分用於監聽點擊事件
      GEvent.addListener(marker, "click", function()
                {
                  marker.openInfoWindowHtml(html);
                }
      );
      return marker;
    }

    
    //網頁加載時用於初始化Google地圖
    function load()
    {
      if (GBrowserIsCompatible())       {
        //創建GMap2對象
        map = new GMap2(document.getElementById("map"));
        
        //縮放級別設得比較小，如不合適可自行設定合適的級別
        map.setCenter(new GLatLng(39.92, 116.46), 3);
        
        //AJAX獲取地標信息
        //此處動態生成XML文件的URL，並加載
        GDownloadUrl("<?php echo $data_url; ?>", function (doc)
            {
               //解析XML文件
               var xmlDoc = GXml.parse(doc);
               
               //獲取地標節點
               var markers = xmlDoc.documentElement.getElementsByTagName("m");
               for (var i = 0; i < markers.length; i++)
               {
               	   //獲取經緯度信息
               	   var lat =  parseFloat(markers[i].getAttribute("lat"));
               	   var lng =  parseFloat(markers[i].getAttribute("lng"));
               	   var point = new GLatLng(lat, lng);
               	   
               	   //獲取客戶端信息及地理信息
               	   var info = "訪客IP：" + markers[i].getAttribute("ip") + "<br />";
               	   info += "訪問時間：" + markers[i].getAttribute("t") + "<br />";
               	   info += "訪問者所在城市：" + markers[i].getAttribute("p") + "<br />";
               	   info += "訪問者所在省份：" + markers[i].getAttribute("r") + "<br />";
               	   info += "訪問者所在國家：" + markers[i].getAttribute("c") + "<br />";
               	   info += "瀏覽器信息：" + markers[i].getAttribute("ua") + "<br />";
               	   
               	   //創建地標
               	   var marker = createMarker(point, info, myIcon);
               	   
                   
               	   //存入地標數組
               	   markers_array.push(marker);
               }
               
               //創建GMarkerManager
               var mm = new GMarkerManager(map, {borderPadding:1});
               
               //添加地標數組
               mm.addMarkers(markers_array, 2);
               
               //顯示地標
               mm.refresh();
               
            }
        );
      }
    }
    
    //]]>
    </script>
  </head>
  <!--加載時調用load()函數加載地圖，注意加上onunload="GUnload()"防止內存泄露-->
  <body onload="load()" onunload="GUnload()">
    <!--
    以下id為map的DIV元素即為Google地圖的容器
    因為已在CSS中定義該層寬、高均為100%，故此處不必重複定義
    -->
    <div id="map"></div>
  </body>
</html>
