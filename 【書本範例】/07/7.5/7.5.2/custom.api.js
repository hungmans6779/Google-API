var G_INCOMPAT = false;
function GScript(src) {
    document.write('<' + 'script src="' + src + '"' +' type="text/javascript"><' + '/script>');
}

// 檢測瀏覽器兼容性
function GBrowserIsCompatible(setBodyClass)
{
    if (G_INCOMPAT)
        return false;
    if (!window.RegExp)
        return false;
    var AGENTS = ["opera","msie","safari","firefox","netscape","mozilla"];
    var agent = navigator.userAgent.toLowerCase();
    for (var i = 0; i < AGENTS.length; i++)
    {
        var agentStr = AGENTS[i];
        if (agent.indexOf(agentStr) != -1)
        {
            if (setBodyClass && document.body)
            {
                document.body.className = agentStr;
            }
            var versionExpr = new RegExp(agentStr + "[ \/]?([0-9]+(\.[0-9]+)?)");
            var version = 0;
            if (versionExpr.exec(agent) != null) 
            {
                version = parseFloat(RegExp.$1);
            }
            if (agentStr == "opera")
                return version >= 7;
            if (agentStr == "safari")
                return version >= 125;
            if (agentStr == "msie")
                return (version >= 5.5 &&agent.indexOf("powerpc") == -1);
            if (agentStr == "netscape")
                return version > 7;
            if (agentStr == "firefox")
                return version >= 0.8;
        }
    }
    
    return !!document.getElementById;
}

function GVerify() {}

function GLoad()
{
    GAddMessages({1415: '.',1416: ',',10037: '出發地址',10038: '到達地址',10093: '使用條款',
                  10095: '要查看屏幕上的所有細節，請使用地圖旁邊的\"打印\"鏈接。',10096: '',10049: '地圖',10111: '地圖',
                  10120: '很抱歉，在這一縮放級別的地圖上未找到此區域。\x3cp\x3e請縮小地圖，擴大視野範圍。\x3c/p\x3e',
                  10050: '衛星',10112: '星期六',
                  10121: '很抱歉，在這一縮放級別的成像上未找到此區域。\x3cp\x3e請縮小成像，擴大視野範圍。\x3c/p\x3e',
                  10116: '混合地圖',10117: '混合地圖',10021: '放大',10022: '縮小',10023: '單擊設置縮放水平',
                  10024: '拖動縮放',10507: '向左平移',10508: '向右平移',10509: '向上平移',10510: '向下平移',
                  10029: '返回上一結果',10511: '顯示街道地圖',10512: '顯示衛星圖片',10513: '顯示標有街道名稱的圖片',
                  10806: '點擊可在 Google 地圖上參看該區域',1616: '公里',1547: '英里',10109: '米',10110: '英尺',
                  11259: '全屏顯示',10130: '地址',10131: '詳細資料',10908: '無標題',10940: '創建地圖時出錯',
                  10941: '已保存到 %1$s',10942: '保存定位標記時出錯',10943: '正在保存...',10945: '添加定位標記',
                  10946: '畫線',10947: '畫圖形',11371: '保存自 \x3ca href\x3d\"%1$s\"\x3e%2$s\x3c/a\x3e',10985: '放大',
                  10986: '縮小',11047: '在此居中放置地圖',10983: '清除搜索結果',10935: '保存到“我的地圖”',
                  11271: '以此處為出發點的路線',11272: '到達此目的地的路線',0: ''
                  });
    GAddMessages({10807: '交通流量',10808: '顯示交通流量',10809: '隱藏交通流量',
                  11089: '\x3ca href\x3d\"javascript:void(0);\"\x3e放大\x3c/a\x3e可查看該地區的交通流量',10293: '添加',
                  10294: '保存',10295: '取消',10296: '刪除',10296: '刪除',10297: '新地址：',10298: '啟用地址自動保存功能',
                  10299: '選擇：',10299: '選擇：',10300: '全部',10300: '全部',10301: '無',10301: '無',10302: '編輯',
                  10303: '默認',10304: '標籤',10304: '標籤',10304: '標籤',10305: '地址',10305: '地址',10305: '地址',
                  10307: '無已保存地址。',10308: '將該地址作為初始地圖視圖',10309: '請勿將該地址作為初始地圖視圖',10018: '正在加載...',
                  160: '\x3cH1\x3e服務器錯誤\x3c/H1\x3e服務器暫時出現錯誤，可能無法處理您的申請。\x3cp\x3e請幾分鐘後重試。\x3c/p\x3e',
                  1935: '查看大圖',11250: '\x3ca href\x3d\"%1$s\"\x3e登錄\x3c/a\x3e以查看我現有的書籤'
                  });
                  
    /*
    // 校驗部分， 取消
    if (!GValidateKey(""))
    {
        G_INCOMPAT = true;
        alert("此網站使用的 Google Maps API 密鑰已為另一網站註冊。您可以在 http://www.google.com/apis/maps/ 上為該網站生成一個新密鑰。");
        return;
    }
    */
    GLoadApi(
        [
            // 這裡加載谷歌的中文地圖API的數據
            "http://mapgoogle.mapabc.com/googlechina/maptile?v=w2.60&"
        ],
        
        [
            "http://kh0.google.com/kh?n=404&v=20&",
            "http://kh1.google.com/kh?n=404&v=20&",
            "http://kh2.google.com/kh?n=404&v=20&",
            "http://kh3.google.com/kh?n=404&v=20&"
        ],
        
        [
            "http://mt0.google.com/mt?n=404&v=apt.60&",
            "http://mt1.google.com/mt?n=404&v=apt.60&",
            "http://mt2.google.com/mt?n=404&v=apt.60&",
            "http://mt3.google.com/mt?n=404&v=apt.60&"
        ],
        
        "","","",false,"G");
    if (window.GJsLoaderInit)
    {
        GJsLoaderInit("http://www.google.com/intl/zh-CN_cn/mapfiles/86/maps2" +".api/main.js");
    }
}

