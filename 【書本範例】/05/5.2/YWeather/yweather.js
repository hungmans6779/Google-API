//全局變量GMap
var map;

//RSS命名空間
var nsGeo = "http:\/\/www.w3.org\/2003\/01\/geo\/wgs84_pos#";
var nsYWeather = "http:\/\/xml.weather.yahoo.com\/ns/rss\/1.0";

//Url模板，其中{...}這些內容會被實際的值所代替
//地標圖片的路徑模版
var iconUrlTemplate = "http:\/\/l.yimg.com\/us.yimg.com\/i\/us\/we\/31/{code}.gif";
//天氣RSS路徑的模版
var feedUrlTemplate = "http:\/\/weather.yahoo.com\/forecastrss?p={id}&u={unit}";

//GIcon模板，image屬性通過iconUrlTemplate產生
var iconTemplate = new GIcon();
iconTemplate.shadow = "shadow.gif"
iconTemplate.iconSize = new GSize(31, 31);
iconTemplate.shadowSize = new GSize(1, 1);
iconTemplate.iconAnchor = new GPoint(16, 15);
iconTemplate.infoWindowAnchor = new GPoint(16, 15);

//創建YWeather()類
function YWeather(){

};

//處理獲取到的XML，並顯示信息
YWeather.prototype.process = function(result){
  if(!result.error)
  {
    //XML文檔
    var xmldoc = result.xmlDocument;
    
    /*--------- 下面信息有些並未用到，可在需要時自行添加 ------------------*/
    //經緯度
    var latitude = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsGeo, "lat")[0].firstChild.nodeValue;
    var longitude = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsGeo, "long")[0].firstChild.nodeValue;
    
    //發布時間
    var pubDate = xmldoc.getElementsByTagName("pubDate")[0].firstChild.nodeValue;
    
    //描述
    var description = xmldoc.getElementsByTagName("description")[1].firstChild.nodeValue;
    
    //地區
    var locationInfo = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsYWeather , "location")[0];
    
    //單位
    var units = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsYWeather , "units")[0];
    
    //風
    var wind = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsYWeather , "wind")[0];
    
    //大氣
    var atmosphere = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsYWeather , "atmosphere")[0];
    
    //當前天氣
    var condition = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsYWeather , "condition")[0];
    
    //預報信息
    var forecast = google.feeds.getElementsByTagNameNS(xmldoc.documentElement, nsYWeather , "location");
    
    
    /*--------- 下面信息有些並未用到，可在需要時自行添加 ------------------*/
    var iconUrl = iconUrlTemplate.replace("{code}", condition.getAttribute("code"));
    var weatherIcon = new GIcon(iconTemplate, iconUrl);
    var hint = locationInfo.getAttribute("city") + ": " +  condition.getAttribute("text");
    var point = new GLatLng(latitude, longitude)
    var marker = new GMarker(point, {icon:weatherIcon, title:hint});
    map.addOverlay(marker);
    GEvent.addListener(marker, "click", function(){
                              marker.openInfoWindowHtml("<div style='font:14px'><strong>"+ locationInfo.getAttribute("city") +"<\/strong><\/div>"+ "<div style='font:12px'>"+ description +"<\/div>");
                         });
  }
}

//加載天氣信息
YWeather.prototype.loadWeather = function(id, unit){
  //如果id為空，直接返回，不予執行
  if(!id) return;
  
  this.id = id;
  //參數unit可省略，默認使用公制"c"
  this.unit = unit ? unit: "c";  
  
  //生成真實的RSS的URL
  var url = feedUrlTemplate.replace("{id}", this.id).replace("{unit}", this.unit);
  
  //加載RSS並設定其回調函數為this.process，即YWeather.process.
  this.feed = new google.feeds.Feed(url);
  this.feed.setResultFormat(google.feeds.Feed.XML_FORMAT);
  this.feed.load(this.process);
}

//加載天氣信息
YWeather.prototype.loadWeather = function(id, unit){
  //如果id為空，直接返回，不予執行
  if(!id) return;
  
  this.id = id;
  //參數unit可省略，默認使用公制"c"
  this.unit = unit ? unit: "c";  
  
  //生成真實的RSS的URL
  var url = feedUrlTemplate.replace("{id}", this.id).replace("{unit}", this.unit);
  
  //加載RSS並設定其回調函數為this.process，即YWeather.process.
  var feed = new google.feeds.Feed(url);
  feed.setResultFormat(google.feeds.Feed.XML_FORMAT);
  feed.load(this.process);
}

//獲取地區天氣
YWeather.prototype.getWeather = function(loc, unit){
  //代理轉發的URL地址
  var url = "proxy.php?where=" + loc;
  
  //將YWeather對象存入self變量
  var self = this;
  GDownloadUrl(url, function(doc)
    {
       //解析XML文件
       var xmlDoc = GXml.parse(doc);
       
       var locations = xmlDoc.documentElement.getElementsByTagName("loc");
       
       //判斷查詢結果是否為空
       if(locations.length>0)
       {
          //通過self變量訪問YWeather對象中的變量和方法
       	  self.id= locations[0].getAttribute("id");
       	  self.loadWeather(self.id);
       }
    });
}
