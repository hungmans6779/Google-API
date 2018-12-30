<?php
  
  //引用config.php
  require_once 'config.php';
  
  //引用geoipregionvars.php
  require_once 'geoipregionvars.php';
  
  //獲取傳遞過來的信息
  $country_code = $_GET["country_code"];
  $country = $_GET["country"];
  $region_code = $_GET["region_code"];
  $city = $_GET["city"];
  $lat = $_GET["lat"];
  $lng = $_GET["lng"];
  
  //取得地區名稱
  $region = $GEOIP_REGION_NAME[$country_code][$region_code];
  
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
  $ip = ip2long(getClientIP());
  
  //讀取Cookie的visited
  $visited = $_COOKIE["visited"];
  
  //若Cookie未設置或失效，則向數據庫添加新數據並設置Cookie的visited為true
  if (!$visited)
  {
    //此處添加新數據
    //連接數據庫
    mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
    
    //選擇數據庫，若失敗則報錯停止執行
    @mysql_select_db(DB_NAME) or die('alert("Failed to connect database!")');
    
    //拼接SQL語句
    $sql = "INSERT INTO `guestinfo` (`ip`, `lat`, `lng`, `city`, `region`, `country`, `ua`)
             VALUES ($ip, $lat, $lng, '$city', '$region', '$country', '$ua')";
    
    //執行SQL語句
    if(mysql_query($sql))
    {
      echo 'var recorded = true; alert($ip);';
      //設定Cookie值，設置1天后失效
      setcookie("visited", true, time()+3600*24);
    }
    else  //插入失敗
    {
      echo 'var recorded = false; alert($ip);';
      //設定Cookie值，失效時間為過去，即刪除該Cookie
      setcookie("visited", false, time()-3600*24);
    }
    //別忘了關閉數據庫
    mysql_close();
    
  }
  
  
?>