// 這就是用於防止內存泄露的GUnload()函數
function GUnload()
{
    if (window.GUnloadApi)
    {
        GUnloadApi();
    }
}

var _mF = [ 400,200,false,false,false,false,100,4096,
            "bounds_030.txt","cities_030.txt","local/add/flagStreetView",
            true,true,2000,false,false,false,false,false,true,false,false 
          ];

var _mHost = "http://ditu.google.cn";
var _mUri = "/maps";
var _mDomain = "google.cn";
var _mStaticPath = "http://www.google.com/intl/zh-CN_cn/mapfiles/";
var _mJavascriptVersion = "";
var _mTermsUrl = "http://www.google.com/intl/zh-CN_cn/help/terms_maps.html";
var _mHL = "zh-CN";
var _mGL = "CN";
var _mTrafficEnableApi = true;
var _mTrafficTileServerUrlBase = "http://www.google.com/mapstt";
var _mWizActions = {hyphenSep: 1,breakSep: 2,dir: 3,searchNear: 6,savePlace: 9};
var _mSatelliteToken = "fzwq1DuMuNm1bqqC_XJbuDFigBt8i9PRHvRGvw";
var _mMapCopy = "地圖資料 \x26#169;2007";
var _mSatelliteCopy = "Imagery \x26#169;2007";
var _mGoogleCopy = "\x26#169;2007 Google";
var _mPreferMetric = true;
var _mPanelWidth = 20;
var _mMapPrintUrl = 'http://www.google.com/mapprint';
var _mAutocompleteFrom = '從';
var _mAutocompleteTo = '至';
var _mAutocompleteNearRe = '^(?:(?:.*?)\\s+)(?:(?:in|near|around|close to):?\\s+)(.+)$';
var _mSvgEnabled = true;
var _mSvgForced = false;
var _mLogInfoWinExp = true;
var _mLogPanZoomClks = false;
var _mLogWizard = true;
var _mLogLimitExceeded = true;
var _mLogPrefs = true;
var _mMMLogMyMapViewpoints = true;
var _mDirectionsDragging = false;
var _mDirectionsEnableApi = true;

// 要加AdSense了？！
var _mAdSenseForMapsEnable = "true";
var _mAdSenseForMapsFeedUrl = "http://pagead2.googlesyndication.com/afmaps/ads";

function GLoadMapsScript()
{
    if (GBrowserIsCompatible())
    {
        GScript("http://www.google.com/intl/zh-CN_cn/mapfiles/86/maps2" +".api/main.js");
    }
}

GLoadMapsScript();