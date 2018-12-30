<?php
//導入庫文件
include("geoipcity.inc");
include("geoipregionvars.php");


//獲取客戶端IP的函數
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

//如果傳遞的查詢參數為空
if(empty($_GET['q']))
{
    $ip = getClientIP();
    if(!$ip)
    {
        echo 'alert("Cannot get your IP address!");';
        die();
    }
}

//如果傳遞的查詢參數不為空
else
{    //探測字符串是否為IP的正則表達式
    $pattern = "/^(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$/";
    
    if(preg_match($pattern, $_GET['q']))   //如果查詢的信息為IP
    {
        $ip = $_GET['q'];
    }
    else     //如果查詢的信息為域名
    {
        $ip = gethostbyname($_GET['q']);  //若域名查詢成功，則返回的字符串為IP
        if(!preg_match($pattern, $ip))  //檢測是否返回IP，若未返回IP，即域名查詢失敗，報錯
        {
            echo 'alert("Invalid Input!"); ';
            die();
        }
    }
}

//如果取消下一行將使用共享內存打開GeoLiteCity數據庫，可加快查詢。但前提是服務器支持共享內存
//$gi = geoip_open("./GeoLiteCity.dat",GEOIP_MEMORY_CACHE);

//以常規方式打開GeoLiteCity數據庫，一般情況下都可以使用
$gi = geoip_open("./GeoLiteCity.dat",GEOIP_STANDARD);

//以上是假定GeoLiteCity數據庫和PHP文件在同一個目錄，故使用"./GeoLiteCity.dat"為路徑
//如果不是，請改為實際目錄

//獲取IP的信息
$record = geoip_record_by_addr($gi, $ip);

//關閉數據庫
geoip_close($gi);

//如果獲取了相關數據
if($record)
{
    echo 'loadGeoInfo('.
                  '"'.   $_GET['q']   .'",'.  //原始查詢信息
                  '"'.   $ip   .'",'.  //被查IP
                  '"'.   $record->country_code   .'",'.  //國家代碼（兩位）
                  '"'.   $record->country_code3  .'",'.  //國家代碼（三位）
                  '"'.   $record->country_name   .'",'.  //國家名稱
                  '"'.   $GEOIP_REGION_NAME[$record->country_code][$record->region]   .'",'.  //地區名稱
                  '"'.   $record->city   .'",'.  //城市名稱
                  $record->latitude   .','.  //緯度
                  $record->longitude   .')';  //經度
}
//如果數據庫中不存在相關數據
else
{
    echo 'alert("The Information for '.$ip.' is not available now!"); ';
}

?>
