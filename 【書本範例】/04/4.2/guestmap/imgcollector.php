<?php
  //屏蔽執行中的錯誤，以正確顯示圖片
  error_reporting(0);
  
  //引用config.php
  require_once 'config.php';
  //引用GeoIP API
  require_once 'geoipcity.inc';
  require_once 'geoipregionvars.php';
  
  
  //取得瀏覽器UA
  $ua = $_SERVER["HTTP_USER_AGENT"] ? $_SERVER["HTTP_USER_AGENT"]: getenv("HTTP_USER_AGENT");
  
  //取得客戶端IP
  function getClientIP()
  {
      if($HTTP_SERVER_VARS["HTTP_X_FORWARDED_FOR"])
      {
          $ip = $HTTP_SERVER_VARS["HTTP_X_FORWARDED_FOR"];
      }
      elseif($HTTP_SERVER_VARS["HTTP_CLIENT_IP"])
      {
          $ip = $HTTP_SERVER_VARS["HTTP_CLIENT_IP"];
      }
      elseif ($HTTP_SERVER_VARS["REMOTE_ADDR"])
      {
          $ip = $HTTP_SERVER_VARS["REMOTE_ADDR"];
      }
      elseif (getenv("HTTP_X_FORWARDED_FOR"))
      {
          $ip = getenv("HTTP_X_FORWARDED_FOR");
      }
      elseif (getenv("HTTP_CLIENT_IP"))
      {
          $ip = getenv("HTTP_CLIENT_IP");
    }
      elseif (getenv("REMOTE_ADDR"))
      {
          $ip = getenv("REMOTE_ADDR");
      }
      else
      {
          $ip = false;
      }
      return $ip;
  }
  $ip = getClientIP();
  
  
  //讀取Cookie的visited
  $visited = $_COOKIE["visited"];
  
  //若Cookie未設置或失效，則向數據庫添加新數據並設置Cookie的visited為true
  if (!$visited)
  {
    //利用GeoLiteCity數據庫進行查詢，注意使用GeoLiteCity.dat文件的實際路徑
    $gi = geoip_open("./GeoLiteCity.dat",GEOIP_STANDARD);
    $record = geoip_record_by_addr($gi, $ip);
    geoip_close($gi);
    
    //若順利在數據庫中取得數據
    if($record)
    {
      //拼接SQL語句
      $sql = "INSERT INTO `guestinfo` (`ip`, `lat`, `lng`, `city`, `region`, `country`, `ua`)
             VALUES ('" .ip2long($ip). "', '" .$record->latitude. "', '" .$record->longitude. "', '" .$record->city. "', '" .$GEOIP_REGION_NAME[$record->country_code][$record->region]. "', '" .$record->country_name. "', '" .$ua. "')";
      //此處添加新數據
      //連接數據庫
      mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
      
      //選擇數據庫，若失敗則報錯停止執行
      @mysql_select_db(DB_NAME) or die('alert("Failed to connect database!")');
      
      
      //若取到數據並執行SQL語句成功
      if(mysql_query($sql))
      {
        //設定Cookie值，設置1天后失效
        setcookie("visited", true, time()+3600*24);
      }
      else  //插入失敗
      {
        //設定Cookie值，失效時間為過去，即刪除該Cookie
        setcookie("visited", false, time()-3600*24);
      }
      //別忘了關閉數據庫
      mysql_close();
      
    }
  }
  //無論執行情況如何，利用GD庫生成圖片
  header("Content-type: image/png");
  $im = @imagecreate(220, 30)
    or die("Cannot Initialize new GD image stream");
  $background_color = imagecolorallocate($im, 255, 255, 255);
  $text_color = imagecolorallocate($im, 233, 14, 91);
  imagestring($im, 3, 5, 5,  "Your IP is: $ip", $text_color);
  imagepng($im);
  imagedestroy($im);
?>
